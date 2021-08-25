add_executable(BubbleSort_test testBubbleSort.cpp)

target_link_libraries(BubbleSort_test PRIVATE BubbleSort gtest gtest_main)

add_test(NAME BubbleSort_test COMMAND BubbleSort_test)
