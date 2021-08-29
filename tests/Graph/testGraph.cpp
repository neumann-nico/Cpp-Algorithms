#include <algorithm>
#include "gtest/gtest.h"
#include "Graph/Graph.h"

TEST(Graph, graph1) {
    Graph<int> graph;
    EXPECT_EQ(graph.getSize(), 0);

    auto *node1 = new Node<int>(1);
    auto *node2 = new Node<int>(2);
    auto *node3 = new Node<int>(3);
    auto *node4 = new Node<int>(4);

    node1->addNeighbour(node2);
    node2->addNeighbour(node3);
    node4->addNeighbour(node1);

    graph.addNode(node1);
    EXPECT_EQ(graph.getSize(), 1);
    graph.addNode(node2);
    EXPECT_EQ(graph.getSize(), 2);
    graph.addNode(node3);
    EXPECT_EQ(graph.getSize(), 3);
    graph.addNode(node4);
    EXPECT_EQ(graph.getSize(), 4);

    EXPECT_EQ(graph.getNode(4)->getNeighbours().size(), 1);

    graph.removeNode(node1);
    EXPECT_EQ(graph.getSize(), 3);

    EXPECT_EQ(graph.getNode(4)->getNeighbours().size(), 0);

    graph.printGraph();
}
