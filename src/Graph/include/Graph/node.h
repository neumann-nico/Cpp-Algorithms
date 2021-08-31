#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
public:
    Node(int key, double balance = 0.0);

    friend std::ostream &operator<<(std::ostream &, const Node &);

    friend std::ostream &operator<<(std::ostream &, const Node *);

    int getKey() const { return this->key; };

    int getVisited() const { return this->visited; };

    double getBalance() const { return this->balance; };

    void setKey(int key) { this->key = key; };

    void setVisited(bool visited) { this->visited = visited; };

    void setBalance(double balance) { this->balance = balance; };

private:
    int key;
    double balance;
    bool visited = false;
};

#endif // NODE_H
