#!/bin/bash

# Kill any existing node_server processes
pkill -f node_server

# Start 5 node servers on different ports
for i in {1..5}; do
    port=$((5000 + i))
    address="localhost:$port"
    ./build/node_server "$address" "peers.txt" &
    echo "Started node$i at $address"
    sleep 1
done

# Wait for all background processes
wait 