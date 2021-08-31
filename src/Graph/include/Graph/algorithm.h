#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <queue>
#include <cmath>

#include "graph.h"
#include "edge.h"

class Algorithm {
public:
    Algorithm();

    explicit Algorithm(const std::string &inputfile);

    void process(const std::string &inputfile, int direction = Direction::UNDIRECTED);

    void printVisitedPath();

    void depthSearch(int startKey, bool recursive = false, bool print = false, bool reset = true);

    void depthSearchRecursive(Node *node, bool print = false);

    void breadthSearch(int startKey, bool print = false, bool reset = true);

    int relatedComponents();

    double prim(int startKey);

    double kruskal();

    double kruskal(std::map<Node *, std::vector<Edge *>> &mst_edges);

    double nearestNeighbor(int startKey);

    double nearestNeighbor(int startKey, std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> &path);

    double doubleTree(int startKey);

    double doubleTree(int startKey, std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> &path);

    void depthSearchRecursiveDoubleTree(Node *node, std::vector<Node *> &node_list,
                                        std::map<Node *, std::vector<Edge *>> &edges);

    double tryAllPossibilities();

    double branchAndBound();

    void TSPRecursive(Node *actual_node, double actual_costs, double &min_costs, int position,
                      std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> &path, bool allow_shortcuts = true);

    void dijkstra(double &distance, int startKey, int endKey = -1, bool directed = false);

    bool mooreBellmanFord(double &distance, int startKey, int endKey = -1, bool print = false);

    bool mooreBellmanFord(int startKey, Graph<Edge> *graph);

    bool calculateSTWay(int startKey, int endKey, Graph<Edge> *graph, std::vector<Edge *> &p);

    double edmondsKarp(int startKey, int endKey = -1);

    double edmondsKarp(int startKey, int endKey, Graph<Edge> *gf, Graph<Edge> *n);

    double cycleCanceling();

    double successiveShortestPath();

    std::vector<Node *> pred;
    std::vector<double> dist;

    bool checkForCycle(Edge *edge);

    std::vector<Edge *> getCyclePath(Edge *edge, Graph<Edge> *graph);

    std::vector<Edge *> buildNegativeCycleFrom(Graph<Edge> *graph);

    Graph<Edge>* getGraph() const;

private:
    Graph<Edge> *graph;
    std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> visitedPath;
};

#endif // ALGORITHM_H
