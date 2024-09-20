#include "gtest/gtest.h"
#include "SQLiteWrapper.hpp"
#include <chrono>
#include <sstream>


namespace db {


TEST(SQLiteWrapperTest, First) 
{
    SQLiteWrapper sql;
    EXPECT_EQ(m_latestUuid, 0);
    EXPECT_TRUE(m_storage);
}

TEST(SQLiteWrapperTest, StoreAndRetrieveLatest) 
{
    auto now = std::chrono::system_clock::now();
    auto tt = std::chrono::system_clock::to_time_t(now);
    auto tm = *std::gmtime(&tt);
    std::stringstream ss;
    ss << std::put_time(&tm,  "UTC: %Y-%m-%d %H:%M:%S");

    DataStruct data {-1, ss.str(), DataType::SYS_METRIC};
 
    SQLiteWrapper sql;

    EXPECT_EQ(m_latestUuid, 0);
    sql.Store(&data);
    EXPECT_EQ(m_latestUuid, 1);

    DataStruct dataRetrieved = sql.Retrieve();
    EXPECT_EQ(m_latestUuid, dataRetrieved.id);
    EXPECT_EQ(data.timestamp, dataRetrieved.timestamp);
    EXPECT_EQ(data.type, dataRetrieved.type);

}

// TEST(SQLiteWrapperTest, Retrieve) 
// {
//     SQLiteWrapper sql;
// }

// TEST(SQLiteWrapperTest, Remove) 
// {
//     SQLiteWrapper sql;
// }

// TEST(SQLiteWrapperTest, RemoveAll) 
// {
//     SQLiteWrapper sql;
// }

} // namespace db
