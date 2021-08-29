add_executable(Graph_test testGraph.cpp)

target_link_libraries(Graph_test PRIVATE Graph gtest gtest_main)

add_test(NAME Graph_test COMMAND Graph_test)
