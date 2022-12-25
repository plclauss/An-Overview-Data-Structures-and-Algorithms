#include <iostream>
#include "Tree.h"

int main() {
    Tree treeInstance = Tree(5);
    treeInstance.insertNode(1);
    treeInstance.insertNode(2);
    treeInstance.insertNode(0);
    treeInstance.insertNode(9);
    treeInstance.insertNode(10);
    treeInstance.insertNode(8);

    treeInstance.printTree(treeInstance.getRoot());

    return 0;
}
