#include <iostream>
#include "HashMap.h"


void test1() {
    Arr* newArray = new Arr;
    newArray->size = 0;
    newArray->arr = nullptr;

    std::cout << "The contents of your array, currently, are: [";
    printArray(newArray);
    std::cout << "]." << std::endl;
    std::cout << "The first repeated character is: " << firstRecurringNumber(newArray->arr, newArray->size) << "." << std::endl << std::endl;

    std::cout << "The contents of your ordered, unique-numbered array are: [";
    generateOrderedArray(newArray);
    printArray(newArray);
    std::cout << "]." << std::endl;
    std::cout << "The first repeated character is: " << firstRecurringNumber(newArray->arr, newArray->size) << "." << std::endl << std::endl;

    generateArray(newArray);

    std::cout << "The contents of your randomly generated array are: [";
    printArray(newArray);
    std::cout << "]." << std::endl;
    std::cout << "The first repeated character is: " << firstRecurringNumber(newArray->arr, newArray->size) << "." << std::endl << std::endl;

    free(newArray->arr);
    delete(newArray);
}

int main() {
    test1();

    return 0;
}
