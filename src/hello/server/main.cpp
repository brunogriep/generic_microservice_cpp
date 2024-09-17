#include <hello.pb.h>
#include <hello.grpc.pb.h>

#include <grpc/grpc.h>
#include <grpcpp/server_builder.h>

#include <iostream>

class HelloService final : public hello::Greeter::Service {
    public:
        virtual ::grpc::Status SayHello(::grpc::ServerContext* context, const ::hello::HelloMessage* request, ::hello::HelloMessage* response)
        {
            std::cout << "Server: GetAddress for \"" << request->msg() << "\"." << std::endl;
            response->set_msg("Hello");
            return grpc::Status::OK;
        }
};

int main(int argc, char* argv[])
{
    grpc::ServerBuilder builder;
    builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());

    HelloService my_service;
    builder.RegisterService(&my_service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    server->Wait();
    
    return 0;
}