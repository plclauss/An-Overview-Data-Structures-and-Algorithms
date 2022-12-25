nes (16 sloc) 395 Bytes
//
// Created by plcla on 3/26/2022.
//

#ifndef ZTMHASHTABLES_HASHMAP_H
#define ZTMHASHTABLES_HASHMAP_H

// custom types
typedef struct {
    int* arr;
    int size;
}Arr;

// custom functions
int firstRecurringNumber(int* arr, int arrSize);
void generateArray(Arr* container);
void generateOrderedArray(Arr* container);
void printArray(const Arr* container);

#endif //ZTMHASHTABLES_HASHMAP_H
