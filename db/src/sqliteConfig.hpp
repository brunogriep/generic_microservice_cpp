#include <sqlite_orm/sqlite_orm.h>

#include <string>

namespace db {

    // move to a global header file
    enum class DataType {
        SYS_METRIC = 0,
        LOG_RECORD,
    };

    struct DataStruct {
        uint32_t id;
        std::string timestamp;
        DataType type;
    };

inline auto initStorage(const std::string& path) {
    using namespace sqlite_orm;
    return sqlite_orm::make_storage(path,
                        sqlite_orm::make_table("COMPANY",
                                   sqlite_orm::make_column("ID", &Employee::id, primary_key()),
                                   sqlite_orm::make_column("NAME", &Employee::name),
                                   sqlite_orm::make_column("AGE", &Employee::age),
                                   sqlite_orm::make_column("ADDRESS", &Employee::address),
                                   sqlite_orm::make_column("SALARY", &Employee::salary)));
}

using Storage = decltype(initStorage(""));

} // namespace
