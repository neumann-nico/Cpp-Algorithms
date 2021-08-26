add_library(DoubleLinkedList
        include/DoubleLinkedList/List.h
        include/DoubleLinkedList/Node.h
        src/List.cpp
        src/Node.cpp
        )

target_include_directories(DoubleLinkedList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(DoubleLinkedList PUBLIC CppAlgorithms)

add_executable(DoubleLinkedList_run src/main.cpp)
target_link_libraries(DoubleLinkedList_run DoubleLinkedList)