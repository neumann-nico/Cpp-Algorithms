#pragma once

#include <vector>
#include "DoubleLinkedList/Node.h"

template<typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();

    void addItemFront(T value);

    void addItemBack(T value);

    void removeItem(T item);

    void printList();

    void printReverseList();

    std::vector<T> getVector();

    Node<T> *getFirstItem();

    Node<T> *getLastItem();

    bool isEmpty();

    int getSize();

private:
    Node<T> *head;
    int size;
};
