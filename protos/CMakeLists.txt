find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

set(PROTO_NAMESPACE hello)

# Protobuf/Grpc source files
set(PROTO_FILES
    hello.proto
    database.proto
)

# Add Library target with protobuf sources
add_library(${PROTO_NAMESPACE} ${PROTO_FILES})
target_link_libraries(${PROTO_NAMESPACE}
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)
target_include_directories(${PROTO_NAMESPACE} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Compile protobuf and grpc files in ${PROTO_NAMESPACE} target to cpp
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET ${PROTO_NAMESPACE} LANGUAGE cpp)
protobuf_generate(TARGET ${PROTO_NAMESPACE} LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")