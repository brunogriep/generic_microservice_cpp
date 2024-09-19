#include "sqliteConfig.hpp"

namespace db {

class SQLiteWrapper {
    public:
    SQLiteWrapper();
    ~SQLiteWrapper() = default;

    virtual auto Store(DataStruct data) -> void;
    virtual auto Retrieve() -> DataType;            // retrieve latest data
    virtual auto Retrieve(uint32_t id) -> DataType; // retrieve data from specific id
    virtual auto UpdateBackup() -> void;
    virtual auto PerformBackup() -> void;
    virtual auto Remove() -> void;            // remove all data entries
    virtual auto Remove(uint32_t id) -> void; // remove a specific data entry giving an ID

    private:
    uint32_t m_latestUuid;
    std::unique_ptr<Storage> m_storage;
};

} // namespace
