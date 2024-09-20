#include <sqlite_orm/sqlite_orm.h>

#include <string>

namespace db {

// move to a global header file
enum class DataType {
    SYS_METRIC = 0,
    LOG_RECORD,
    ERROR_REPORT,
};

class DataStruct {
    public:
    uint32_t id;
    std::string timestamp;
    DataType type;
};

inline auto initStorage(const std::string& path)
{
    using namespace sqlite_orm;
    return make_storage(path,
                        make_table("DB",
                                   make_column("ID", &DataStruct::id, primary_key()),
                                   make_column("TIMESTAMP", &DataStruct::timestamp),
                                   make_column("DATATYPE", &DataStruct::type)));
}

using Storage = decltype(initStorage(""));

} // namespace
