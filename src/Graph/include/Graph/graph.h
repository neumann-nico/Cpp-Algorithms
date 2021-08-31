#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <list>
#include <vector>
#include <string>

#include "node.h"
#include "edge.h"
#include "flowedge.h"


template<class T>
class Graph {
public:
    Graph();

    explicit Graph(std::string inputfile, int direction = Direction::UNDIRECTED);

    ~Graph();

    bool process(std::string inputfile, int direction);

    void resetVisited();

    bool allVisited();

    int getNodeSize();

    Node *getNode(int key);

    std::vector<Node *> getAllNodes();

    int getEdgeSize();

    std::map<Node *, std::vector<T *>> getAllEdges();

    std::vector<T *> getEdges(Node *node);

    std::vector<T *> getEdges(int key);

    T *getEdge(Node *origin, Node *destination);

    T *getEdge(int origin, int destination);

    void updateEdge(Node *node1, Node *node2, double cost, int direction = Direction::UNDIRECTED, double capacity = 0.0);

    void deleteEdge(Node *node1, Node *node2);

    void deleteNode(Node *node);

    void updateNode(Node *node);

    friend Graph<Edge> *convert_to_residual(Graph<Edge> *);

protected:
    std::vector<Node *> nodes;
    std::map<Node *, std::vector<T *>> edges;
    std::map<std::pair<Node *, Node *>, T *> edge_association;
};

Graph<Edge> *convert_to_residual(Graph<Edge> *from);

#endif // GRAPH_H
