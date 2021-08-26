add_executable(PerformanceAnalysis_run src/main.cpp)
target_link_libraries(PerformanceAnalysis_run
        AbstractSort
        BubbleSort
        InsertionSort
        MergeSort
        QuickSort)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/files DESTINATION ${CMAKE_CURRENT_BINARY_DIR})