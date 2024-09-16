cmake_minimum_required(VERSION 3.8)

find_package(Threads REQUIRED)
find_package(Protobuf REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")
find_package(gRPC  REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")
