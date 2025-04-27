#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

// Simulate scoring based on system load
float compute_score(int queue_length) {
    // Random CPU and memory (in real world, use sys info APIs)
    float cpu_free = 70.0f + static_cast<float>(rand() % 30); // 70-100%
    float mem_free = 60.0f + static_cast<float>(rand() % 40); // 60-100%

    return 0.5f * cpu_free + 0.3f * mem_free - 0.2f * static_cast<float>(queue_length);
}

void simulate_task(int task_id, int duration_ms) {
    std::cout << "[TASK] Running task ID: " << task_id << " for " << duration_ms << "ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}
