source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES main.cpp)

add_executable(server main.cpp)

target_link_libraries(server PRIVATE hello)