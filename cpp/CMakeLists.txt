cmake_minimum_required(VERSION 3.14)
project(Mini3LeaderConsensus)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    /opt/homebrew/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link directories
link_directories(
    /opt/homebrew/lib
)

# Node server executable
add_executable(node_server
    node.cpp
    node_server.cpp
    utils.cpp
    leader.pb.cc
    leader.grpc.pb.cc
)

# Test client executable
add_executable(test_client
    test_client.cpp
    leader.pb.cc
    leader.grpc.pb.cc
)

# Common libraries
set(COMMON_LIBS
    protobuf
    grpc++
    grpc
    gpr
    absl_strings
    absl_synchronization
    absl_time
    absl_symbolize
    absl_stacktrace
    absl_status
    absl_statusor
    absl_hash
    absl_raw_logging_internal
    absl_log_severity
    absl_log_internal_message
    absl_log_internal_globals
    absl_log_internal_check_op
    absl_log_internal_nullguard
    absl_cord
    absl_cord_internal
    absl_cordz_info
    absl_cordz_functions
    pthread
)

# Link libraries
target_link_libraries(node_server ${COMMON_LIBS})
target_link_libraries(test_client ${COMMON_LIBS})
