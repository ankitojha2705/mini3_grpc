#include "node_server.h"
#include "utils.h"
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <iostream>
#include <algorithm>
#include <chrono>

NodeServiceImpl::NodeServiceImpl(const std::string& node_id)
    : node_id_(node_id), current_score_(0.0f) {
    std::thread([this]() {
        while (true) {
            UpdateSystemMetrics();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }).detach();
}

grpc::Status NodeServiceImpl::Heartbeat(grpc::ServerContext*,
                                        const leader::NodeStatus* request,
                                        leader::Ack* reply) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        peer_statuses_[request->node_id()] = *request;
    }

    reply->set_message("ACK");
    reply->set_success(true);
    return grpc::Status::OK;
}

grpc::Status NodeServiceImpl::AssignTask(grpc::ServerContext*,
                                         const leader::Task* request,
                                         leader::Ack* reply) {
    // GPT-Generated: Burst test logic
    std::cout << "\n=== Task Assignment Request ===" << std::endl;
    std::cout << "Task ID: " << request->task_id() << std::endl;
    std::cout << "Duration: " << request->duration_ms() << "ms" << std::endl;
    std::cout << "Source Node: " << request->source_node() << std::endl;
    std::cout << "Current Queue Size: " << task_queue_.size() << std::endl;
    
    if (task_queue_.size() >= max_queue_size_) {
        std::cout << "Queue full, attempting work stealing..." << std::endl;
        if (TryWorkStealing()) {
            std::cout << "Work stealing successful" << std::endl;
        } else {
            std::cout << "Work stealing failed" << std::endl;
        }
    }

    if (task_queue_.size() < max_queue_size_) {
        task_queue_.push(*request);
        std::cout << "Task " << request->task_id() << " added to queue" << std::endl;
        std::cout << "New Queue Size: " << task_queue_.size() << std::endl;
        reply->set_message("Task assigned successfully");
        return grpc::Status::OK;
    }

    std::cout << "Queue still full after work stealing attempt" << std::endl;
    reply->set_message("Queue full, task rejected");
    return grpc::Status(grpc::RESOURCE_EXHAUSTED, "Queue full");
}

grpc::Status NodeServiceImpl::RequestWork(grpc::ServerContext*,
                                          const leader::WorkRequest* request,
                                          leader::WorkResponse* reply) {
    std::cout << "\n=== Work Stealing Request Received ===" << std::endl;
    std::cout << "Requester: " << request->requester_id() << std::endl;
    std::cout << "Current Queue Size: " << task_queue_.size() << std::endl;
    
    std::lock_guard<std::mutex> lock(queue_mutex_);
    
    if (task_queue_.size() <= MIN_QUEUE_LENGTH) {
        std::cout << "Not enough tasks to share (minimum " << MIN_QUEUE_LENGTH << " required)" << std::endl;
        reply->set_success(false);
        return grpc::Status::OK;
    }

    int tasks_to_share = std::min(
        static_cast<int>((task_queue_.size() - MIN_QUEUE_LENGTH) / 2),  // Share half of excess tasks
        request->max_tasks()
    );

    std::cout << "Sharing " << tasks_to_share << " tasks" << std::endl;
    
    for (int i = 0; i < tasks_to_share; ++i) {
        if (task_queue_.empty()) break;
        
        leader::Task* task = reply->add_tasks();
        *task = task_queue_.front();
        task->set_steal_count(task->steal_count() + 1);
        task_queue_.pop();
        
        std::cout << "Shared Task ID: " << task->task_id() 
                 << " (stolen " << task->steal_count() << " times)" << std::endl;
    }
    
    std::cout << "New Queue Size: " << task_queue_.size() << std::endl;
    reply->set_success(true);
    return grpc::Status::OK;
}

grpc::Status NodeServiceImpl::TransferWork(grpc::ServerContext*,
                                           const leader::Task* request,
                                           leader::Ack* reply) {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    task_queue_.push(*request);
    reply->set_message("Work transferred");
    reply->set_success(true);
    return grpc::Status::OK;
}

