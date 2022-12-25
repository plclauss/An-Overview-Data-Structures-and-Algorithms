//
// Created by plcla on 9/14/2022.
//

#include <iostream>
#include "SearchingAlgorithms.h"

int32_t SearchingAlgorithms::linearSearchNums(const std::vector<int32_t> &vec, const int32_t &key) {
    for (int index = 0; index < vec.size(); index++)
        if (vec[index] == key)
            return index;
    return -1;
}

void SearchingAlgorithms::mergeSortMerge(std::vector<int32_t> &vec, std::vector<int32_t> &left, std::vector<int32_t> &right) {
    auto replaceThis = vec.begin();
    auto leftIt = left.begin();
    auto rightIt = right.begin();

    // Compare which one's smaller
    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            *replaceThis = *leftIt;
            leftIt++;
        }
        else {
            *replaceThis = *rightIt;
            rightIt++;
        }

        replaceThis++;
    }

    // Get remaining
    while (leftIt != left.end()) {
        *replaceThis = *leftIt;
        replaceThis++; leftIt++;
    }
    while (rightIt != right.end()) {
        *replaceThis = *rightIt;
        replaceThis++; rightIt++;
    }
}

void SearchingAlgorithms::mergeSortNums(std::vector<int32_t> &vec) {
    if (vec.size() <= 1)
        return;

    int32_t midpoint = vec.size() / 2;
    std::vector<int32_t> leftVec (vec.begin(), vec.begin() + midpoint);
    std::vector<int32_t> rightVec (vec.begin() + midpoint, vec.end());
    mergeSortNums(leftVec);
    mergeSortNums(rightVec);
    mergeSortMerge(vec, leftVec, rightVec);
}

bool SearchingAlgorithms::binarySearchRecurse(std::vector<int32_t> &vec, const int32_t &key) {
    if (vec.empty())
        return false;

    int midpoint = vec.size() / 2;
    int valueAtMidpoint = vec.at(midpoint);
    if (valueAtMidpoint == key)
        return true;
    else if (key < valueAtMidpoint) {
        std::vector<int32_t> leftHalf (vec.begin(), vec.begin() + midpoint);
        return binarySearchRecurse(leftHalf, key);
    }
    else {
        std::vector<int32_t> rightHalf (vec.begin() + midpoint + 1, vec.end());
        return binarySearchRecurse(rightHalf, key);
    }
}

bool SearchingAlgorithms::binarySearchNums(std::vector<int32_t> vec, const int32_t &key) {
    mergeSortNums(vec);
    return binarySearchRecurse(vec, key);
}

bool SearchingAlgorithms::bfsTree(Node* currRoot, const int32_t& key) {
    std::queue<Node*> q;
    q.push(currRoot);

    while (!q.empty()) {
        Node* nodeToCheck = q.front(); q.pop();
        if (nodeToCheck != nullptr) {
            q.push(nodeToCheck->leftChild);
            q.push(nodeToCheck->rightChild);

            if (nodeToCheck->nodeVal == key)
                return true;
        }
    }

    return false;
}

bool SearchingAlgorithms::dfsTree(Node *currRoot, const int32_t &key) {
    if (currRoot == nullptr)
        return false;

    if (currRoot->nodeVal == key ||
        ((currRoot->leftChild != nullptr && dfsTree(currRoot->leftChild, key)) ||
        (currRoot->rightChild != nullptr && dfsTree(currRoot->rightChild, key)))) {
        return true;
    }
    return false;
}

int32_t SearchingAlgorithms::treeSearchFor(Tree& tree, const int32_t &key, const std::string& algorithm) {
    if (algorithm == "BFS")
        return bfsTree(tree.getRoot(), key);
    else if (algorithm == "DFS")
        return dfsTree(tree.getRoot(), key);
    return 2;
}

void SearchingAlgorithms::searchTreeFor(Tree& tree, const int32_t &key, const std::string &algorithm) {
    int32_t isPresentINT = treeSearchFor(tree, key, algorithm);
    switch (isPresentINT) {
        case 2:
            std::cout << "\tInvalid algorithm; input either \"BFS\" or \"DFS\" for breadth-first and depth-first, respectively." << std::endl;
            break;
        case 1:
            std::cout << "\t" << key << " is in the tree.";
            break;
        default:
            std::cout << "\t" << key << " is not in the tree.";
    }
}

bool SearchingAlgorithms::pathFinder(Node *currRoot, const int32_t &node1Val, const int32_t &node2Val) {
    if (currRoot == nullptr)
        return false;

    // Stop searching
    if (currRoot->nodeVal == node1Val)
        return dfsTree(currRoot, node2Val);
    else if (currRoot->nodeVal == node2Val)
        return dfsTree(currRoot, node1Val);

    // Continue searching for one
    if (currRoot->leftChild != nullptr)
        return pathFinder(currRoot->leftChild, node1Val, node2Val);
    if (currRoot->rightChild != nullptr)
        return pathFinder(currRoot->rightChild, node1Val, node2Val);

    return false;
}

bool SearchingAlgorithms::findPath(Tree& tree, const int32_t &node1Val, const int32_t &node2Val) {
    return pathFinder(tree.getRoot(), node1Val, node2Val);
}
