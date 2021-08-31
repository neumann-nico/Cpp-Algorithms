add_library(Graph
        include/Graph/Edge.h
        include/Graph/Graph.h
        include/Graph/Node.h
        src/Edge.cpp
        src/Graph.cpp
        src/Node.cpp
        )

target_include_directories(Graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Graph PUBLIC CppAlgorithms)

add_executable(Graph_run src/main.cpp)
target_link_libraries(Graph_run Graph)