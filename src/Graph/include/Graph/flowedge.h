#ifndef FLOWEDGE_H
#define FLOWEDGE_H

#include "edge.h"


class FlowEdge : public Edge {
public:
    FlowEdge() : Edge() {};

    FlowEdge(Node *origin, Node *destination, double cost = 1.0, int direction = Direction::UNDIRECTED);

    friend std::ostream &operator<<(std::ostream &, const FlowEdge &);

    friend std::ostream &operator<<(std::ostream &, const FlowEdge *);

    double getCapacity() const { return this->capacity; }

    double getFlow() const { return this->flow; }

    void setCapacity(double capacity) { this->capacity = capacity; }

    void setFlow(double filled) { this->flow = filled; }

    bool operator()(const FlowEdge *lhs, const FlowEdge *rhs) const {
        return lhs->getCost() > rhs->getCost();
    }

protected:
    double capacity = 0.0;
    double flow = 0.0;
};

#endif // FLOWEDGE_H
