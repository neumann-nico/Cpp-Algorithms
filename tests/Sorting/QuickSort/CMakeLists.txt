add_executable(QuickSort_test testQuickSort.cpp)

target_link_libraries(QuickSort_test PRIVATE QuickSort gtest gtest_main)

add_test(NAME QuickSort_test COMMAND QuickSort_test)
