#include "Graph/algorithm.h"
#include "Graph/edge.h"

Algorithm::Algorithm() : graph(new Graph<Edge>()) {}

Algorithm::Algorithm(const std::string &inputfile) : graph(new Graph<Edge>(inputfile)) {
    std::cout << "Processed graph " << inputfile << " with " << this->graph->getNodeSize() << " nodes and "
              << this->graph->getEdgeSize() << " edges." << std::endl;
}

void Algorithm::process(const std::string &inputfile, int direction) {
    if (this->graph->process(inputfile, direction))
        std::cout << "Processed graph " << inputfile << " with " << this->graph->getNodeSize() << " nodes and "
                  << this->graph->getEdgeSize() << " edges." << std::endl;
    else
        std::cout << "Error processing graph!" << std::endl;
}

void Algorithm::printVisitedPath() {
    for (auto &i: this->visitedPath) {
        std::cout << i.first.first->getKey() << "->(" << i.second->getCost() << ")->" << i.first.second->getKey()
                  << "\n";
    }
}

void Algorithm::depthSearch(int startKey, bool recursive, bool print, bool reset) {
    if (reset) this->graph->resetVisited();

    if (recursive) {
        depthSearchRecursive(this->graph->getNode(startKey));
        return;
    }

    std::deque<Node *> queue;
    queue.push_back(this->graph->getNode(startKey));
    this->graph->getNode(startKey)->setVisited(true);

    while (!queue.empty()) {
        Node *node = (Node *) queue.front();
        queue.pop_front();
        std::vector<Edge *> curEdges = this->graph->getEdges(node);
        for (auto iter = curEdges.rbegin(); iter != curEdges.rend(); ++iter) {
            Edge *edge = *iter;
            Node *destination_node = edge->getOtherNode(node);
            if (!destination_node->getVisited()) {
                destination_node->setVisited(true);
                if (print)
                    std::cout << *node << "->" << *destination_node << std::endl;
                queue.push_front(destination_node);
            }
        }
    }
}

void Algorithm::depthSearchRecursive(Node *node, bool print) {
    node->setVisited(true);

    for (auto const &edge: this->graph->getEdges(node)) {
        Node *destination_node = edge->getOtherNode(node);
        if (!destination_node->getVisited()) {
            if (print)
                std::cout << *node << "->" << *destination_node << std::endl;
            depthSearchRecursive(destination_node);
        }
    }
}

void Algorithm::breadthSearch(int startKey, bool print, bool reset) {
    if (reset) this->graph->resetVisited();
    std::queue<Node *> queue;
    queue.push(this->graph->getNode(startKey));
    this->graph->getNode(startKey)->setVisited(true);

    while (!queue.empty()) {
        Node *node = (Node *) queue.front();
        queue.pop();
        for (auto const &edge: this->graph->getEdges(node)) {
            Node *destination_node = edge->getOtherNode(node);
            if (!destination_node->getVisited()) {
                destination_node->setVisited(true);
                queue.push(destination_node);
                if (print)
                    std::cout << *node << "->" << *destination_node << std::endl;
            }
        }
    }
}

int Algorithm::relatedComponents() {
    this->graph->resetVisited();
    std::vector<Node *> nodes = this->graph->getAllNodes();
    int related = 0;

    for (auto iter = nodes.begin(); iter != nodes.end();) {
        this->breadthSearch((*iter)->getKey(), false, false);
        related++;

        do {
            ++iter;
        } while (iter != nodes.end() && (*iter)->getVisited());
    }
    return related;
}

double Algorithm::prim(int startKey) {
    this->graph->resetVisited();
    double costs = 0.0;

    std::priority_queue<Edge *, std::vector<Edge *>, Edge> pq;

    for (const auto &edge: this->graph->getEdges(startKey)) {
        pq.push(edge); // add all edges from the start node
    }

    this->graph->getNode(startKey)->setVisited(true); // mark starting node

    while (!pq.empty()) {
        Edge *e = pq.top();
        pq.pop();
        e->setVisited(true);
        Node *node = e->getDestination();
        if (node->getVisited()) node = e->getOrigin();
        if (!node->getVisited()) {
            for (const auto &edge: this->graph->getEdges(node)) {
                if (!edge->getVisited())
                    pq.push(edge); // add all edges from the visited node
            }
            costs += e->getCost(); // add costs of the edges
            node->setVisited(true); // mark node
        }
    }
    return costs;
}

