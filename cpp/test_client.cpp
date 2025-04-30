#include "leader.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class TestClient {
public:
    TestClient(const std::string& server_address) 
        : stub_(leader::NodeService::NewStub(
            grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()))) {}

    bool SendTask(int task_id, int duration_ms) {
        std::cout << "\n=== Sending Task ===" << std::endl;
        std::cout << "Task ID: " << task_id << std::endl;
        std::cout << "Duration: " << duration_ms << "ms" << std::endl;
        
        leader::Task task;
        task.set_task_id(task_id);
        task.set_duration_ms(duration_ms);
        task.set_source_node("client");
        task.set_steal_count(0);

        leader::Ack reply;
        ClientContext context;
        Status status = stub_->AssignTask(&context, task, &reply);

        if (status.ok()) {
            std::cout << "Task " << task_id << " sent successfully" << std::endl;
            std::cout << "Server response: " << reply.message() << std::endl;
            return true;
        } else {
            std::cout << "Failed to send task " << task_id << std::endl;
            std::cout << "Error: " << status.error_message() << std::endl;
            return false;
        }
    }

    // Get node status
    bool GetNodeStatus() {
        leader::NodeStatus status;
        status.set_node_id("client");
        
        leader::Ack reply;
        ClientContext context;
        Status rpc_status = stub_->Heartbeat(&context, status, &reply);

        if (rpc_status.ok()) {
            std::cout << "Node status: " << reply.message() << "\n";
            return true;
        } else {
            std::cout << "Failed to get node status: " << rpc_status.error_message() << "\n";
            return false;
        }
    }

private:
    std::unique_ptr<leader::NodeService::Stub> stub_;
};

void runBurstTest(TestClient& client, int num_tasks, int burst_interval_ms) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> task_duration(100, 1000);

    std::cout << "\n=== Starting Burst Test ===" << std::endl;
    std::cout << "Number of tasks: " << num_tasks << std::endl;
    std::cout << "Burst interval: " << burst_interval_ms << "ms" << std::endl;
    std::cout << "Task duration range: 100-1000ms" << std::endl;

    for (int i = 0; i < num_tasks; i++) {
        int duration = task_duration(gen);
        std::cout << "\nSending task " << i << " with duration " << duration << "ms" << std::endl;
        client.SendTask(i, duration);
        std::this_thread::sleep_for(std::chrono::milliseconds(burst_interval_ms));
    }
    
    std::cout << "\n=== Burst Test Complete ===\n" << std::endl;
}

void runGradualLoadTest(TestClient& client, int num_tasks, int interval_ms) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> task_duration(100, 1000);

    std::cout << "\n=== Starting Gradual Load Test ===" << std::endl;
    std::cout << "Number of tasks: " << num_tasks << std::endl;
    std::cout << "Interval between tasks: " << interval_ms << "ms" << std::endl;
    std::cout << "Task duration range: 100-1000ms" << std::endl;

    for (int i = 0; i < num_tasks; i++) {
        int duration = task_duration(gen);
        std::cout << "\nSending task " << (i + 1000) << " with duration " << duration << "ms" << std::endl;
        client.SendTask(i + 1000, duration);
        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }
    
    std::cout << "\n=== Gradual Load Test Complete ===\n" << std::endl;
}

void runLongTaskTest(TestClient& client, int num_tasks) {
    std::cout << "\n=== Starting Long Task Test ===" << std::endl;
    std::cout << "Number of tasks: " << num_tasks << std::endl;
    std::cout << "Task duration: 5000ms (5 seconds)" << std::endl;

    for (int i = 0; i < num_tasks; i++) {
        std::cout << "\nSending long task " << (i + 2000) << std::endl;
        client.SendTask(i + 2000, 5000);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    std::cout << "\n=== Long Task Test Complete ===\n" << std::endl;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <server_address>\n";
        std::cerr << "Example: " << argv[0] << " localhost:5001\n";
        return 1;
    }

    TestClient client(argv[1]);
    
    std::cout << "Test Client Started\n";
    std::cout << "Connected to: " << argv[1] << "\n";
    std::cout << "Available tests:\n";
    std::cout << "1. Burst Test (20 tasks, fast)\n";
    std::cout << "2. Gradual Load Test (10 tasks, slow)\n";
    std::cout << "3. Long Task Test (5 tasks, 5s each)\n";
    std::cout << "4. Run All Tests\n";
    std::cout << "Enter test number (1-4): ";

    int choice;
    std::cin >> choice;

    switch(choice) {
        case 1:
            runBurstTest(client, 20, 50);
            break;
        case 2:
            runGradualLoadTest(client, 10, 500);
            break;
        case 3:
            runLongTaskTest(client, 5);
            break;
        case 4:
            runBurstTest(client, 20, 50);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            runGradualLoadTest(client, 10, 500);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            runLongTaskTest(client, 5);
            break;
        default:
            std::cout << "Invalid choice\n";
            return 1;
    }

    std::cout << "\nTests completed. Press Enter to exit.\n";
    std::cin.ignore();
    std::cin.get();
    return 0;
} 