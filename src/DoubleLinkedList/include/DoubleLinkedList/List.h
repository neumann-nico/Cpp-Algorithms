#pragma once

#include <vector>
#include "DoubleLinkedList/Node.h"

template<typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();

    DoubleLinkedList(const DoubleLinkedList &other);

    DoubleLinkedList<T> &operator=(const DoubleLinkedList<T> &other);

    ~DoubleLinkedList();

    void addItemFront(T value);

    void addItemBack(T value);

    void removeFirst();

    void removeLast();

    void removeItem(T item);

    void removeAllNodes();

    void printList() const;

    void printReverseList() const;

    void reverse();

    std::vector<T> getVector() const;

    Node<T> *getFirstItem() const;

    Node<T> *getLastItem() const;

    bool isEmpty() const;

    int getSize() const;

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};
