//
// Created by plcla on 4/5/2022.
//

#include "LinkedList.h"
#include <iostream>
#include <cassert>

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::~LinkedList() {
    Node* linkedListCopy = head;
    while (linkedListCopy) {
        Node* nextNodeCopy = linkedListCopy->next;
        delete linkedListCopy;
        linkedListCopy = nextNodeCopy;
    }
}

Node& LinkedList::traverseList(int index) {
    Node* linkedListCopy = head;
    int currIndex = 0;

    while (linkedListCopy) {
        if (currIndex == index)
            break;
        linkedListCopy = linkedListCopy->next;
        currIndex++;
    }

    return *linkedListCopy;
}

int LinkedList::getLengthOfList() {
    Node* linkedListCopy = head;
    int length = 1;

    while (linkedListCopy) {
        linkedListCopy = linkedListCopy->next;
        length++;
    }

    return length;
}

void LinkedList::insertNode(int data, int index) {
    Node* nodeToAdd = new Node;
    nodeToAdd->data = data;

    if (index == 0) {
        nodeToAdd->next = head;
        head = nodeToAdd;
        return;
    }

    const int length = getLengthOfList();
    assert((index > 0) && (index <= length));

    nodeToAdd->next = &traverseList(index);
    traverseList(index - 1).next = nodeToAdd;

    return;
}

void LinkedList::deleteNode(int index) {
    Node* pointerToPreviousHead;
    const int len = getLengthOfList();

    if (index == 0) {
        pointerToPreviousHead = head;
        head = head->next;
        delete pointerToPreviousHead;
        return;
    }

    assert((index > 0) && (index <= len));
    pointerToPreviousHead = &traverseList(index);
    traverseList(index - 1).next = pointerToPreviousHead->next;
    delete pointerToPreviousHead;

    return;
}

void LinkedList::printList() {
    Node* linkedListCopy = head;
    while (linkedListCopy) {
        std::cout << linkedListCopy->data << " --> ";
        linkedListCopy = linkedListCopy->next;
    }
    std::cout << std::endl;
}
