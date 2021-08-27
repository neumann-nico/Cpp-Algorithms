#include <string>
#include "DoubleLinkedList/Node.h"

template<typename T>
Node<T>::Node(T value) : value(value), previous(nullptr), next(nullptr) {}

template<typename T>
T Node<T>::getValue() const {
    return this->value;
}

template<typename T>
Node<T> *Node<T>::getPrevious() const {
    return this->previous;
}

template<typename T>
Node<T> *Node<T>::getNext() const {
    return this->next;
}

template<typename T>
void Node<T>::setValue(T value) {
    this->value = value;
}

template<typename T>
void Node<T>::setPrevious(Node<T> *previous) {
    this->previous = previous;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next;
}

template
class Node<int>;

template
class Node<double>;

template
class Node<float>;

template
class Node<char>;

template
class Node<std::string>;