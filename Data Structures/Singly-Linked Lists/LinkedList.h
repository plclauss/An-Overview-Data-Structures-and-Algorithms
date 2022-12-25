//
// Created by plcla on 4/5/2022.
//

#ifndef LINKEDLISTSPRACTICE_LINKEDLIST_H
#define LINKEDLISTSPRACTICE_LINKEDLIST_H

typedef struct Node {
    int data;
    Node* next;
}Node;

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insertNode(int data, int index);
    void deleteNode(int index);
    int getLengthOfList();
    void printList();
private:
    Node* head;

    Node& traverseList(int index);
};

#endif //LINKEDLISTSPRACTICE_LINKEDLIST_H
