#include <Graph/Graph.h>
#include <string>
#include <iostream>
#include <algorithm>

template<typename T>
Graph<T>::Graph() : size(0) {}

template<typename T>
void Graph<T>::addNode(Node<T>* node) {
    this->nodes.push_back(node);
    ++this->size;
}

template<typename T>
void Graph<T>::removeNode(Node<T>* node) {
    auto n = std::find(this->nodes.begin(), this->nodes.end(), node);
    if (n != this->nodes.end()) {
        this->nodes.erase(n);
        for (auto &other_nodes : this->nodes){
            other_nodes->removeNeighbour(node);
        }
        delete node;
        --this->size;
    }
}

template<typename T>
void Graph<T>::printGraph() const{
    for (auto &node : this->nodes) {
        std::cout << node->getValue() << ": ";
        node->printNeighbours();
    }
}

template<typename T>
bool Graph<T>::isEmpty() const{
    return this->size == 0;
}

template<typename T>
int Graph<T>::getSize() const{
    return this->size;
}

template<typename T>
void Graph<T>::removeAllNodes() {
    for (int i=0; i < this->nodes.size(); ++i){
        delete this->nodes[i];
    }
    this->nodes.clear();
    this->size = 0;
}

template<typename T>
Graph<T>::~Graph() {
    this->removeAllNodes();
}

template<typename T>
std::vector<Node<T> *> Graph<T>::getNodes() const {
    return this->nodes;
}

template<typename T>
Node<T> *Graph<T>::getNode(T value) const {
    for (auto &node : this->nodes) {
        if (node->getValue() == value) return node;
    }
    return nullptr;
}

template
class Graph<int>;

template
class Graph<double>;

template
class Graph<float>;

template
class Graph<char>;

template
class Graph<std::string>;