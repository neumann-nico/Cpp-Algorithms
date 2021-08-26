add_library(InsertionSort
        include/InsertionSort/InsertionSort.h
        src/InsertionSort.cpp)

target_include_directories(InsertionSort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(InsertionSort PUBLIC CppAlgorithms AbstractSort)

add_executable(InsertionSort_run src/main.cpp)
target_link_libraries(InsertionSort_run InsertionSort)