add_executable(AbstractSort_test testAbstractSort.cpp)

target_link_libraries(AbstractSort_test PRIVATE AbstractSort gtest gtest_main)

add_test(NAME AbstractSort_test COMMAND AbstractSort_test)
