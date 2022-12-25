//
// Created by plcla on 4/29/2022.
//

#ifndef DOUBLYLINKEDLISTSPRACTICE_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLISTSPRACTICE_DOUBLYLINKEDLIST_H

#include <cstdint>

typedef struct Node {
    int32_t value;
    Node* nextNode;
    Node* prevNode;
}Node;

class DoublyLinkedList {
private:
    Node* headNode;

    Node& createNode(int32_t data);

public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    Node& traverseListToIndex(int32_t index);
    void insertNode(int32_t data, int32_t index);
    void deleteNode(int32_t index);
    Node& reverseList();
    void printList();
};


#endif //DOUBLYLINKEDLISTSPRACTICE_DOUBLYLINKEDLIST_H
