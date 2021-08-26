#include "DoubleLinkedList/List.h"

int main() {
    DoubleLinkedList<int> list;
    list.printList();
    list.addItemFront(5);
    list.printList();
    list.addItemFront(6);
    list.printList();
    list.addItemBack(7);
    list.addItemFront(3);
    list.addItemBack(6);
    list.printList();
    list.removeItem(7);
    list.printList();

    return 0;
}
