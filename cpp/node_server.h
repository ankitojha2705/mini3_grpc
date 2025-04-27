#ifndef NODE_SERVER_H
#define NODE_SERVER_H

#include "leader.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <mutex>
#include <queue>
#include <string>
#include <thread>

class NodeServiceImpl final : public leader::NodeService::Service {
public:
    NodeServiceImpl(const std::string& node_id);

    grpc::Status Heartbeat(grpc::ServerContext* context,
                           const leader::NodeStatus* request,
                           leader::Ack* reply) override;

    grpc::Status AssignTask(grpc::ServerContext* context,
                            const leader::Task* request,
                            leader::Ack* reply) override;

    void Run(const std::string& server_address);
    void StartHeartbeatLoop(const std::vector<std::string>& peer_addresses);

private:
    std::string node_id_;
    std::queue<leader::Task> task_queue_;
    std::mutex queue_mutex_;
    float current_score_;

    void ProcessTasks();
    void SendHeartbeatToPeer(const std::string& peer_address);
};

#endif // NODE_SERVER_H
