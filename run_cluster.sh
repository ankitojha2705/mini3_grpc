#!/bin/bash

# Kill any existing processes
pkill -f node_server

# Create build directory if it doesn't exist
mkdir -p cpp/build
cd cpp/build

# Build the project
cmake ..
make

# Start 5 nodes on different ports
for i in {1..5}; do
    port=$((5000 + i))
    ./node_server "localhost:$port" "../peers.txt" &
    echo "Started node$i on port $port"
done

# Wait for all background processes
wait
