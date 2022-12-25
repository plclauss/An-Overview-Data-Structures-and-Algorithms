//
// Created by plcla on 9/5/2022.
//

#ifndef SORTINGINTRO_SORTINGALGORITHMS_H
#define SORTINGINTRO_SORTINGALGORITHMS_H

#include <cstdint>
#include <vector>

class SortingAlgorithms {
private:
    void swapArrContents(std::vector<int32_t>& vec, int32_t left, int32_t right);
    void mergeSortMerge(std::vector<int32_t>& origVec, std::vector<int32_t>& left, std::vector<int32_t>& right);
    void medianToMiddle(std::vector<int32_t>& origVec);
    void quickSortMerge(std::vector<int32_t>& origVec, std::vector<int32_t>& leftVec, std::vector<int32_t>& rightVec);

public:
    void printVectorNums(std::vector<int32_t>& vec);
    void bubbleSortNums(std::vector<int32_t>& vec);
    void selectionSortNums(std::vector<int32_t>& vec);
    void insertionSortNums(std::vector<int32_t>& vec);
    void mergeSortNums(std::vector<int32_t>& vec);
    void quickSortNums(std::vector<int32_t>& vec);
};


#endif //SORTINGINTRO_SORTINGALGORITHMS_H
