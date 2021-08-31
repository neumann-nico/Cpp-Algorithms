#pragma once

#include <Graph/Node.h>

enum Direction {
    FORWARD = 0,
    BACKWARD = 1,
    UNDIRECTED = 2
};

template<typename T>
class Edge {
public:
    explicit Edge(Node<T>* first, Node<T>* second, T cost, int direction = Direction::UNDIRECTED);

    T getCost() const;

    void setCost(T cost);

    Node<T>* getFirst() const;

    Node<T>* getSecond() const;

    int getDirection() const;

    void setDirection(int direction);

    void reverseDirection();

private:
    Node<T>* first;
    Node<T>* second;
    T cost;
    int direction;
};