void NodeServiceImpl::ProcessTasks() {
    while (true) {
        if (!task_queue_.empty()) {
            leader::Task task;
            {
                std::lock_guard<std::mutex> lock(queue_mutex_);
                task = task_queue_.front();
                task_queue_.pop();
            }
            ProcessTask(task);
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}

void NodeServiceImpl::SendHeartbeatToPeer(const std::string& peer_address) {
    auto channel = grpc::CreateChannel(peer_address, grpc::InsecureChannelCredentials());
    std::unique_ptr<leader::NodeService::Stub> stub = leader::NodeService::NewStub(channel);

    leader::NodeStatus status;
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        status.set_node_id(node_id_);
        status.set_score(ComputeScore());
        status.set_queue_length(task_queue_.size());
        status.set_cpu_utilization(cpu_utilization_);
        status.set_memory_utilization(memory_utilization_);
        status.set_last_heartbeat_time(
            std::chrono::system_clock::now().time_since_epoch().count()
        );
        status.set_is_leader(is_leader_);
    }

    leader::Ack ack;
    grpc::ClientContext context;
    grpc::Status s = stub->Heartbeat(&context, status, &ack);

    if (!s.ok()) {
        std::cerr << "[ERROR] Heartbeat to " << peer_address << " failed.\n";
    }
}

void NodeServiceImpl::StartHeartbeatLoop(const std::vector<std::string>& peers) {
    peer_addresses_ = peers;

    std::thread([this]() {
        while (true) {
            for (const auto& peer : peer_addresses_) {
                if (peer != node_id_) {
                    SendHeartbeatToPeer(peer);
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }).detach();

    std::thread([this]() {
        ElectionLoop();
    }).detach();

    std::thread([this]() {
        WorkStealingLoop();
    }).detach();
}

void NodeServiceImpl::ElectionLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::lock_guard<std::mutex> lock(queue_mutex_);
        float best_score = ComputeScore();
        std::string best_node = node_id_;

        for (const auto& [peer_id, status] : peer_statuses_) {
            if (status.score() > best_score) {
                best_score = status.score();
                best_node = peer_id;
            }
        }

        is_leader_ = (best_node == node_id_);
        if (leader_id_ != best_node) {
            leader_id_ = best_node;
            std::cout << "[LEADER] New leader elected: " << leader_id_ << "\n";
        }
    }
}

void NodeServiceImpl::WorkStealingLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::lock_guard<std::mutex> lock(queue_mutex_);
        if (task_queue_.size() > MIN_QUEUE_LENGTH) {
            continue;
        }

        for (const auto& [peer_id, status] : peer_statuses_) {
            if (ShouldStealWork(status)) {
                auto channel = grpc::CreateChannel(peer_id, grpc::InsecureChannelCredentials());
                std::unique_ptr<leader::NodeService::Stub> stub = leader::NodeService::NewStub(channel);

                leader::WorkRequest request;
                request.set_requester_id(node_id_);
                request.set_max_tasks(MAX_TASKS_TO_STEAL);
                request.set_max_steal_count(MAX_STEAL_COUNT);

                leader::WorkResponse response;
                grpc::ClientContext context;
                grpc::Status s = stub->RequestWork(&context, request, &response);

                if (s.ok() && response.success()) {
                    for (const auto& task : response.tasks()) {
                        task_queue_.push(task);
                    }
                }
            }
        }
    }
}

void NodeServiceImpl::UpdateSystemMetrics() {
    // In a real implementation, this would use system APIs
    cpu_utilization_ = 30.0f + static_cast<float>(rand() % 70); // 30-100%
    memory_utilization_ = 40.0f + static_cast<float>(rand() % 60); // 40-100%
}

bool NodeServiceImpl::ShouldStealWork(const leader::NodeStatus& peer_status) {
    // Only steal if the peer has more than minimum tasks and we have capacity
    if (peer_status.queue_length() <= MIN_QUEUE_LENGTH || task_queue_.size() >= max_queue_size_) {
        return false;
    }

    // Calculate load imbalance
    int queue_diff = peer_status.queue_length() - task_queue_.size();
    if (queue_diff <= 1) {  // Don't steal for minor imbalances
        return false;
    }

    // Check if peer is not too busy
    if (peer_status.cpu_utilization() >= 80.0f) {
        return false;
    }

    // Consider steal count to prevent excessive stealing
    float avg_steal_count = 0.0f;
    int total_tasks = 0;
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        std::queue<leader::Task> temp = task_queue_;
        while (!temp.empty()) {
            avg_steal_count += temp.front().steal_count();
            total_tasks++;
            temp.pop();
        }
    }
    if (total_tasks > 0) {
        avg_steal_count /= total_tasks;
        if (avg_steal_count >= MAX_STEAL_COUNT) {
            return false;
        }
    }

    return true;
}

