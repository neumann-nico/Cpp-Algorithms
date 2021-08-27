#include <DoubleLinkedList/List.h>
#include <string>
#include <iostream>

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList &other) {
    this->head = new Node<T>(*other.head);
    auto *temp_other = other.head->getNext();
    auto *temp_this = this->head;
    while (temp_other != nullptr){
        auto *node = new Node<T>(*temp_other);
        temp_this->setNext(node);
        node->setPrevious(temp_this);
        temp_this = temp_this->getNext();
        temp_other = temp_other->getNext();
    }
    this->size = other.size;
}

template<typename T>
DoubleLinkedList<T> &DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &other) {
    this->removeAllNodes();

    this->head = new Node<T>(*other.head);
    auto *temp_other = other.head->getNext();
    auto *temp_this = this->head;
    while (temp_other != nullptr){
        auto *node = new Node<T>(*temp_other);
        temp_this->setNext(node);
        node->setPrevious(temp_this);
        temp_this = temp_this->getNext();
        temp_other = temp_other->getNext();
    }
    this->size = other.size;

    return *this;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    this->removeAllNodes();
}

template<typename T>
void DoubleLinkedList<T>::addItemFront(T value) {
    auto *node = new Node<T>(value);
    if (this->isEmpty()) {
        this->tail = node;
    } else {
        this->head->setPrevious(node);
        node->setNext(this->head);
    }
    this->head = node;
    ++this->size;
}

template<typename T>
void DoubleLinkedList<T>::addItemBack(T value) {
    auto *node = new Node<T>(value);
    if (this->isEmpty()) {
        this->head = node;
    } else {
        this->tail->setNext(node);
        node->setPrevious(this->tail);
    }
    this->tail = node;
    ++this->size;
}

template<typename T>
void DoubleLinkedList<T>::removeItem(T value) {
    if (this->isEmpty()) return;

    if (this->head->getValue() == value) {
        this->removeFirst();
    } else {
        auto *temp = this->head->getNext();
        while (temp != nullptr) {
            if (temp->getValue() == value) {
                if (temp == this->tail) {
                    this->removeLast();
                } else {
                    auto *temp2 = temp->getPrevious();
                    if (temp->getPrevious() != nullptr) temp->getPrevious()->setNext(temp->getNext());
                    if (temp->getNext() != nullptr) temp->getNext()->setPrevious(temp2);
                    delete temp;
                    --this->size;
                }
                return;
            }
            temp = temp->getNext();
        }
    }
}

template<typename T>
void DoubleLinkedList<T>::printList() const{
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
void DoubleLinkedList<T>::printReverseList() const{
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
std::vector<T> DoubleLinkedList<T>::getVector() const{
    std::vector<T> vec(this->size);
    auto *temp = this->head;
    for (auto &item: vec) {
        item = temp->getValue();
        temp = temp->getNext();
    }
    return vec;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const{
    return this->head == nullptr;
}

template<typename T>
void DoubleLinkedList<T>::reverse() {
    if (this->size <= 1) return;

    auto *temp = this->head;
    auto *temp2 = this->tail;
    for (int i = 0; i < (this->size / 2); ++i) {
        T val = temp->getValue();
        temp->setValue(temp2->getValue());
        temp2->setValue(val);
        temp = temp->getNext();
        temp2 = temp2->getPrevious();
    }
}

template<typename T>
Node<T> *DoubleLinkedList<T>::getFirstItem() const{
    return this->head;
}

template<typename T>
Node<T> *DoubleLinkedList<T>::getLastItem() const{
    return this->tail;
}

template<typename T>
int DoubleLinkedList<T>::getSize() const{
    return this->size;
}

template<typename T>
void DoubleLinkedList<T>::removeFirst() {
    if (this->isEmpty()) return;

    auto *temp = this->head->getNext();
    delete this->head;
    this->head = temp;
    --this->size;
    if (this->size == 0) {
        this->tail = nullptr;
    } else {
        temp->setPrevious(nullptr);
    }
}

template<typename T>
void DoubleLinkedList<T>::removeLast() {
    if (this->isEmpty()) return;

    if (this->head->getNext() == nullptr) {
        this->removeFirst();
    } else {
        auto *temp = this->tail->getPrevious();
        temp->setNext(nullptr);
        delete this->tail;
        this->tail = temp;
        --this->size;
    }
}

template<typename T>
void DoubleLinkedList<T>::removeAllNodes() {
    while(this->head != nullptr) {
        auto &temp = this->head;
        this->head = this->head->getNext();
        delete temp;
    }
    this->head = nullptr;
    this->tail = nullptr;
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