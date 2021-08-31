add_library(Graph
        include/Graph/algorithm.h
        include/Graph/edge.h
        include/Graph/flowedge.h
        include/Graph/graph.h
        include/Graph/node.h
        src/algorithm.cpp
        src/edge.cpp
        src/flowedge.cpp
        src/graph.cpp
        src/node.cpp
        )

target_include_directories(Graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Graph PUBLIC CppAlgorithms)

add_executable(Graph_run src/main.cpp)
target_link_libraries(Graph_run Graph)