//
// Created by plcla on 7/17/2022.
//

#include <iostream>
#include "Tree.h"

Tree::Tree() {
    this->root = new Node;
}

Tree::Tree(const int32_t valOfRoot) {
    this->root = new Node;
    this->root->val = valOfRoot;
}

Node* Tree::getRoot() {
    return this->root;
}

Node* Tree::searchForViableInsert(Node* rootNode, Node &nodeToInsert) {
    if (rootNode == nullptr) {
        rootNode = &nodeToInsert;
        return rootNode;
    }

    if (nodeToInsert.val < rootNode->val) {
        if (rootNode->leftChild == nullptr)
            return rootNode;
        else
            return searchForViableInsert(rootNode->leftChild, nodeToInsert);
    }
    else {
        if (rootNode->rightChild == nullptr)
            return rootNode;
        else
            return searchForViableInsert(rootNode->rightChild, nodeToInsert);
    }
}

void Tree::insertNode(const int32_t valToInsert) {
    Node* newNode = new Node;
    newNode->val = valToInsert;

    Node* parentNode = searchForViableInsert(this->root, *newNode);
    if (valToInsert < parentNode->val)
        parentNode->leftChild = newNode;
    else if (valToInsert > parentNode->val)
        parentNode->rightChild = newNode;
    else {
        std::cout << "Error: Could not insert; no duplicates allowed." << std::endl;
        return;
    }
}

Node* Tree::searchForNode(Node* rootNode, const int32_t valToSearchFor) {
    if (rootNode->val == valToSearchFor)
        return rootNode;
    else if (valToSearchFor < rootNode->val)
        return searchForNode(rootNode->leftChild, valToSearchFor);
    else if (valToSearchFor > rootNode->val)
        return searchForNode(rootNode->rightChild, valToSearchFor);
    else
        return nullptr;
}

int32_t Tree::getHeight(Node* rootNode) {
    static int32_t currHeight = 1, maxHeight = 1;

    if (rootNode->leftChild == nullptr && rootNode->rightChild == nullptr) {
        if (currHeight > maxHeight)
            maxHeight = currHeight;
        currHeight--;
        return maxHeight;
    }

    if (rootNode->leftChild != nullptr) {
        currHeight++;
        getHeight(rootNode->leftChild);
    }
    if (rootNode->rightChild != nullptr) {
        currHeight++;
        getHeight(rootNode->rightChild);
    }

    return maxHeight - 1;
}

void Tree::printSpaces(const int32_t spacesToPrint) {
    for (int32_t spacesPrinted = 0; spacesPrinted <= spacesToPrint; spacesPrinted++)
        std::cout << " ";
}

void Tree::printTree(Node* rootNode) {
    static int32_t numSpaces = 0;

    if (rootNode->leftChild == nullptr && rootNode->rightChild == nullptr) {
        printSpaces(numSpaces);
        std::cout << rootNode->val << std::endl;
        return;
    }

    printSpaces(numSpaces);
    std::cout << rootNode->val << std::endl;
    if (rootNode->leftChild != nullptr) {
        numSpaces++;
        printTree(rootNode->leftChild);
        numSpaces--;
    }
    if (rootNode->rightChild != nullptr) {
        numSpaces++;
        printTree(rootNode->rightChild);
        numSpaces--;
    }
}
