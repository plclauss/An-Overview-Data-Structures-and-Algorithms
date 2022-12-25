//
// Created by plcla on 9/14/2022.
//

#ifndef SEARCHINGINTRO_TREE_H
#define SEARCHINGINTRO_TREE_H

#include <cstdint>
#include <vector>
#include <queue>

enum Color {RED, BLACK};
typedef struct Node {
    Color color;
    int32_t nodeVal;
    Node* parentNode;
    Node* leftChild;
    Node* rightChild;
}Node;

enum RotateType {TRIANGLE, LINE};
class Tree {
private:
    Node* root = nullptr;

    Node* createRedNode(Node* parent, const int32_t& nodeVal);
    void insertNode(Node* rootNode, const int32_t& valToInsert);
    void leftRotate(Node* rotatingNode);
    void rightRotate(Node* rotatingNode);
    void fixInsertViolations(Node* violatingNode);
    void printTreeAsVector(Node* currRoot);

public:
    Tree() { this->root = nullptr; }
    Tree(int32_t rootVal, Node* left, Node* right);

    Node* getRoot();
    void insert(const int32_t& valToInsert);
    void printTree();
};


#endif //SEARCHINGINTRO_TREE_H
