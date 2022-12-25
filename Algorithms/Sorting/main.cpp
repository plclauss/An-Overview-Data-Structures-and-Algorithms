#include <iostream>
#include "SortingAlgorithms.h"

void fillVec(std::vector<int32_t>& vec) {
    while (vec.size() != 15)
        vec.push_back(rand());
}

int main() {
    SortingAlgorithms instance;
    std::vector<int32_t> vec = {7,5,1,2,9,3,8,4,6,10};
    std::vector<int32_t> tempVec = vec;

    std::cout << "********************************" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "***** BEGIN STABLE TESTING *****" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "********************************" << std::endl;

    // Bubble Sort
    std::cout << "Testing Bubble Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.bubbleSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;


    // Reset tempVec
    tempVec = vec;

    // Selection Sort
    std::cout << "Testing Selection Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.selectionSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    // Reset tempVec
    tempVec = vec;

    // Insertion Sort
    std::cout << "Testing Insertion Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.insertionSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    // Reset tempVec
    tempVec = vec;

    // Merge Sort
    std::cout << "Testing Merge Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.mergeSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    // Reset tempVec
    tempVec = vec;

    // Quick Sort
    std::cout << "Testing Quicksort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.quickSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    std::cout << std::endl << "********************************" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "*** BEGIN RANDOMIZED TESTING ***" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "********************************" << std::endl;

    vec.clear();
    srand(time(nullptr));
    fillVec(vec);

    // Bubble Sort
    std::cout << "Testing Bubble Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.bubbleSortNums(vec);
    instance.printVectorNums(vec);
    std::cout << std::endl << std::endl;


    // Reset vec
    vec.clear();
    fillVec(vec);

    // Selection Sort
    std::cout << "Testing Selection Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.selectionSortNums(vec);
    instance.printVectorNums(vec);
    std::cout << std::endl << std::endl;

    // Reset vec
    vec.clear();
    fillVec(vec);

    // Insertion Sort
    std::cout << "Testing Insertion Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.insertionSortNums(vec);
    instance.printVectorNums(vec);
    std::cout << std::endl << std::endl;

    // Reset vec
    vec.clear();
    fillVec(vec);

    // Merge Sort
    std::cout << "Testing Merge Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.mergeSortNums(vec);
    instance.printVectorNums(vec);
    std::cout << std::endl << std::endl;

    // Reset vec
    vec.clear();
    fillVec(vec);

    // Quick Sort
    std::cout << "Testing Quicksort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(vec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.quickSortNums(vec);
    instance.printVectorNums(vec);
    std::cout << std::endl << std::endl;

    // Reset vec
    vec.clear();
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(8);
    tempVec = vec;

    std::cout << "********************************" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "*** BEGIN ADDITIONAL TESTING ***" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "********************************" << std::endl;

    // Bubble Sort
    std::cout << "Testing Bubble Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(tempVec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.bubbleSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    // Reset tempVec
    tempVec = vec;

    // Selection Sort
    std::cout << "Testing Selection Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(tempVec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.selectionSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    // Reset tempVec
    tempVec = vec;

    // Insertion Sort
    std::cout << "Testing Insertion Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(tempVec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.insertionSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    // Reset tempVec
    tempVec = vec;

    // Merge Sort
    std::cout << "Testing Merge Sort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(tempVec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.mergeSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    // Reset tempVec
    tempVec = vec;

    // Quick Sort
    std::cout << "Testing Quicksort:" << std::endl << "\tUn-sorted Vector:\n\t\t";
    instance.printVectorNums(tempVec);
    std::cout << std::endl << "\tSorted Vector:\n\t\t";
    instance.quickSortNums(tempVec);
    instance.printVectorNums(tempVec);
    std::cout << std::endl << std::endl;

    return 0;
}
