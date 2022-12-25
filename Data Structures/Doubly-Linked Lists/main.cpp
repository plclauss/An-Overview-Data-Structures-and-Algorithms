#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    auto listHead = new DoublyLinkedList();

    for (int i = 0; i < 5; i++)
        listHead->insertNode(i + 1, i);

    listHead->printList();

    listHead->reverseList();

    listHead->printList();

    delete listHead;

    return 0;
}
