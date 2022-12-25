//
// Created by plcla on 9/5/2022.
//

#include <iostream>
#include "SortingAlgorithms.h"

void SortingAlgorithms::printVectorNums(std::vector<int32_t> &vec) {
    for (int index = 0; index < vec.size(); index++) {
        if (index == vec.size() - 1)
            std::cout << vec[index];
        else
            std::cout << vec[index] << ", ";
    }
}

void SortingAlgorithms::swapArrContents(std::vector<int32_t> &vec, int32_t left, int32_t right) {
    if (left < 0 || left >= vec.size() || right < 0 || right >= vec.size())
        return;

    int32_t temp = vec[right];
    vec[right] = vec[left];
    vec[left] = temp;
}

void SortingAlgorithms::bubbleSortNums(std::vector<int32_t> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1])
                swapArrContents(vec, j, j + 1);
        }
    }
}

void SortingAlgorithms::selectionSortNums(std::vector<int32_t> &vec) {
    int32_t indexToSwapWith = 0, i = 0;
    while (indexToSwapWith < vec.size()) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[i])
                i = j;
        }
        swapArrContents(vec, indexToSwapWith, i);
        indexToSwapWith++;
        i = indexToSwapWith;
    }
}

void SortingAlgorithms::insertionSortNums(std::vector<int32_t> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        int valToSwap = vec[i];
        int j = i - 1;

        while (j >= 0 && valToSwap < vec[j]) {
            swapArrContents(vec, j, j + 1);
            j--;
        }
    }
}

void SortingAlgorithms::mergeSortMerge(std::vector<int32_t>& origVec, std::vector<int32_t> &left, std::vector<int32_t> &right) {
    auto replaceThis = origVec.begin();
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

void SortingAlgorithms::mergeSortNums(std::vector<int32_t> &vec) {
    if (vec.size() == 1)
        return;

    int32_t midpoint = vec.size() / 2;
    std::vector<int32_t> leftVec (vec.begin(), vec.begin() + midpoint);
    std::vector<int32_t> rightVec (vec.begin() + midpoint, vec.end());

    mergeSortNums(leftVec);
    mergeSortNums(rightVec);
    mergeSortMerge(vec, leftVec, rightVec);
}

void SortingAlgorithms::medianToMiddle(std::vector<int32_t> &origVec) {
    if (origVec.front() > origVec.back())
        swapArrContents(origVec, 0, origVec.size() - 1);
    if (origVec.front() > origVec.at(origVec.size() / 2))
        swapArrContents(origVec, 0, origVec.size() / 2);
    if (origVec.back() < origVec.at(origVec.size() / 2))
        swapArrContents(origVec, origVec.size() / 2, origVec.size() / 2);
}

void SortingAlgorithms::quickSortMerge(std::vector<int32_t> &origVec, std::vector<int32_t> &leftVec, std::vector<int32_t> &rightVec) {
    int32_t currIndex = 0;
    for (int32_t num : leftVec) {
        origVec[currIndex] = num;
        currIndex++;
    }
    currIndex++;
    for (int32_t num : rightVec) {
        origVec[currIndex] = num;
        currIndex++;
    }
}

void SortingAlgorithms::quickSortNums(std::vector<int32_t> &vec) {
    if (vec.size() <= 1)
        return;

    medianToMiddle(vec);

    int32_t leftIndex = 0, medianIndex = vec.size() / 2, rightIndex = vec.size() - 1;
    while (leftIndex != rightIndex) {
        if (leftIndex != medianIndex) {
            if (vec.at(leftIndex) > vec.at(medianIndex)) {
                swapArrContents(vec, leftIndex, medianIndex);
                medianIndex = leftIndex;
            }
            else
                leftIndex++;
        }
        else {
            if (vec.at(rightIndex) < vec.at(medianIndex)) {
                swapArrContents(vec, rightIndex, medianIndex);
                medianIndex = rightIndex;
            }
            else
                rightIndex--;
        }
    }

    std::vector<int32_t> leftVec (vec.begin(), vec.begin() + medianIndex);
    std::vector<int32_t> rightVec (vec.begin() + medianIndex + 1, vec.end());
    quickSortNums(leftVec);
    quickSortNums(rightVec);
    quickSortMerge(vec, leftVec, rightVec);
}
