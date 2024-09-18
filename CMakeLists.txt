cmake_minimum_required(VERSION 3.13)
project(example-grpc LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(protos)
# TODO: Add a CMakeLists.txt under src
add_subdirectory(src/hello)

add_subdirectory(test)