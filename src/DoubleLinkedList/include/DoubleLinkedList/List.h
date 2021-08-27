#pragma once

#include <vector>
#include "DoubleLinkedList/Node.h"

template<typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();

    ~DoubleLinkedList();

    void addItemFront(T value);

    void addItemBack(T value);

    void removeFirst();

    void removeLast();

    void removeItem(T item);

    void printList();

    void printReverseList();

    void reverse();

    std::vector<T> getVector();

    Node<T> *getFirstItem();

    Node<T> *getLastItem();

    bool isEmpty();

    int getSize();

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};
