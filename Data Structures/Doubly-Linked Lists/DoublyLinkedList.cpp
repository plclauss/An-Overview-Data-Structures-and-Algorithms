//
// Created by plcla on 4/29/2022.
//

#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    this->headNode = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (this->headNode->nextNode) {
        this->headNode = this->headNode->nextNode;
        delete this->headNode->prevNode;
    }
    delete this->headNode;
}

Node& DoublyLinkedList::reverseList() {
    Node* previous = (Node*)malloc(sizeof(Node));

    while (this->headNode->nextNode) {
        previous = this->headNode->prevNode;
        this->headNode->prevNode = this->headNode->nextNode;
        this->headNode->nextNode = previous;

        this->headNode = this->headNode->prevNode;
    }
    this->headNode->nextNode = this->headNode->prevNode;
    this->headNode->prevNode = nullptr;

    free(previous);
    return *this->headNode;
}

Node& DoublyLinkedList::traverseListToIndex(int32_t index) {
    Node* headCopy = this->headNode;
    uint32_t i = 0;

    while (headCopy && i != index) {
        headCopy = headCopy->nextNode;
        i++;
    }

    return *headCopy;
}

Node& DoublyLinkedList::createNode(int32_t data) {
    Node* newNode = new Node;
    newNode->value = data;
    newNode->nextNode = nullptr;
    newNode->prevNode = nullptr;

    return *newNode;
}

void DoublyLinkedList::insertNode(int32_t data, int32_t index) {
    Node* nodeToInsert = &createNode(data);

    if (!this->headNode) {
        nodeToInsert->value = data;
        nodeToInsert->nextNode = nullptr;
        nodeToInsert->prevNode = nullptr;

        this->headNode = nodeToInsert;

        return;
    }

    Node* nodeAtIndex = &traverseListToIndex(index);
    if (!nodeAtIndex) {
        Node* nodeBeforeIndex = &traverseListToIndex(index - 1);
        nodeBeforeIndex->nextNode = nodeToInsert;
        nodeToInsert->prevNode = nodeBeforeIndex;
        nodeToInsert->nextNode = nullptr;

        return;
    }

    nodeToInsert->prevNode = nodeAtIndex->prevNode;
    nodeAtIndex->prevNode = nodeToInsert;
    nodeToInsert->nextNode = nodeAtIndex;
    nodeToInsert->prevNode->nextNode = nodeToInsert;
}

void DoublyLinkedList::deleteNode(int32_t index) {
    Node* nodeToDelete = &traverseListToIndex(index);

    if (nodeToDelete) {
        nodeToDelete->nextNode->prevNode = nodeToDelete->prevNode;
        nodeToDelete->prevNode->nextNode = nodeToDelete->nextNode;

        delete nodeToDelete;
    }
}

void DoublyLinkedList::printList() {
    Node* headCopy = this->headNode;

    while (headCopy) {
        std::cout << headCopy->value << " ";
        headCopy = headCopy->nextNode;
    }
    std::cout << std::endl;
}
