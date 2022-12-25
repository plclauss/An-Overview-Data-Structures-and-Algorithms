#include <iostream>
#include "Recursion.h"

int main() {
    Recursion recursionInstance;
    std::cout << "5! is " << recursionInstance.factorial(5) << "." << std::endl;
    std::cout << "With 0-indexing, the number at the 5 index position in the Fibonacci sequence is " << recursionInstance.fib(5) << "." << std::endl;
    std::cout << "The reverse of \"yoyo mastery\" is " << recursionInstance.reverseString("yoyo mastery") << "." << std::endl;

    return 0;
}
