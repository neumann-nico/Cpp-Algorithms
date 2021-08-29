#include "Graph/Graph.h"
#include "Graph/Node.h"

int main() {
    Graph<int> graph;

    auto *node1 = new Node<int>(1);
    auto *node2 = new Node<int>(2);
    auto *node3 = new Node<int>(3);
    auto *node4 = new Node<int>(4);

    node1->addNeighbour(node2);
    node2->addNeighbour(node3);
    node4->addNeighbour(node1);

    graph.addNode(node1);
    graph.addNode(node2);
    graph.addNode(node3);
    graph.addNode(node4);

    graph.printGraph();
}
