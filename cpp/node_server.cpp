#include "node_server.h"
#include "utils.h"
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <iostream>

NodeServiceImpl::NodeServiceImpl(const std::string& node_id)
    : node_id_(node_id), current_score_(0.0f) {}

grpc::Status NodeServiceImpl::Heartbeat(grpc::ServerContext*,
                                        const leader::NodeStatus* request,
                                        leader::Ack* reply) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        peer_scores_[request->node_id()] = request->score();  // Save peer's score
    }

    std::cout << "[HEARTBEAT] Received from " << request->node_id()
              << " Score: " << request->score() << "\n";

    reply->set_message("ACK");
    return grpc::Status::OK;
}

grpc::Status NodeServiceImpl::AssignTask(grpc::ServerContext*,
                                         const leader::Task* request,
                                         leader::Ack* reply) {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    task_queue_.push(*request);
    std::cout << "[TASK RECEIVED] Task ID: " << request->task_id() << "\n";
    reply->set_message("Task received.");
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
            simulate_task(task.task_id(), task.duration_ms());
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
        current_score_ = compute_score(task_queue_.size());
        status.set_node_id(node_id_);
        status.set_score(current_score_);
        status.set_queue_length(task_queue_.size());
    }

    leader::Ack ack;
    grpc::ClientContext context;
    grpc::Status s = stub->Heartbeat(&context, status, &ack);

    if (!s.ok()) {
        std::cerr << "[ERROR] Heartbeat to " << peer_address << " failed.\n";
    }
}

void NodeServiceImpl::StartHeartbeatLoop(const std::vector<std::string>& peers) {
    peer_addresses_ = peers;  // save peers for election use

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
}

void NodeServiceImpl::ElectionLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5)); // run election every 5s

        std::lock_guard<std::mutex> lock(queue_mutex_);

        std::string best_node = node_id_;
        float best_score = current_score_;

        for (const auto& [peer_id, score] : peer_scores_) {
            if (score > best_score) {
                best_node = peer_id;
                best_score = score;
            }
        }

        if (leader_id_ != best_node) {
            leader_id_ = best_node;
            if (leader_id_ == node_id_) {
                std::cout << "[LEADER] I am elected as the new leader!\n";
            } else {
                std::cout << "[INFO] New leader elected: " << leader_id_ << "\n";
            }
        }
    }
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
