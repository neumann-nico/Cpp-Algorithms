#pragma once

template<typename T>
class Node {
public:
    explicit Node(T value);

    T getValue() const;

    Node<T> *getPrevious() const;

    Node<T> *getNext() const;

    void setValue(T value);

    void setPrevious(Node<T> *previous);

    void setNext(Node<T> *next);

private:
    T value;
    Node<T> *next;
    Node<T> *previous;
};
