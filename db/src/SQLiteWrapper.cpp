#include "SQLiteWrapper.hpp"

// TODO: remove aftger adding glog logs
#include <iostream>

namespace db {

SQLiteWrapper::SQLiteWrapper()
    : m_latestUuid(0)
{
    m_storage = std::make_unique<Storage>(initStorage("db.sqlite"));
    m_storage->sync_schema();
}

uint32_t SQLiteWrapper::Store(const DataStruct& data)
{
    m_latestUuid = m_storage->insert(data);
    return m_latestUuid;
}

DataStruct SQLiteWrapper::Retrieve()
{
    return Retrieve(m_latestUuid);
}

DataStruct SQLiteWrapper::Retrieve(uint32_t id)
{
    // auto data = m_storage->get_no_throw<DataStruct>(id);
    // std::cout << "tweet with id " << id << (bool(data) ? " exists" : " doesn't exist") << std::endl;
    // if (data) {
    //     std::cout << m_storage->dump(*data) << std::endl;
    // }
    auto data = m_storage.get(id);
    return data;
}

/*
auto SQLiteWrapper::UpdateBackup() -> void {
    // TODO
}

auto SQLiteWrapper::PerformBackup() -> void {
    // TODO
}

auto SQLiteWrapper::Remove() -> void
{
    m_storage->remove_all<DataStruct>();
}

auto SQLiteWrapper::Remove(uint32_t id) -> void
{
    m_storage->remove<DataStruct>(id);
}
*/

} // namespace db