double Algorithm::kruskal() {
    std::map<Node *, std::vector<Edge *>> mst_edges;
    return this->kruskal(mst_edges);
}

double Algorithm::kruskal(std::map<Node *, std::vector<Edge *>> &mst_edges) {
    this->graph->resetVisited();
    double weight = 0.0;

    struct DisjointSet {
        int *parent, *rank;

        explicit DisjointSet(int n) {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i <= n; ++i) {
                rank[i] = 0;
                parent[i] = i;
            }
        }

        int findParent(int u) {
            if (u != parent[u]) {
                parent[u] = findParent(parent[u]);
            }
            return parent[u];
        }

        void mergeSets(int x, int y) {
            x = findParent(x);
            y = findParent(y);

            if (rank[x] > rank[y])
                parent[y] = x;
            else
                parent[x] = y;

            if (rank[x] == rank[y])
                rank[y]++;
        }
    };

    std::vector<Edge *> sortedEdges;
    std::map<Node *, std::vector<Edge *>> edges = this->graph->getAllEdges();

    // push all edges into a vector
    for (auto &edge: edges) {
        sortedEdges.insert(sortedEdges.end(), edge.second.begin(), edge.second.end());
    }

    // remove duplicates
    sort(sortedEdges.begin(), sortedEdges.end());
    sortedEdges.erase(unique(sortedEdges.begin(), sortedEdges.end()), sortedEdges.end());

    // sort by costs
    sort(sortedEdges.begin(), sortedEdges.end(), [](Edge *left, Edge *right) {
             return left->getCost() < right->getCost();
         }
    );

    // actual kruskal
    DisjointSet ds(this->graph->getNodeSize());

    for (auto &it: sortedEdges) {
        int u = it->getOrigin()->getKey();
        int v = it->getDestination()->getKey();

        int set_u = ds.findParent(u);
        int set_v = ds.findParent(v);

        if (set_u != set_v) {
            weight += it->getCost();
            mst_edges[it->getOrigin()].push_back(it);
            mst_edges[it->getDestination()].push_back(it);
            ds.mergeSets(set_u, set_v);
        }
    }
    return weight;
}

double Algorithm::nearestNeighbor(int startKey) {
    std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> path;
    return this->nearestNeighbor(startKey, path);
}

double Algorithm::nearestNeighbor(int startKey, std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> &path) {
    this->graph->resetVisited();
    double costs = 0.0;

    std::queue<Node *> queue;
    Node *start_node = this->graph->getNode(startKey);
    start_node->setVisited(true);
    queue.push(start_node);

    Node *current_node = nullptr;

    while (!queue.empty()) {
        current_node = queue.front();
        queue.pop();

        Edge *best_edge = nullptr;
        for (const auto &edge: this->graph->getEdges(current_node)) {
            Node *other_node = edge->getOtherNode(current_node);
            if (!other_node->getVisited() and (best_edge == nullptr || edge->getCost() < best_edge->getCost())) {
                best_edge = edge;
            }
        }
        if (best_edge != nullptr) {
            costs += best_edge->getCost();
            Node *other_node = best_edge->getOtherNode(current_node);
            path.emplace_back(std::make_pair(current_node, other_node), best_edge);
            other_node->setVisited(true);
            queue.push(other_node);
        }
    }

    Edge *edge = this->graph->getEdge(current_node, start_node);
    path.emplace_back(std::make_pair(current_node, start_node), edge);
    costs += edge->getCost();

    return costs;
}

void Algorithm::depthSearchRecursiveDoubleTree(Node *node, std::vector<Node *> &node_list,
                                               std::map<Node *, std::vector<Edge *>> &edges) {
    if (node->getVisited()) return;
    node->setVisited(true);
    node_list.push_back(node);

    for (auto const &edge: edges[node]) {
        Node *destination_node = edge->getOtherNode(node);
        if (!destination_node->getVisited()) {
            this->depthSearchRecursiveDoubleTree(destination_node, node_list, edges);
        }
    }
}

double Algorithm::doubleTree(int startKey) {
    std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> path;
    return this->doubleTree(startKey, path);
}