std::vector<leader::Task> NodeServiceImpl::GetTasksToSteal(int count) {
    std::vector<leader::Task> tasks;
    while (count-- > 0 && !task_queue_.empty()) {
        tasks.push_back(task_queue_.front());
        task_queue_.pop();
    }
    return tasks;
}

float NodeServiceImpl::ComputeScore() const {
    // Weighted scoring based on multiple factors
    float queue_weight = 0.3f;
    float cpu_weight = 0.4f;
    float memory_weight = 0.3f;

    return (1.0f - queue_weight * (task_queue_.size() / 100.0f)) +
           cpu_weight * (1.0f - cpu_utilization_ / 100.0f) +
           memory_weight * (1.0f - memory_utilization_ / 100.0f);
}

void NodeServiceImpl::Run(const std::string& server_address) {
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(this);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "[STARTED] Node running at " << server_address << "\n";

    std::thread task_thread(&NodeServiceImpl::ProcessTasks, this);
    server->Wait();
    task_thread.join();
}
// GPT-Generated: Burst test logic
void NodeServiceImpl::ProcessTask(const leader::Task& task) {
    std::cout << "\n=== Processing Task ===" << std::endl;
    std::cout << "Task ID: " << task.task_id() << std::endl;
    std::cout << "Duration: " << task.duration_ms() << "ms" << std::endl;
    std::cout << "Source Node: " << task.source_node() << std::endl;
    std::cout << "Steal Count: " << task.steal_count() << std::endl;
    std::cout << "Current Queue Size: " << task_queue_.size() << std::endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(task.duration_ms()));
    
    std::cout << "Task " << task.task_id() << " completed" << std::endl;
    std::cout << "Total processing time: " << task.duration_ms() << "ms" << std::endl;
    std::cout << "Final steal count: " << task.steal_count() << std::endl;
    std::cout << "=== Task Complete ===\n" << std::endl;
}

bool NodeServiceImpl::TryWorkStealing() {
    std::cout << "\n=== Work Stealing Attempt ===" << std::endl;
    std::cout << "Current Queue Size: " << task_queue_.size() << std::endl;
    
    // Get peer statuses to find the best node to steal from
    std::vector<std::pair<std::string, int>> peer_queues;
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        for (const auto& [peer_id, status] : peer_statuses_) {
            if (peer_id != node_id_ && status.queue_length() > MIN_QUEUE_LENGTH) {
                peer_queues.push_back({peer_id, status.queue_length()});
            }
        }
    }
    
    // Sort peers by queue length in descending order
    std::sort(peer_queues.begin(), peer_queues.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });
    
    for (const auto& [peer_id, queue_length] : peer_queues) {
        std::cout << "Attempting to steal work from " << peer_id 
                 << " (queue size: " << queue_length << ")" << std::endl;
        
        auto channel = grpc::CreateChannel(peer_id, grpc::InsecureChannelCredentials());
        auto stub = leader::NodeService::NewStub(channel);
        
        leader::WorkRequest request;
        request.set_requester_id(node_id_);
        request.set_max_tasks(MAX_TASKS_TO_STEAL);
        
        leader::WorkResponse response;
        grpc::ClientContext context;
        
        grpc::Status status = stub->RequestWork(&context, request, &response);
        
        if (status.ok() && response.success()) {
            std::cout << "Successfully stole " << response.tasks_size() << " tasks" << std::endl;
            {
                std::lock_guard<std::mutex> lock(queue_mutex_);
                for (const auto& task : response.tasks()) {
                    std::cout << "Stolen Task ID: " << task.task_id() 
                             << " (steal count: " << task.steal_count() << ")" << std::endl;
                    task_queue_.push(task);
                }
                std::cout << "New Queue Size: " << task_queue_.size() << std::endl;
            }
            return true;
        } else {
            std::cout << "Failed to steal work from " << peer_id << std::endl;
            if (!status.ok()) {
                std::cout << "Error: " << status.error_message() << std::endl;
            }
        }
    }
    
    std::cout << "No work stealing opportunities found" << std::endl;
    return false;
}
