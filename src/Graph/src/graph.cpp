#include "Graph/graph.h"
#include <filesystem>

template
class Graph<Edge>;

template
class Graph<FlowEdge>;

template<class T>
Graph<T>::Graph() {

}

template<class T>
Graph<T>::Graph(std::string inputfile) {
    process(inputfile);
}

template<class T>
Graph<T>::~Graph() {
    if (this->nodes.empty() && this->edges.empty()) return;

    std::list<T *> edge_list;
    for (auto &element: this->edges) {
        for (auto &edge: element.second) {
            edge_list.push_back(edge);
        }
    }

    edge_list.sort();
    edge_list.unique();
    for (auto &edge: edge_list) {
        delete edge;
    }

    for (auto &node: this->nodes) {
        delete node;
    }

    this->edges.clear();
    this->edge_association.clear();
    this->nodes.clear();
}

template<class T>
bool Graph<T>::process(std::string inputfile) {
    assert(std::filesystem::exists(inputfile));
    if (!this->edges.empty() && !this->edges.empty()) {
        std::list<T *> edge_list;
        for (const auto &element: this->edges) {
            for (auto iter = element.second.begin(); iter != element.second.end(); ++iter) {
                T *edge = *iter;
                edge_list.push_back(edge);
            }
        }

        edge_list.sort();
        edge_list.unique();
        for (const auto &edge: edge_list) {
            delete edge;
        }

        for (const auto &node: this->nodes) {
            delete node;
        }

        this->edges.clear();
        this->edge_association.clear();
        this->nodes.clear();
    }

    std::ifstream file = std::ifstream(inputfile);
    char delimiter = '\t';
    std::string filename, line, field;
    try {
        getline(file, line);
        assert(!line.empty());

        int node_size = stoi(line);
        this->nodes.reserve(node_size);

        // process nodes
        for (int i = 0; i < node_size; ++i) {
            Node *node = new Node(i);
            this->nodes.push_back(node);
        }

        // check type of graph
        getline(file, line);
        int pos = line.find(delimiter);
        bool b_graph = pos >= line.size();

        if (b_graph) {
            // read balance values
            for (int i = 0; i < node_size; ++i) {
                double balance = stod(line);
                this->nodes[i]->setBalance(balance);
                getline(file, line);

            }
        }


        // process edges
        double cost = 1.0;
        double capacity = 0.0;
        do {
            std::stringstream ss(line);

            std::getline(ss, field, delimiter);
            Node *node1 = this->nodes[stoi(field)];

            std::getline(ss, field, delimiter);
            Node *node2 = this->nodes[stoi(field)];

            if (!ss.eof()) {
                std::getline(ss, field, delimiter);
                cost = stod(field);
            }
            if (!ss.eof()) {
                std::getline(ss, field, delimiter);
                capacity = stod(field);
            } else {
                capacity = cost;
            }

            T *edge = new T(node1, node2, cost, Direction::FORWARD);
            edge->setCapacity(capacity);
            this->edges[node1].push_back(edge);
            //this->edges[node2].push_back(edge);
            this->edge_association[std::make_pair(node1, node2)] = edge;
            //this->edge_association[std::make_pair(node2, node1)] = edge;
        } while (getline(file, line));
    } catch (std::exception e) {
        std::cerr << "Error in processing graph!" << std::endl;
        return false;
    }

    /*for(int i=0; i<nodes.size(); ++i){
        std::cout << nodes[i] << ":" << nodes[i]->getBalance() << std::endl;
    }

    for(auto &element : edges){
        for(auto &edge : element.second){
            std::cout << edge << std::endl;
        }
    }*/

    file.close();
    return true;
}

template<class T>
void Graph<T>::resetVisited() {
    for (auto const &node: this->nodes) {
        node->setVisited(false);
    }

    for (const auto &element: this->edges) {
        for (auto iter = element.second.begin(); iter != element.second.end(); ++iter) {
            T *edge = *iter;
            edge->setVisited(false);
        }
    }
}

template<class T>
bool Graph<T>::allVisited() {
    for (auto const &node: this->nodes) {
        if (!node->getVisited())
            return false;
    }
    return true;
}

template<class T>
int Graph<T>::getNodeSize() {
    return this->nodes.size();
}

template<class T>
int Graph<T>::getEdgeSize() {
    return this->edges.size();
}

template<class T>
Node *Graph<T>::getNode(int key) {
    return this->nodes[key];
}

template<class T>
std::vector<Node *> Graph<T>::getAllNodes() {
    return this->nodes;
}

template<class T>
T *Graph<T>::getEdge(Node *origin, Node *destination) {
    return this->edge_association[std::make_pair(origin, destination)];
}

template<class T>
T *Graph<T>::getEdge(int origin, int destination) {
    Node *origin_ = this->getNode(origin);
    Node *destination_ = this->getNode(destination);
    return this->edge_association[std::make_pair(origin_, destination_)];
}

template<class T>
void Graph<T>::updateEdge(Node *node1, Node *node2, double cost, int direction, double capacity) {
    T *edge = this->getEdge(node1, node2);
    if (edge != nullptr) {
        edge->setCost(cost);
        edge->setCapacity(capacity);
        edge->setDirection(direction);
    } else {
        edge = new T(node1, node2, cost, direction);
        this->edges[node1].push_back(edge);
        this->edge_association[std::make_pair(node1, node2)] = edge;
    }
}

