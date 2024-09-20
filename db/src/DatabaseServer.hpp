
#include <grpcpp/grpcpp.h>
#include <db.pb.h>
#include <db.grpc.pb.h>

namespace db {

class DatabaseServer final : public database::Database::Service {
    public:
    DatabaseServer();
    ~DatabaseServer() = default;

    private:
    auto StoreData(grpc::ServerContext* context, const database::StoreRequest* request,
                   database::StoreResponse* reply) -> grpc::Status override;
    auto RetrieveData(grpc::ServerContext* context, const database::RetrieveRequest* request,
                      database::RetrieveResponse* reply) -> grpc::Status override;
};

} // namespace db