double Algorithm::doubleTree(int startKey, std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> &path) {
    double costs = 0.0;

    std::map<Node *, std::vector<Edge *>> mst_edges;
    this->kruskal(mst_edges);

    std::vector<Node *> node_list;
    Node *start_node = this->graph->getNode(startKey);
    this->graph->resetVisited();
    this->depthSearchRecursiveDoubleTree(start_node, node_list, mst_edges);
    node_list.push_back(start_node);

    for (auto it = node_list.begin(); it != node_list.end() - 1;) {
        Node *first = *it;
        Node *second = *(++it);

        Edge *edge = this->graph->getEdge(first, second);
        path.emplace_back(std::make_pair(first, second), edge);
        costs += edge->getCost();
    }
    return costs;
}

double Algorithm::tryAllPossibilities() {
    double costs = INFINITY;
    std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> path(this->graph->getNodeSize());

    this->graph->resetVisited();
    this->graph->getNode(0)->setVisited(true);
    this->TSPRecursive(this->graph->getNode(0), 0.0, costs, -1, path, false);
    return costs;
}

double Algorithm::branchAndBound() {
    double costs = INFINITY;
    std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> path(this->graph->getNodeSize());

    this->graph->resetVisited();
    this->graph->getNode(0)->setVisited(true);
    this->TSPRecursive(this->graph->getNode(0), 0.0, costs, -1, path, true);
    return costs;
}

void Algorithm::TSPRecursive(
        Node *actual_node,
        double actual_costs,
        double &min_costs,
        int position,
        std::vector<std::pair<std::pair<Node *, Node *>, Edge *>> &path,
        bool allow_shortcuts) {
    if (++position < this->graph->getNodeSize() - 1) {
        for (const auto &edge: this->graph->getEdges(actual_node)) {
            Node *other_node = edge->getOtherNode(actual_node);
            if (!other_node->getVisited()) {
                double costs = actual_costs + edge->getCost();
                if (allow_shortcuts && costs >= min_costs) continue;

                other_node->setVisited(true);
                path[position] = std::make_pair(std::make_pair(actual_node, other_node), edge);
                this->TSPRecursive(other_node, costs, min_costs, position, path, allow_shortcuts);
                other_node->setVisited(false);
            }
        }
    } else {
        Edge *edge = this->graph->getEdge(actual_node, this->graph->getNode(0));
        actual_costs += edge->getCost();
        if (actual_costs < min_costs) {
            path[position] = std::make_pair(std::make_pair(actual_node, this->graph->getNode(0)), edge);
            this->visitedPath = path;
            min_costs = actual_costs;
        }
    }
}

void Algorithm::dijkstra(double &distance, int startKey, int endKey, bool directed) {
    distance = INFINITY;
    this->graph->resetVisited();

    Node *start_node = this->graph->getNode(startKey);

    std::vector<Node *> pred(this->graph->getNodeSize(), nullptr);
    pred[startKey] = start_node;

    std::vector<double> dist(this->graph->getNodeSize(), INFINITY);
    dist[startKey] = 0.0;

    std::priority_queue<std::pair<double, Node *>, std::vector<std::pair<double, Node *>>, std::greater<std::pair<double, Node *>>> pq;
    pq.push(std::make_pair(0.0, start_node));

    while (!pq.empty()) {
        Node *node = pq.top().second;
        pq.pop();
        node->setVisited(true);
        if (node->getKey() == endKey) break;

        for (const auto &edge: this->graph->getEdges(node)) {
            Node *other_node = edge->getDestination();
            if (!directed)
                other_node = edge->getOtherNode(node);
            if ((!directed || node != other_node) && !other_node->getVisited() &&
                dist[node->getKey()] + edge->getCost() < dist[other_node->getKey()]) {
                dist[other_node->getKey()] = dist[node->getKey()] + edge->getCost();
                pred[other_node->getKey()] = node;
                pq.push(std::make_pair(dist[other_node->getKey()], other_node));
            }
        }
    }

    if (endKey != -1) {
        if (pred[endKey] == nullptr) throw std::exception();
        std::cout << startKey << " -> " << endKey << " (" << pred[endKey] << ") : " << dist[endKey] << std::endl;
        distance = dist[endKey];
    } else {
        for (size_t i = 0; i < dist.size(); ++i) {
            if (pred[i] != nullptr)
                std::cout << startKey << " -> " << i << " (" << pred[i] << ") : " << dist[i] << std::endl;
        }
    }
}


