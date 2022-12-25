//
// Created by plcla on 7/17/2022.
//

#ifndef TREEPRACTICE_TREE_H
#define TREEPRACTICE_TREE_H

#include <cstdint>

typedef struct Node {
    int32_t val = 0;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
}Node;


class Tree {
private:
    void printSpaces(const int32_t spacesToPrint);

    Node* root = nullptr;

public:
    Tree();
    Tree(const int32_t valOfRoot);


    Node* getRoot();
    int32_t getHeight(Node* rootNode);
    void insertNode(const int32_t valToInsert);
    Node* searchForViableInsert(Node* rootNode, Node& nodeToInsert);
    Node* searchForNode(Node* rootNode, const int32_t valToSearchFor);
    void printTree(Node* rootNode);
};


#endif //TREEPRACTICE_TREE_H
