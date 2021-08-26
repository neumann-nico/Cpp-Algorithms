add_executable(AbstractSort_test testAbstractSort.cpp)
target_link_libraries(AbstractSort_test PRIVATE AbstractSort gtest gtest_main)
add_test(NAME AbstractSort_test COMMAND AbstractSort_test)

add_executable(Sorting_test testSorting.cpp)
target_link_libraries(Sorting_test PRIVATE
        BubbleSort
        InsertionSort
        MergeSort
        QuickSort
        gtest
        gtest_main)
add_test(NAME Sorting_test COMMAND Sorting_test)