bool Algorithm::mooreBellmanFord(double &distance, int startKey, int endKey, bool directed, bool print) {
    distance = INFINITY;
    std::map<Node *, std::vector<Edge *>> edges = this->graph->getAllEdges();

    Node *start_node = this->graph->getNode(startKey);

    pred = std::vector<Node *>(this->graph->getNodeSize(), nullptr);
    pred[startKey] = start_node;

    dist = std::vector<double>(this->graph->getNodeSize(), INFINITY);
    dist[startKey] = 0.0;

    bool changes = true;
    for (int i = 0; changes && i < this->graph->getNodeSize() - 1; ++i) {
        changes = false;
        for (const auto &element: edges) {
            for (const auto &edge: element.second) {

                Node *origin = edge->getOrigin();
                Node *destination = edge->getDestination();

                if (dist[origin->getKey()] + edge->getCost() < dist[destination->getKey()]) {
                    changes = true;
                    dist[destination->getKey()] = dist[origin->getKey()] + edge->getCost();
                    pred[destination->getKey()] = origin;
                }

                if (!directed) {
                    if (dist[destination->getKey()] + edge->getCost() < dist[origin->getKey()]) {
                        changes = true;
                        dist[origin->getKey()] = dist[destination->getKey()] + edge->getCost();
                        pred[origin->getKey()] = destination;
                    }
                }
            }
        }
    }

    for (const auto &element: edges) {
        for (const auto &edge: element.second) {

            Node *origin = edge->getOrigin();
            Node *destination = edge->getDestination();

            if (dist[origin->getKey()] + edge->getCost() < dist[destination->getKey()]) {
                std::cout << "Negative cycle found!" << std::endl;
                return false;
            }
        }
    }
    if (endKey != -1) distance = dist[endKey];

    if (print) {
        if (endKey != -1) {
            if (pred[endKey] == nullptr) throw std::exception();
            std::cout << startKey << " -> " << endKey << " (" << pred[endKey] << ") : " << dist[endKey] << std::endl;
        } else {
            for (size_t i = 0; i < dist.size(); ++i) {
                if (pred[i] != nullptr)
                    std::cout << startKey << " -> " << i << " (" << pred[i] << ") : " << dist[i] << std::endl;
            }
        }
    }
    return true;
}

bool Algorithm::mooreBellmanFord(int startKey, Graph<Edge> *graph) {
    std::map<Node *, std::vector<Edge *>> edges = graph->getAllEdges();

    Node *start_node = graph->getNode(startKey);

    pred = std::vector<Node *>(graph->getNodeSize(), nullptr);
    pred[startKey] = start_node;

    dist = std::vector<double>(graph->getNodeSize(), INFINITY);
    dist[startKey] = 0.0;

    bool changes = true;
    for (int i = 0; changes && i < graph->getNodeSize() - 1; ++i) {
        changes = false;
        for (const auto &element: edges) {
            for (const auto &edge: element.second) {

                Node *origin = edge->getOrigin();
                Node *destination = edge->getDestination();

                if (dist[origin->getKey()] + edge->getCost() < dist[destination->getKey()]) {
                    changes = true;
                    dist[destination->getKey()] = dist[origin->getKey()] + edge->getCost();
                    pred[destination->getKey()] = origin;
                }
            }
        }
    }

    for (const auto &element: edges) {
        for (const auto &edge: element.second) {

            Node *origin = edge->getOrigin();
            Node *destination = edge->getDestination();

            if (dist[origin->getKey()] + edge->getCost() < dist[destination->getKey()]) {
                //std::cout << "Negative cycle found!" << std::endl;
                return false;
            }
        }
    }

    return true;
}

bool Algorithm::calculateSTWay(int startKey, int endKey, Graph<Edge> *graph, std::vector<Edge *> &p) {
    Node *node = graph->getNode(startKey);
    node->setVisited(true);

    for (auto const &edge: graph->getEdges(node)) {
        Node *destination_node = edge->getDestination();
        if (!destination_node->getVisited()) {
            p.push_back(edge);
            if (destination_node->getKey() == endKey)
                return true;
            if (this->calculateSTWay(destination_node->getKey(), endKey, graph, p))
                return true;
            p.pop_back();
        }
    }
    return false;
}

