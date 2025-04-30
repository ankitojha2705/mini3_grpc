#ifndef NODE_SERVER_H
#define NODE_SERVER_H

#include "leader.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <atomic>
#include <map>

class NodeServiceImpl final : public leader::NodeService::Service {
public:
    explicit NodeServiceImpl(const std::string& node_id);

    grpc::Status Heartbeat(grpc::ServerContext* context,
                           const leader::NodeStatus* request,
                           leader::Ack* reply) override;

    grpc::Status AssignTask(grpc::ServerContext* context,
                            const leader::Task* request,
                            leader::Ack* reply) override;

    grpc::Status RequestWork(grpc::ServerContext* context,
                            const leader::WorkRequest* request,
                            leader::WorkResponse* reply) override;

    grpc::Status TransferWork(grpc::ServerContext* context,
                             const leader::Task* request,
                             leader::Ack* reply) override;

    void Run(const std::string& server_address);
    void StartHeartbeatLoop(const std::vector<std::string>& peers);

private:
    void ProcessTask(const leader::Task& task);
    bool TryWorkStealing();
    
    const std::string node_id_;
    std::queue<leader::Task> task_queue_;
    std::mutex queue_mutex_;
    std::map<std::string, leader::NodeStatus> peer_statuses_;
    std::vector<std::string> peer_addresses_;
    float current_score_;
    float cpu_utilization_;
    float memory_utilization_;
    bool is_leader_;
    std::string leader_id_;
    const int max_queue_size_ = 10;
    const int MIN_QUEUE_LENGTH = 2;
    const int MAX_TASKS_TO_STEAL = 3;
    const int MAX_STEAL_COUNT = 3;

    void ProcessTasks();
    void SendHeartbeatToPeer(const std::string& peer_address);
    void ElectionLoop();
    void WorkStealingLoop();
    void UpdateSystemMetrics();
    bool ShouldStealWork(const leader::NodeStatus& peer_status);
    std::vector<leader::Task> GetTasksToSteal(int count);
    float ComputeScore() const;
};

#endif // NODE_SERVER_H
