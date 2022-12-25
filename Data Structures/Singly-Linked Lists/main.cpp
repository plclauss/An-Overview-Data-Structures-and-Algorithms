#include <iostream>
#include "LinkedList.h"

int main() {;
    LinkedList pointerToHead;
    pointerToHead.insertNode(1, 0);
    pointerToHead.insertNode(2, 1);
    pointerToHead.insertNode(3, 2);
    pointerToHead.printList();
    std::cout << "hi1" << std::endl;

    pointerToHead.deleteNode(0);
//    pointerToHead.deleteNode(1);
//    pointerToHead.deleteNode(2);
    pointerToHead.printList();
    std::cout << "hi2" << std::endl;

    return 0;
}
