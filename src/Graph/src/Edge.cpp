#include <string>
#include <algorithm>
#include <iostream>
#include "Graph/Edge.h"


template<typename T>
Edge<T>::Edge(Node<T> *first, Node<T> *second, T cost, int direction) : first(first), second(second), cost(cost),
direction(direction){}

template<typename T>
T Edge<T>::getCost() const {
    return this->cost;
}

template<typename T>
void Edge<T>::setCost(T cost) {
    this->cost = cost;
}

template<typename T>
Node<T> *Edge<T>::getFirst() const {
    return this->first;
}

template<typename T>
Node<T> *Edge<T>::getSecond() const {
    return this->second;
}

template<typename T>
int Edge<T>::getDirection() const {
    return this->direction;
}

template<typename T>
void Edge<T>::setDirection(int direction) {
    this->direction = direction;
}

template<typename T>
void Edge<T>::reverseDirection() {
    if (this->direction == Direction::FORWARD) {
        this->direction = Direction::BACKWARD;
    }
    else if (this->direction == Direction::BACKWARD) {
        this->direction = Direction::FORWARD;
    }
}

template
class Edge<int>;

template
class Edge<double>;

template
class Edge<float>;

template
class Edge<char>;

template
class Edge<std::string>;
