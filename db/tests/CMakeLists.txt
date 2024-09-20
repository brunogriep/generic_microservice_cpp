enable_testing()

find_package(GTest REQUIRED)

add_executable(${DB_NAME}_test SQLiteWrapperTest.cpp)
target_link_libraries(
    example_test
    GTest::gtest_main
    ${DB_LIB}
)

include(GoogleTest)
gtest_discover_tests(${DB_NAME}_test)