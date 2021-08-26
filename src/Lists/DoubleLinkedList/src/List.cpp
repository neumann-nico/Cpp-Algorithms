#include <DoubleLinkedList/List.h>
#include <string>
#include <iostream>

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
void DoubleLinkedList<T>::addItemFront(T value) {
    auto *node = new Node<T>(value);
    if (this->isEmpty()) {
        this->head = node;
        this->tail = node;
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
        this->tail = node;
    } else {
        this->tail->setNext(node);
        node->setPrevious(this->tail);
        this->tail = node;
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
            this->tail = nullptr;
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
                if (temp == this->tail){
                    if (temp->getNext() != nullptr) this->tail = temp->getNext();
                    else this->tail = temp->getPrevious();
                }
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
    auto *temp = this->tail;
    while (temp != nullptr) {
        std::cout << temp->getValue();
        if (temp->getPrevious() != nullptr) std::cout << ", ";
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
void DoubleLinkedList<T>::reverse() {
    if (this->size <= 1) return;

    auto *temp = this->head;
    auto *temp2 = this->tail;
    for (int i=0; i < (this->size/2); ++i){
        T val = temp->getValue();
        temp->setValue(temp2->getValue());
        temp2->setValue(val);
        temp = temp->getNext();
        temp2 = temp2->getPrevious();
    }
}

template<typename T>
Node<T> *DoubleLinkedList<T>::getFirstItem() {
    return this->head;
}

template<typename T>
Node<T> *DoubleLinkedList<T>::getLastItem() {
    return this->tail;
}

template<typename T>
int DoubleLinkedList<T>::getSize() {
    return this->size;
}

template<typename T>
void DoubleLinkedList<T>::removeFirst() {
    if(this->isEmpty()) return;

    if (this->head->getNext() == nullptr){
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else{
        auto *temp = this->head->getNext();
        temp->setPrevious(nullptr);
        delete this->head;
        this->head = temp;
    }
}

template<typename T>
void DoubleLinkedList<T>::removeLast() {
    if(this->isEmpty()) return;

    if (this->head->getNext() == nullptr){
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        auto *temp = this->tail->getPrevious();
        temp->setNext(nullptr);
        delete this->tail;
        this->tail = temp;
    }
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