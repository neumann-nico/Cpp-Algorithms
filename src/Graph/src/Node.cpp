#include <string>
#include <algorithm>
#include <iostream>
#include "Graph/Node.h"

template<typename T>
Node<T>::Node(T value) : value(value) {}

template<typename T>
T Node<T>::getValue() {
    return this->value;
}

template<typename T>
void Node<T>::setValue(T value) {
    this->value = value;
}

template<typename T>
std::vector<Node<T> *> Node<T>::getNeighbours() {
    return this->neighbours;
}

template<typename T>
void Node<T>::addNeighbour(Node<T> *node) {
    this->neighbours.push_back(node);
}

template<typename T>
void Node<T>::removeNeighbour(Node<T> *node) {
    auto n = std::find(this->neighbours.begin(), this->neighbours.end(), node);
    if (n != this->neighbours.end()) {
        this->neighbours.erase(n);
    }
}

template<typename T>
void Node<T>::removeAllNeighbours() {
    this->neighbours.clear();
}

template<typename T>
void Node<T>::printNeighbours() {
    std::cout << "[";
    for (int i = 0; i < this->neighbours.size(); ++i) {
        std::cout << this->neighbours[i]->getValue();
        if (i < this->neighbours.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template
class Node<int>;

template
class Node<double>;

template
class Node<float>;

template
class Node<char>;

template
class Node<std::string>;