double Algorithm::edmondsKarp(int startKey, int endKey) {
    double value = 0.0;

    Graph<Edge> *n = this->graph;
    Graph<Edge> *gf = convert_to_residual(n);

    while (true) {
        std::vector<Edge *> p;

        gf->resetVisited();
        if (!this->calculateSTWay(startKey, endKey, gf, p)) {
            break;
        }

        double y = INFINITY;
        for (const auto &e: p) {
            if (e->getCost() < y) y = e->getCost();
        }
        value += y;

        for (const auto &e: p) {
            Edge *fe;

            if (e->getDirection() == Direction::BACKWARD) {
                fe = n->getEdge(e->getDestination()->getKey(), e->getOrigin()->getKey());
                fe->setFlow(fe->getFlow() - y);
            } else {
                fe = n->getEdge(e->getOrigin()->getKey(), e->getDestination()->getKey());
                fe->setFlow(fe->getFlow() + y);
            }

            Node *node1 = gf->getNode(fe->getOrigin()->getKey());
            Node *node2 = gf->getNode(fe->getDestination()->getKey());

            // update gf
            double cost = fe->getCapacity() - fe->getFlow();
            if (cost > 0.0) {
                gf->updateEdge(node1, node2, cost, Direction::FORWARD, fe->getCapacity());
            } else {
                gf->deleteEdge(node1, node2);
            }

            if (fe->getFlow() > 0.0) {
                gf->updateEdge(node2, node1, fe->getFlow(), Direction::BACKWARD, fe->getCapacity());
            } else {
                gf->deleteEdge(node2, node1);
            }
        }
    }
    delete gf;
    //delete n;

    return value;
}

double Algorithm::edmondsKarp(int startKey, int endKey, Graph<Edge> *gf, Graph<Edge> *n) {
    double value = 0.0;

    while (true) {
        std::vector<Edge *> p;

        gf->resetVisited();
        if (!this->calculateSTWay(startKey, endKey, gf, p)) {
            break;
        }

        double y = INFINITY;
        for (const auto &e: p) {
            if (e->getCost() < y) y = e->getCost();
        }
        value += y;

        for (const auto &e: p) {
            Edge *fe;

            if (e->getDirection() == Direction::BACKWARD) {
                fe = n->getEdge(e->getDestination()->getKey(), e->getOrigin()->getKey());
                fe->setFlow(fe->getFlow() - y);
            } else {
                fe = n->getEdge(e->getOrigin()->getKey(), e->getDestination()->getKey());
                fe->setFlow(fe->getFlow() + y);
            }

            Node *node1 = gf->getNode(fe->getOrigin()->getKey());
            Node *node2 = gf->getNode(fe->getDestination()->getKey());

            // update gf
            double cost = fe->getCapacity() - fe->getFlow();
            if (cost > 0.0) {
                gf->updateEdge(node1, node2, cost, Direction::FORWARD, fe->getCapacity());
            } else {
                gf->deleteEdge(node1, node2);
            }

            if (fe->getFlow() > 0.0) {
                gf->updateEdge(node2, node1, fe->getFlow(), Direction::BACKWARD, fe->getCapacity());
            } else {
                gf->deleteEdge(node2, node1);
            }
        }
    }

    return value;
}

