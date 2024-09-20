find_package(SqliteOrm REQUIRED)

set(DB_LIB lib${DB_NAME})

add_library(${DB_LIB} SHARED 
    SQLiteWrapper.cpp
    # DatabaseServer.cpp
    # Database.cpp
)

add_executable(${DB_NAME} main.cpp)

target_link_libraries(${DB_NAME} PRIVATE ${DB_LIB} sqlite_orm::sqlite_orm)