template<class T>
void Graph<T>::deleteNode(Node *node) {
    for (auto &element: this->getAllEdges()) {
        for (auto &edge: element.second) {
            if (edge->getOrigin() == node || edge->getDestination() == node) {
                this->deleteEdge(edge->getOrigin(), edge->getDestination());
            }
        }
    }
    delete this->nodes[node->getKey()];
    nodes.resize(nodes.size() - 1);
}

template<class T>
void Graph<T>::deleteEdge(Node *node1, Node *node2) {
    T *edge = this->getEdge(node1, node2);

    if (edge != nullptr) {
        this->edges[node1].erase(std::remove(this->edges[node1].begin(), this->edges[node1].end(), edge),
                                 this->edges[node1].end());
        this->edge_association.erase(std::make_pair(node1, node2));
        delete edge;
    }
}

template<class T>
void Graph<T>::updateNode(Node *node) {
    if (node->getKey() < this->nodes.size()) {
        delete this->nodes[node->getKey()];
        this->nodes[node->getKey()] = node;
    } else {
        nodes.resize(node->getKey() + 1);
        nodes[node->getKey()] = node;
    }
}

template<class T>
std::vector<T *> Graph<T>::getEdges(int key) {
    return this->getEdges(this->nodes[key]);
}

template<class T>
std::vector<T *> Graph<T>::getEdges(Node *node) {
    return this->edges[node];
}

template<class T>
std::map<Node *, std::vector<T *>> Graph<T>::getAllEdges() {
    return this->edges;
}

Graph<FlowEdge> *convert_graph(Graph<Edge> *from) {
    Graph<FlowEdge> *graph = new Graph<FlowEdge>();

    int node_size = from->getNodeSize();
    graph->nodes.reserve(node_size);

    for (int i = 0; i < node_size; ++i) {
        Node *node = new Node(i, from->nodes[i]->getBalance());
        graph->nodes.push_back(node);
    }

    for (const auto &element: from->getAllEdges()) {
        for (const auto &edge: element.second) {
            Node *node1 = graph->getNode(edge->getOrigin()->getKey());
            Node *node2 = graph->getNode(edge->getDestination()->getKey());

            if (graph->getEdge(node1, node2) != nullptr) continue;

            FlowEdge *flowedge = new FlowEdge(node1, node2, edge->getCost(), Direction::FORWARD);
            //flowedge->setCapacity(edge->getCapacity());
            graph->edges[node1].push_back(flowedge);
            graph->edge_association[std::make_pair(node1, node2)] = flowedge;
        }
    }

    return graph;
}

Graph<Edge> *convert_graph(Graph<FlowEdge> *from) {
    Graph<Edge> *graph = new Graph<Edge>();

    int node_size = from->getNodeSize();
    graph->nodes.reserve(node_size);

    for (int i = 0; i < node_size; ++i) {
        Node *node = new Node(i, from->nodes[i]->getBalance());
        graph->nodes.push_back(node);
    }

    for (const auto &element: from->getAllEdges()) {
        for (const auto &flowedge: element.second) {
            Node *node1 = graph->getNode(flowedge->getOrigin()->getKey());
            Node *node2 = graph->getNode(flowedge->getDestination()->getKey());

            // forward
            double cost = flowedge->getCapacity() - flowedge->getFlow();
            if (cost > 0.0) {
                //std::cout << Direction::FORWARD << std::endl;
                Edge *edge = new Edge(node1, node2, cost, Direction::FORWARD);
                graph->edges[node1].push_back(edge);
                graph->edge_association[std::make_pair(node1, node2)] = edge;
            }

            // backward
            if (flowedge->getFlow() > 0.0) {
                //std::cout << Direction::BACKWARD << std::endl;
                Edge *edge = new Edge(node2, node1, flowedge->getFlow(), Direction::BACKWARD);
                graph->edges[node2].push_back(edge);
                graph->edge_association[std::make_pair(node2, node1)] = edge;
            }
        }
    }

    return graph;
}

Graph<Edge> *convert_to_residual(Graph<Edge> *from) {
    Graph<Edge> *graph = new Graph<Edge>();

    int node_size = from->getNodeSize();
    graph->nodes.reserve(node_size);

    for (int i = 0; i < node_size; ++i) {
        Node *node = new Node(i, from->nodes[i]->getBalance());
        graph->nodes.push_back(node);
    }

    for (const auto &element: from->getAllEdges()) {
        for (const auto &flowedge: element.second) {
            Node *node1 = graph->getNode(flowedge->getOrigin()->getKey());
            Node *node2 = graph->getNode(flowedge->getDestination()->getKey());

            // forward
            double cost = flowedge->getCapacity() - flowedge->getFlow();
            if (cost > 0.0) {
                Edge *edge = new Edge(node1, node2, cost, Direction::FORWARD);
                edge->setCapacity(flowedge->getCapacity());
                edge->setCost(flowedge->getCost());
                edge->setFlow(cost);
                graph->edges[node1].push_back(edge);
                graph->edge_association[std::make_pair(node1, node2)] = edge;
            }

            // backward
            if (flowedge->getFlow() > 0.0) {
                Edge *edge = new Edge(node2, node1, flowedge->getFlow(), Direction::BACKWARD);
                edge->setCapacity(flowedge->getCapacity());
                edge->setCost(-flowedge->getCost());
                edge->setFlow(flowedge->getFlow());
                graph->edges[node2].push_back(edge);
                graph->edge_association[std::make_pair(node2, node1)] = edge;
            }
        }
    }

    return graph;
}
