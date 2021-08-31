#include "Graph/edge.h"

Edge::Edge(Node *origin, Node *destination, double cost, int direction) : origin(origin),
                                                                                  destination(destination),
                                                                                  cost(cost),
                                                                                  direction(direction) {}

Node *Edge::getOtherNode(Node *node) const {
    if (node == this->origin) return this->destination;
    return this->origin;
};

std::ostream &operator<<(std::ostream &s, const Edge &edge) {
    return s << edge.origin << " ->(" << edge.getFlow() << ", " << edge.getCapacity() << "," << edge.getCost() << ")-> "
             << edge.destination << " : " << edge.cost;
}

std::ostream &operator<<(std::ostream &s, const Edge *edge) {
    return s << edge->origin << " ->(" << edge->flow << ", " << edge->capacity << ", " << edge->cost << ")-> "
             << edge->destination;
}
