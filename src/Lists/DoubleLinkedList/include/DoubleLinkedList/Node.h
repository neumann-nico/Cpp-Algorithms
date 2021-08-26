#pragma once

template<typename T>
class Node {
public:
    explicit Node(T value);

    T getValue();

    Node<T> *getPrevious();

    Node<T> *getNext();

    void setValue(T value);

    void setPrevious(Node<T> *previous);

    void setNext(Node<T> *next);

private:
    T value;
    Node<T> *next;
    Node<T> *previous;
};
