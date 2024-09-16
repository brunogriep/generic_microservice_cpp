cmake_minimum_required(VERSION 3.8)
project(GenericMicroservice)

# include(cmake/common.cmake)
find_package(Threads REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

# Proto file
set(hello_proto "{CMAKE_SOURCE_DIR}/protos/hello.proto")
set(hello_proto_path "{CMAKE_SOURCE_DIR}/protos/")
set(hello_build_path "{CMAKE_BINARY_DIR}/hello/")

# Generated sources
set(hello_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/hello.pb.cc")
set(hello_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/hello.pb.h")
set(hello_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/hello.grpc.pb.cc")
set(hello_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/hello.grpc.pb.h")

add_custom_command(
      OUTPUT "${hello_proto_srcs}" "${hello_proto_hdrs}" "${hello_grpc_srcs}" "${hello_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${hello_build_path}"
        --cpp_out "${hello_build_path}"
        -I "${hello_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hello_proto}"
      DEPENDS "${hello_proto}")

include_directories("${hello_build_path}")

# hello_grpc_proto
add_library(hello_grpc_proto
  ${hello_grpc_srcs}
  ${hello_grpc_hdrs}
  ${hello_proto_srcs}
  ${hello_proto_hdrs})

# target_link_libraries(hello_grpc_proto
#   absl::absl_log
#   ${_REFLECTION}
#   ${_GRPC_GRPCPP}
#   protobuf::protobuf)
