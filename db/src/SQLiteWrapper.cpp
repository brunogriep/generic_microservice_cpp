#include "SQLiteWrapper.hpp"

namespace db {

SQLiteWrapper::SQLiteWrapper()
    : m_storage(std::make_unique<Storage>(initStorage("db.sqlite")))
{
    m_storage->sync_schema();
    m_storage->remove_all<DataStruct>();
}

auto SQLiteWrapper::Store(DataStruct &data) -> void {
    data.id = storage.insert(data);
 }

auto SQLiteWrapper::Retrieve() -> DataType { }

auto SQLiteWrapper::Retrieve(uint32_t id) -> DataType { }

auto SQLiteWrapper::UpdateBackup() -> void { }

auto SQLiteWrapper::PerformBackup() -> void { }

auto SQLiteWrapper::Remove() -> void
{
    m_storage->remove_all<DataStruct>();
}

auto SQLiteWrapper::Remove(uint32_t id) -> void
{
    storage.remove<DataStruct>(id);
}

}
