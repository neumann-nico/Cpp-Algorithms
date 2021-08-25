add_library(BubbleSort
        include/BubbleSort/BubbleSort.h
        src/BubbleSort.cpp)

target_include_directories(BubbleSort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(BubbleSort PUBLIC CppAlgorithms AbstractSort)

add_executable(BubbleSort_run src/main.cpp)
target_link_libraries(BubbleSort_run BubbleSort)