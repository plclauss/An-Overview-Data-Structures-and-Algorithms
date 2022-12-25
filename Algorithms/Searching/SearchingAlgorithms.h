//
// Created by plcla on 9/14/2022.
//

#ifndef SEARCHINGINTRO_SEARCHINGALGORITHMS_H
#define SEARCHINGINTRO_SEARCHINGALGORITHMS_H

#include <cstdint>
#include <vector>
#include <string>
#include <queue>
#include "Tree.h"

class SearchingAlgorithms {
private:
    void mergeSortNums(std::vector<int32_t>& vec);
    void mergeSortMerge(std::vector<int32_t>& vec, std::vector<int32_t>& left, std::vector<int32_t>& right);
    bool binarySearchRecurse(std::vector<int32_t>& vec, const int32_t& key);
    bool bfsTree(Node* currRoot, const int32_t& key);
    bool dfsTree(Node* currRoot, const int32_t& key);
    int32_t treeSearchFor(Tree& tree, const int32_t& key, const std::string& algorithm);
    bool pathFinder(Node* currRoot, const int32_t& node1Val, const int32_t& node2Val);

public:
    int32_t linearSearchNums(const std::vector<int32_t>& vec, const int32_t& key);
    bool binarySearchNums(std::vector<int32_t> vec, const int32_t& key);
    void searchTreeFor(Tree& tree, const int32_t& key, const std::string& algorithm);
    bool findPath(Tree& tree, const int32_t& node1Val, const int32_t& node2Val);
};


#endif //SEARCHINGINTRO_SEARCHINGALGORITHMS_H
