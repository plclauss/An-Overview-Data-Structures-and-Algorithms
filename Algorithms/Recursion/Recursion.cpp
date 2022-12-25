//
// Created by plcla on 9/5/2022.
//

#include "Recursion.h"

int32_t Recursion::factorial(int32_t n) {
    if (n == 1)
        return n;
    return n * factorial(n - 1);
}

int32_t Recursion::fib(int32_t n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int32_t firstAddend = fib(n - 1);
    int32_t secondAddend = fib(n - 2);
    return firstAddend + secondAddend;
}

std::string Recursion::reverseString(std::string str) {
    if (str.empty())
        return "";

    std::string retVal = str.substr(str.length() - 1);
    retVal += reverseString(str.substr(0, str.length() - 1));
    return retVal;
}
