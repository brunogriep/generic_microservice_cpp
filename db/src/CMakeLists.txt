find_package(SqliteOrm REQUIRED)

add_executable(db main.cpp)

target_link_libraries(db PRIVATE sqlite_orm::sqlite_orm)
