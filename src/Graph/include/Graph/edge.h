#ifndef EDGE_H
#define EDGE_H

#include "node.h"

enum Direction {
    UNDIRECTED = 0,
    FORWARD = 1,
    BACKWARD = 2
};

class Edge {
public:
    Edge() : origin(), destination(), cost() {};

    Edge(Node *origin, Node *destination, double cost = 1.0, int direction = Direction::UNDIRECTED);

    friend std::ostream &operator<<(std::ostream &, const Edge &);

    friend std::ostream &operator<<(std::ostream &, const Edge *);

    Node *getOrigin() const { return this->origin; };

    Node *getDestination() const { return this->destination; };

    Node *getOtherNode(Node *node) const;

    double getCost() const { return this->cost; };

    int getVisited() const { return this->visited; };

    int getDirection() const { return this->direction; }

    double getCapacity() const { return this->capacity; }

    double getFlow() const { return this->flow; }

    void setOrigin(Node *node) { this->origin = node; };

    void setDestination(Node *node) { this->destination = node; };

    void setCost(double cost) { this->cost = cost; };

    void setVisited(bool visited) { this->visited = visited; };

    void setDirection(int direction) { this->direction = direction; }

    void setCapacity(double capacity) { this->capacity = capacity; }

    void setFlow(double filled) { this->flow = filled; }

    bool operator()(const Edge *lhs, const Edge *rhs) const {
        return lhs->getCost() > rhs->getCost();
    }

protected:
    Node *origin = nullptr;
    Node *destination = nullptr;

    double cost;
    double capacity = 0.0;
    double flow = 0.0;

    int direction = Direction::UNDIRECTED;
    bool visited = false;
};

#endif // EDGE_H
