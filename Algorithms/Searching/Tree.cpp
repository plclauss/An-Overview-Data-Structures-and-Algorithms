//
// Created by plcla on 9/14/2022.
//

#include <iostream>
#include "Tree.h"

Tree::Tree(int32_t rootVal, Node *left, Node *right) {
    Node* newRoot = new Node;
    this->root = newRoot;
    this->root->color = BLACK;
    this->root->nodeVal = rootVal;
    this->root->parentNode = nullptr;
    this->root->leftChild = left;
    this->root->rightChild = right;
}

Node* Tree::createRedNode(Node* parent, const int32_t& nodeVal) {
    Node* nodeToInsert = new Node;
    nodeToInsert->color = RED;
    nodeToInsert->nodeVal = nodeVal;
    nodeToInsert->parentNode = parent;
    nodeToInsert->leftChild = nullptr;
    nodeToInsert->rightChild = nullptr;

    return nodeToInsert;
}

Node* Tree::getRoot() {
    return this->root;
}

void Tree::leftRotate(Node* rotatingNode) {
    Node* replacementNode = rotatingNode->rightChild;

    replacementNode->parentNode = rotatingNode->parentNode;
    rotatingNode->rightChild = replacementNode->leftChild;
    if (rotatingNode->rightChild)
        rotatingNode->rightChild->parentNode = rotatingNode;
    replacementNode->leftChild = rotatingNode;

    if (!rotatingNode->parentNode) {
        this->root = replacementNode;
    }
    else if (rotatingNode == rotatingNode->parentNode->leftChild) {
        rotatingNode->parentNode->leftChild = replacementNode;
    }
    else
        rotatingNode->parentNode->rightChild = replacementNode;

    rotatingNode->parentNode = replacementNode;
}

void Tree::rightRotate(Node* rotatingNode) {
    Node* replacementNode = rotatingNode->leftChild;

    replacementNode->parentNode = rotatingNode->parentNode;
    rotatingNode->leftChild = replacementNode->rightChild;
    if (rotatingNode->leftChild)
        rotatingNode->leftChild->parentNode = rotatingNode;
    replacementNode->rightChild = rotatingNode;

    if (!rotatingNode->parentNode) {
        this->root = replacementNode;
    }
    else if (rotatingNode == rotatingNode->parentNode->leftChild) {
        rotatingNode->parentNode->leftChild = replacementNode;
    }
    else
        rotatingNode->parentNode->rightChild = replacementNode;

    rotatingNode->parentNode = replacementNode;
}

void Tree::fixInsertViolations(Node* violatingNode) {
    Node* p = violatingNode->parentNode;

    Node* gP = p->parentNode;
    if (!gP)
        return;

    Node* u;
    (p == gP->leftChild) ? u = gP->rightChild : u = gP->leftChild;

    while (p->color == RED) {
        // Case 1: Uncle is RED.
        if (u && u->color == RED) {
            // Recolor all but violatingNode.
            (p->color == RED) ? p->color = BLACK : p->color = RED;
            (gP->color == RED) ? gP->color = BLACK : gP->color = RED;
            u->color = BLACK;


            // Reset violatingNode.
            // New violatingNode = gP.
            violatingNode = gP;
        }
        // Case 2: Uncle is BLACK.
        else {
            // Sub-Case 1: Right Line Rotation
            if (p == gP->leftChild && violatingNode == p->leftChild) {
                rightRotate(gP);

                // Recolor
                (p->color == RED) ? p->color = BLACK : p->color = RED;
                (gP->color == RED) ? gP->color = BLACK : gP->color = RED;

                // New potential node violation.
                violatingNode = p;
            }
            // Sub-Case 2: Left Line Rotation
            else if (p == gP->rightChild && violatingNode == p->rightChild) {
                leftRotate(gP);

                // Recolor
                (p->color == RED) ? p->color = BLACK : p->color = RED;
                (gP->color == RED) ? gP->color = BLACK : gP->color = RED;

                // New potential node violation.
                violatingNode = p;
            }
            // Sub-Case 3: Left Triangle Rotation
            else if (p == gP->leftChild && violatingNode == p->rightChild) {
                leftRotate(p);

                // New potential violating node.
                    // Guaranteed node at new p's leftChild.
                violatingNode = p->leftChild;
            }
            // Sub-Case 4: Right Triangle Rotation
            else {
                rightRotate(p);

                // New potential violating node.
                    // Guaranteed node at new p's rightChild.
                violatingNode = p->rightChild;
            }
        }

        p = violatingNode->parentNode;
        if (!p)
            return;

        gP = p->parentNode;
        if (!gP)
            return;

        (p == gP->leftChild) ? u = gP->rightChild : u = gP->leftChild;
    }
}

void Tree::insertNode(Node *rootNode, const int32_t& valToInsert) {
    if (rootNode == nullptr) {
        this->root = createRedNode(nullptr, valToInsert);
        this->root->color = BLACK;
        return;
    }

    if (valToInsert == rootNode->nodeVal) {
        std::cout << "Invalid input; " << valToInsert << " already exists within the tree." << std::endl;
        return;
    }
    else if (valToInsert < rootNode->nodeVal) {
        if (rootNode->leftChild == nullptr) {
            rootNode->leftChild = createRedNode(rootNode, valToInsert);
            fixInsertViolations(rootNode->leftChild);
        }
        else
            insertNode(rootNode->leftChild, valToInsert);
    }
    else {
        if (rootNode->rightChild == nullptr) {
            rootNode->rightChild = createRedNode(rootNode, valToInsert);
            fixInsertViolations(rootNode->rightChild);
        }
        else
            insertNode(rootNode->rightChild, valToInsert);
    }
}

void Tree::insert(const int32_t& valToInsert) {
    std::cout << "Inserting " << valToInsert << "." << std::endl;
    insertNode(this->root, valToInsert);
}

void Tree::printTreeAsVector(Node *currRoot) {
    std::vector<Node*> nodes;
    std::queue<Node*> bfsQueue;

    bfsQueue.push(currRoot);
    while (!bfsQueue.empty()) {
        Node* nodeAtFront = bfsQueue.front();
        bfsQueue.pop();

        if (nodeAtFront) {
            bfsQueue.push(nodeAtFront->leftChild);
            bfsQueue.push(nodeAtFront->rightChild);
        }
        nodes.push_back(nodeAtFront);
    }

    std::cout << "[";
    for (int i = 0; i < nodes.size(); i++) {
        if (!nodes.at(i)) {
            if (i == nodes.size() - 1) {
                std::cout << "null";
                break;
            }
            std::cout << "null, ";
        }
        else {
            if (i == nodes.size() - 1) {
                std::cout << nodes.at(i)->nodeVal;
                break;
            }
            std::cout << nodes.at(i)->nodeVal << ", ";
        }
    }
    std::cout << "]";
}

void Tree::printTree() {
    return printTreeAsVector(this->root);
}
