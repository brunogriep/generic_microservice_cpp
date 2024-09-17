find_package(Threads)

#client
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES client/main.cpp)

add_executable(client client/main.cpp)
target_link_libraries(client PRIVATE hello)

#server
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES server/main.cpp)
add_executable(server server/main.cpp)
target_link_libraries(server PRIVATE hello)