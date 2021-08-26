#include <DoubleLinkedList/List.h>
#include <string>
#include <iostream>

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), size(0) {}

template<typename T>
void DoubleLinkedList<T>::addItemFront(T value) {
    auto *node = new Node<T>(value);
    if (this->isEmpty()) {
        this->head = node;
    } else {
        this->head->setPrevious(node);
        node->setNext(this->head);
        this->head = node;
    }
    ++this->size;
}

template<typename T>
void DoubleLinkedList<T>::addItemBack(T value) {
    auto *node = new Node<T>(value);
    if (this->isEmpty()) {
        this->head = node;
    } else {
        auto *last = this->getLastItem();
        last->setNext(node);
        node->setPrevious(last);
    }
    ++this->size;
}

template<typename T>
void DoubleLinkedList<T>::removeItem(T value) {
    if (this->isEmpty()) return;

    if (this->head->getValue() == value) {
        if (this->head->getNext() == nullptr) {
            delete this->head;
            --this->size;
            this->head = nullptr;
        } else {
            auto *temp = this->head->getNext();
            delete this->head;
            --this->size;
            this->head = temp;
            this->head->setPrevious(nullptr);
        }
    } else {
        auto *temp = this->head->getNext();
        while (temp != nullptr) {
            if (temp->getValue() == value) {
                auto *temp2 = temp->getPrevious();
                if (temp->getPrevious() != nullptr) temp->getPrevious()->setNext(temp->getNext());
                if (temp->getNext() != nullptr) temp->getNext()->setPrevious(temp2);
                delete temp;
                --this->size;
                return;
            }
            temp = temp->getNext();
        }
    }

}

template<typename T>
void DoubleLinkedList<T>::printList() {
    std::cout << "[";
    auto *temp = this->head;
    while (temp != nullptr) {
        std::cout << temp->getValue();
        if (temp->getNext() != nullptr) std::cout << ", ";
        temp = temp->getNext();
    }
    std::cout << "]" << std::endl;
}

template<typename T>
void DoubleLinkedList<T>::printReverseList() {
    std::cout << "[";
    auto *temp = this->getLastItem();
    while (temp->getPrevious() != nullptr) {
        std::cout << temp->getValue();
        if (temp->getPrevious() == nullptr) std::cout << ", ";
        temp = temp->getPrevious();
    }
    std::cout << "]" << std::endl;
}


template<typename T>
std::vector<T> DoubleLinkedList<T>::getVector() {
    std::vector<T> vec;
    auto *temp = this->head;
    while (temp != nullptr) {
        vec.push_back(temp->getValue());
        temp = temp->getNext();
    }
    return vec;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
    return this->head == nullptr;
}

template<typename T>
Node<T> *DoubleLinkedList<T>::getFirstItem() {
    return this->head;
}

template<typename T>
Node<T> *DoubleLinkedList<T>::getLastItem() {
    if (this->isEmpty()) return nullptr;

    auto *temp = this->head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }
    return temp;
}

template<typename T>
int DoubleLinkedList<T>::getSize() {
    return this->size;
}

template
class DoubleLinkedList<int>;

template
class DoubleLinkedList<double>;

template
class DoubleLinkedList<float>;

template
class DoubleLinkedList<char>;

template
class DoubleLinkedList<std::string>;