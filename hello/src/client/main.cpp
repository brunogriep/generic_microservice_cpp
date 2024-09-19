#include <hello.pb.h>
#include <hello.grpc.pb.h>

#include <grpc/grpc.h>
#include <grpcpp/create_channel.h>

#include <iostream>

int main(int argc, char* argv[])
{
    // Setup request
    hello::HelloMessage request;
    hello::HelloMessage result;
    request.set_msg("hi");

    // Call
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    auto stub = hello::Greeter::NewStub(channel);
    grpc::ClientContext context;
    grpc::Status status = stub->SayHello(&context, request, &result);

    // Output result
    std::cout << "I got:" << std::endl;
    std::cout << "Name: " << result.msg() << std::endl;

    return 0;
}