double Algorithm::cycleCanceling() {
    double value = 0.0;
    Graph<Edge> *n = this->graph;

    std::vector<Node *> source;
    std::vector<Node *> sink;
    double sum_balance = 0.0;
    for (const auto &node: n->getAllNodes()) {
        sum_balance += node->getBalance();
        if (node->getBalance() > 0.0) {
            source.push_back(node);
        } else if (node->getBalance() < 0.0) {
            sink.push_back(node);
        }
    }

    if (sum_balance < -0.01 || sum_balance > 0.01) {
        std::cout << "source and sink not balanced!" << std::endl;
        return INFINITY;
    }

    if (source.empty() || sink.empty()) {
        std::cout << "no source or sink found!" << std::endl;
        return INFINITY;
    }

    // step 1
    Node *super_source = source[0];
    Node *super_sink = sink[0];

    if (!source.empty()) {
        super_source = new Node(n->getNodeSize());
        n->updateNode(super_source);

        for (const auto &node: source) {
            n->updateEdge(super_source, node, 0.0, Direction::FORWARD, std::abs(node->getBalance()));
            n->getEdge(super_source, node)->setCapacity(std::abs(node->getBalance()));
        }
    }

    if (!sink.empty()) {
        super_sink = new Node(n->getNodeSize());
        n->updateNode(super_sink);

        for (const auto &node: sink) {
            n->updateEdge(node, super_sink, 0.0, Direction::FORWARD, std::abs(node->getBalance()));
            n->getEdge(node, super_sink)->setCapacity(std::abs(node->getBalance()));
        }
    }

    Graph<Edge> *gf = convert_to_residual(n);

    // b-fluss: Edmonds-Karp
    this->edmondsKarp(super_source->getKey(), super_sink->getKey(), gf, n);

    // step 2 (loop)
    while (true) {
        gf = convert_to_residual(n);

        bool negative_cycle = false;
        for (auto &node: gf->getAllNodes()) {
            if (!this->mooreBellmanFord(node->getKey(), gf)) {
                negative_cycle = true;
                break;
            }
        }
        if (!negative_cycle) break;

        // find negative cycle way
        std::vector<Edge *> negative_cycle_way = this->buildNegativeCycleFrom(gf);

        // find smallest y
        double y = INFINITY;
        for (auto &edge: negative_cycle_way) {
            if (edge->getFlow() < y) y = edge->getFlow();
        }

        // update flow
        for (auto &flow_edge: negative_cycle_way) {
            Edge *edge = nullptr;

            if (flow_edge->getDirection() == Direction::FORWARD) {
                edge = n->getEdge(flow_edge->getOrigin()->getKey(), flow_edge->getDestination()->getKey());
                edge->setFlow(edge->getFlow() + y);
            } else if (flow_edge->getDirection() == Direction::BACKWARD) {
                edge = n->getEdge(flow_edge->getDestination()->getKey(), flow_edge->getOrigin()->getKey());
                edge->setFlow(edge->getFlow() - y);
            }
        }
        delete gf;
    }

    n->deleteNode(super_sink);
    n->deleteNode(super_source);

    // calculate cost minimal flow and calculate outgoing and incoming balances
    std::vector<double> bStrich(n->getAllNodes().size(), 0.0);

    for (const auto &element: n->getAllEdges()) {
        for (const auto &edge: element.second) {
            // calculate cost minimal flow
            value += edge->getCost() * edge->getFlow();

            //std::cout << edge << std::endl;

            // calculate outgoing and incoming balances
            bStrich[edge->getOrigin()->getKey()] += edge->getFlow();
            bStrich[edge->getDestination()->getKey()] -= edge->getFlow();
        }
    }

    // check if outgoing and incoming balances are even
    for (const auto &node: n->getAllNodes()) {
        if (node->getBalance() != bStrich[node->getKey()]) {
            std::cout << "source or sink not balanced!" << std::endl;
            return INFINITY;
        }
    }
    return value;
}

std::vector<Edge *> Algorithm::buildNegativeCycleFrom(Graph<Edge> *graph) {
    for (auto &element: graph->getAllEdges()) {
        for (auto &edge: element.second) {
            if (checkForCycle(edge)) {
                return getCyclePath(edge, graph);
            }
        }
    }
    return {};
}

bool Algorithm::checkForCycle(Edge *edge) {
    // check if edge lays inside negative cycle -> possible candidate
    Node *edgeA = edge->getOrigin();
    double newDistance = this->dist[edgeA->getKey()] + edge->getCost();
    Node *edgeB = edge->getDestination();
    return newDistance < this->dist[edgeB->getKey()];
}

std::vector<Edge *> Algorithm::getCyclePath(Edge *edge, Graph<Edge> *graph) {
    // find last node of negative cycle (node that gets back to our start node)
    Node *start = edge->getOrigin();
    for (int i = 0; i < graph->getNodeSize(); ++i) {
        Node *predecessor = this->pred[start->getKey()];
        if (predecessor != start && predecessor != nullptr) {
            start = predecessor;
        } else {
            break;
        }
    }

    std::vector<Edge *> cycle;
    Node *predecessor = nullptr;
    Node *current = start;

    // from start to last
    while (true) {
        predecessor = this->pred[current->getKey()];
        cycle.push_back(graph->getEdge(predecessor->getKey(), current->getKey()));

        if (predecessor == start) {
            return cycle;
        }
        current = predecessor;
    }
}


