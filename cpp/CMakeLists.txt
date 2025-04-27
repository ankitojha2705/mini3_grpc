cmake_minimum_required(VERSION 3.14)
project(Mini3LeaderConsensus)

set(CMAKE_CXX_STANDARD 17)

# Directories
set(Protobuf_INCLUDE_DIR "/usr/local/protobuf-21/include")
set(Protobuf_LIB_DIR "/usr/local/protobuf-21/lib")
set(GRPC_INCLUDE_DIR "/opt/homebrew/include")
set(GRPC_LIB_DIR "/opt/homebrew/lib")
set(ABSL_INCLUDE_DIR "/opt/homebrew/include")
set(ABSL_LIB_DIR "/opt/homebrew/lib")

# Include directories
include_directories(
  ${Protobuf_INCLUDE_DIR}
  ${GRPC_INCLUDE_DIR}
  ${ABSL_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link directories
link_directories(
  ${Protobuf_LIB_DIR}
  ${GRPC_LIB_DIR}
  ${ABSL_LIB_DIR}
)

# Proto Files
set(PROTO_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/leader.proto
)

# Executable
add_executable(server
    node.cpp
    node_server.cpp
    utils.cpp
    leader.pb.cc
    leader.grpc.pb.cc
)

# Correct linking with absl libraries
target_link_libraries(server
    /usr/local/protobuf-21/lib/libprotobuf.a
    /usr/local/protobuf-21/lib/libprotoc.a
    grpc++
    grpc
    grpc++_reflection
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
)
