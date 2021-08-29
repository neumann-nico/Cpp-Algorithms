#pragma once

#include <vector>

template<typename T>
class Node {
public:
    explicit Node(T value);

    T getValue();

    void setValue(T value);

    std::vector<Node<T>*> getNeighbours();

    void addNeighbour(Node<T> *node);

    void removeNeighbour(Node<T> *node);

    void removeAllNeighbours();

    void printNeighbours();

private:
    T value;
    std::vector<Node<T>*> neighbours;
};
