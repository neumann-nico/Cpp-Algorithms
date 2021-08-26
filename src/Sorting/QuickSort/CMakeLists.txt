add_library(QuickSort
        include/QuickSort/QuickSort.h
        src/QuickSort.cpp)

target_include_directories(QuickSort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(QuickSort PUBLIC CppAlgorithms AbstractSort)

add_executable(QuickSort_run src/main.cpp)
target_link_libraries(QuickSort_run QuickSort)