#include "sqliteConfig.hpp"

// TODO: add #ifdef GTEST_ENABLED here
#include <gtest/gtest_prod.h>

namespace db {

class SQLiteWrapper {
    public:
    SQLiteWrapper();
    virtual ~SQLiteWrapper() = default;

    virtual uint32_t Store(const DataStruct& data);
    virtual DataStruct Retrieve();            // retrieve latest data
    virtual DataStruct Retrieve(uint32_t id) ; // retrieve data from specific id
    /*
    virtual auto UpdateBackup() -> void;
    virtual auto PerformBackup() -> void;
    virtual auto Remove() -> void;            // remove all data entries
    virtual auto Remove(uint32_t id) -> void; // remove a specific data entry giving an ID
    */
    private:
    FRIEND_TEST(SQLiteWrapperTest, First);
    FRIEND_TEST(SQLiteWrapperTest, StoreAndRetrieveLatest);
    uint32_t m_latestUuid;
    std::unique_ptr<Storage> m_storage;
};

} // namespace db
