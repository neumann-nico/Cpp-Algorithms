#pragma once

#include <vector>
#include "Node.h"
#include "Edge.h"

template<typename T>
class Graph {
public:
    Graph();

    ~Graph();

    void addNode(Node<T>* node);

    void removeNode(Node<T>* node);

    void removeAllNodes();

    void removeAllEdges();

    void printGraph() const;

    std::vector<Node<T>*> getNodes() const;

    std::vector<Edge<T>*> getEdges() const;

    Node<T>* getNode(T value) const;

    Edge<T>* getEdge(Node<T>* first, Node<T>* second) const;

    Edge<T>* getEdge(T first, T second) const;

    bool isEmpty() const;

    int getSize() const;

private:
    std::vector<Node<T>*> nodes;
    std::vector<Edge<T>*> edges;
    int size;
};
