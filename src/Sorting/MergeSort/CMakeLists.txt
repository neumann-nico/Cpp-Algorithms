add_library(MergeSort
        include/MergeSort/MergeSort.h
        src/MergeSort.cpp)

target_include_directories(MergeSort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(MergeSort PUBLIC CppAlgorithms AbstractSort)

add_executable(MergeSort_run src/main.cpp)
target_link_libraries(MergeSort_run MergeSort)