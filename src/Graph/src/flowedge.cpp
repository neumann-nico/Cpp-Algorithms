#include "Graph/flowedge.h"

FlowEdge::FlowEdge(Node *origin, Node *destination, double cost, int direction)
        : Edge(origin, destination, cost, direction), capacity(cost), flow(0.0) {}

std::ostream &operator<<(std::ostream &s, const FlowEdge &edge) {
    return s << edge.origin << " ->(" << edge.getCost() << ", " << edge.getCapacity() << ")-> " << edge.destination
             << " : " << edge.cost;
}

std::ostream &operator<<(std::ostream &s, const FlowEdge *edge) {
    return s << edge->origin << " ->(" << edge->cost << ", " << edge->capacity << ")-> " << edge->destination;
}
