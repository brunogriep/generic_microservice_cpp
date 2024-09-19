source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES main.cpp)

add_executable(client main.cpp)

target_link_libraries(client PRIVATE hello)