//
// Created by plcla on 3/26/2022.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unordered_map>
#include "HashMap.h"

void printArray(const Arr* container) {
    for (int i = 0; i < container->size; i++) {
        std::cout << container->arr[i];
        (i == container->size - 1) ? std::cout << "" : std::cout << ", ";
    }
}

void generateOrderedArray(Arr* container) {
    container->size = 10;
    container->arr = (int*)realloc(container->arr, sizeof(int) * container->size);

    for (int i = 0; i < container->size; i++)
        container->arr[i] = i;
}

void generateArray(Arr* container) {
    container->size = 50;
    container->arr = (int*)realloc(container->arr, sizeof(int) * container->size);

    srand(time(nullptr));
    for (int i = 0; i < container->size; i++)
        container->arr[i] = rand() % 100 + 1;
}

int firstRecurringNumber(int* arr, int arrSize) {
    // key = int in arr
    // map = index of int in arr
    std::unordered_map<int, int> um = {};

    for (int i = 0; i < arrSize; i++) {
        if (um.find(arr[i]) != um.end())
            return arr[i];
        um.insert(std::make_pair(arr[i], i));
    }

    return  -1;
}
