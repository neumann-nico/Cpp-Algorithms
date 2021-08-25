add_library(AbstractSort
        include/AbstractSort/AbstractSort.h
        src/AbstractSort.cpp)

target_include_directories(AbstractSort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(AbstractSort PUBLIC CppAlgorithms)
