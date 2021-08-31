#include "Graph/node.h"

Node::Node(int key, double balance) : key(key), balance(balance) {}

std::ostream &operator<<(std::ostream &s, const Node &node) {
    return s << node.key;
}


std::ostream &operator<<(std::ostream &s, const Node *node) {
    return s << node->key;
}