double Algorithm::successiveShortestPath() {
    double value = 0;
    Graph<Edge> *n = this->graph;
    Graph<Edge> *residual = convert_to_residual(n);

    std::vector<double> bStrich(n->getAllNodes().size(), 0.0);

    // step 1
    // calculate flow
    for (auto &e: n->getAllEdges()) {
        for (auto &i: e.second) {
            i->setFlow(i->getCost() < 0.0 ? i->getCapacity() : 0.0);
        }
    }

    // calculate bStrich
    for (auto &e: n->getAllEdges()) {
        for (auto &i: e.second) {
            Node *origin = n->getNode(i->getOrigin()->getKey());
            Node *destination = n->getNode(i->getDestination()->getKey());

            bStrich[origin->getKey()] += i->getFlow();
            bStrich[destination->getKey()] -= i->getFlow();
        }
    }

    bool end = false;
    while (!end) {
        // calculate sources and sink
        std::vector<Node *> source;
        std::vector<Node *> sink;

        for (const auto &node: n->getAllNodes()) {
            if (node->getBalance() - bStrich[node->getKey()] > 0.0) {
                source.push_back(node);
            }
            if (node->getBalance() - bStrich[node->getKey()] < 0.0) {
                sink.push_back(node);
            }
        }

        if (source.empty() && sink.empty()) {
            // there is no b-flow -> done
            std::cout << "\n";
            for (const auto &element: n->getAllEdges()) {
                for (const auto &edge: element.second) {
                    // calculate cost minimal flow
                    value += edge->getCost() * edge->getFlow();
                }
            }
            for (int i = 0; i < bStrich.size(); i++) {
                std::cout << i << " : " << bStrich[i] << "\n";
            }

            end = true;
            continue;
        } else if (source.empty() || sink.empty()) {
            // network not large enough
            return INFINITY;
        }

        for (auto &src: source) {
            bool sink_found = false;
            for (auto &s: sink) {
                // step 3
                residual = convert_to_residual(n);
                mooreBellmanFord(src->getKey(), residual);
                double minCapacity = INFINITY;
                Node *tmp = s;
                std::vector<Edge *> way;

                if (pred[tmp->getKey()] == nullptr) continue;
                sink_found = true;
                do {
                    int key1 = pred[tmp->getKey()]->getKey();
                    int key2 = tmp->getKey();
                    Edge *e = residual->getEdge(key1, key2);
                    way.push_back(e);
                    tmp = pred[tmp->getKey()];
                    Edge *n_edge;
                    if (e->getDirection() == Direction::FORWARD)
                        n_edge = n->getEdge(key1, key2);
                    else
                        n_edge = n->getEdge(key2, key1);
                    minCapacity = e->getFlow() < minCapacity ? e->getFlow() : minCapacity;
                } while (tmp->getKey() != src->getKey());


                double minSourceBalance = src->getBalance() - bStrich[src->getKey()];
                double minSinkBalance = bStrich[s->getKey()] - s->getBalance();

                double gamma = std::min(std::min(minCapacity, minSourceBalance), minSinkBalance);

                bStrich[src->getKey()] += gamma;
                bStrich[s->getKey()] -= gamma;

                for (auto &e: way) {
                    Edge *n_edge = nullptr;
                    if (e->getDirection() == Direction::FORWARD) {
                        n_edge = n->getEdge(e->getOrigin()->getKey(), e->getDestination()->getKey());
                        n_edge->setFlow(n_edge->getFlow() + gamma);
                    } else {
                        n_edge = n->getEdge(e->getDestination()->getKey(), e->getOrigin()->getKey());
                        n_edge->setFlow(n_edge->getFlow() - gamma);
                    }
                }
            }
            if (!sink_found) return INFINITY;
        }
    }
    return value;
}

Graph<Edge> *Algorithm::getGraph() const {
    return this->graph;
}
