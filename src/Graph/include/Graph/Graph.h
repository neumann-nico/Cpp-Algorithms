#pragma once

#include <vector>
#include "Graph/Node.h"

template<typename T>
class Graph {
public:
    Graph();

    ~Graph();

    void addNode(Node<T>* node);

    void removeNode(Node<T>* node);

    void removeAllNodes();

    void printGraph() const;

    std::vector<Node<T>*> getNodes() const;

    Node<T>* getNode(T value) const;

    bool isEmpty() const;

    int getSize() const;

private:
    std::vector<Node<T>*> nodes;
    int size;
};
