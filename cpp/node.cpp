#include "node_server.h"
#include <iostream>
#include <fstream>
#include <vector>

// Load peer addresses from a config file (one per line)
std::vector<std::string> load_peers(const std::string& filename) {
    std::vector<std::string> peers;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            peers.push_back(line);
        }
    }
    return peers;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: ./server <node_id> <peers_file>\n";
        return 1;
    }

    std::string node_id = argv[1];          
    std::string peers_file = argv[2];       

    // Load peers
    std::vector<std::string> peers = load_peers(peers_file);
    if (peers.empty()) {
        std::cerr << "No peers found in file.\n";
        return 1;
    }

    // Start the gRPC server and heartbeat loop
    NodeServiceImpl server(node_id);
    server.StartHeartbeatLoop(peers);
    server.Run(node_id);

    return 0;
}
