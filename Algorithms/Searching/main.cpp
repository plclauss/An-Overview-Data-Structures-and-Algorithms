#include <iostream>
#include "SearchingAlgorithms.h"
#include "Tree.h"
#include "Graph.h"

void printVector(const std::vector<int32_t>& vec) {
    std::cout << "[";
    for (int index = 0; index < vec.size(); index++) {
        std::cout << vec[index];
        (index == vec.size() - 1) ? std::cout << "]" : std::cout << ", " ;
    }
}

void generateVecWithoutKey(std::vector<int32_t>& vec, const int32_t& vecSize, const int32_t& key) {
    while (vec.size() != vecSize) {
        int32_t randomNum = rand() % 100 + 1;
        if (key != randomNum)
            vec.push_back(randomNum);
    }
}

void generateVecWithKey(std::vector<int32_t>& vec, const int32_t& vecSize, const int32_t& key) {
    bool isInArray = false;
    while (vec.size() != vecSize) {
        if (!isInArray && vec.size() == vecSize - 1) {
            vec.push_back(key);
            break;
        }
        int32_t randomNum = rand() % 100 + 1;
        if (randomNum == key)
            isInArray = true;
        vec.push_back(randomNum);
    }
}

int main() {
    srand(time(nullptr));
    SearchingAlgorithms algorithms;
    std::vector<int32_t> testVec;
    int32_t searchFor = rand() % 100 + 1;

    std::cout << "******************************************" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "***** TESTS WHERE KEY DOES NOT EXIST *****" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "******************************************" << std::endl << std::endl;

    generateVecWithoutKey(testVec, rand() % 100 + 1, searchFor);

    // Linear Search
    std::cout << "Linear Search" << std::endl;
    std::cout << "\tOriginal Vector:\n\t";
    printVector(testVec);
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    int32_t searchForAt = algorithms.linearSearchNums(testVec, searchFor);
    if (searchForAt == -1)
        std::cout << "\t" << searchFor << " not in array.";
    else
        std::cout << "\t" << searchFor << " is at " << searchForAt << " in the array, 0-indexed.";

    std::cout << std::endl << std::endl;

    // Binary Search
    std::cout << "Binary Search" << std::endl;
    std::cout << "\tOriginal Vector:\n\t";
    printVector(testVec);
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    bool isPresent = algorithms.binarySearchNums(testVec, searchFor);
    if (isPresent)
        std::cout << "\t" << searchFor << " is in the array.";
    else
        std::cout << "\t" << searchFor << " is not in the array.";

    std::cout << std::endl << std::endl;

    testVec.clear();
    searchFor = rand() % 100 + 1;
    generateVecWithKey(testVec, rand() % 100 + 1, searchFor);

    // Linear Search
    std::cout << "Linear Search" << std::endl;
    std::cout << "\tOriginal Vector:\n\t";
    printVector(testVec);
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    searchForAt = algorithms.linearSearchNums(testVec, searchFor);
    if (searchForAt == -1)
        std::cout << "\t" << searchFor << " not in array.";
    else
        std::cout << "\t" << searchFor << " is at " << searchForAt << " in the array, 0-indexed.";

    std::cout << std::endl << std::endl;

    // Binary Search
    std::cout << "Binary Search" << std::endl;
    std::cout << "\tOriginal Vector:\n\t";
    printVector(testVec);
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    isPresent = algorithms.binarySearchNums(testVec, searchFor);
    if (isPresent)
        std::cout << "\t" << searchFor << " is in the array.";
    else
        std::cout << "\t" << searchFor << " is not in the array.";

    std::cout << std::endl << std::endl << "**********************************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "*************** END **************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "***** BEGINNING TREE TESTS *****" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << "********************************" << std::endl << std::endl;

    // Red-Black Tree
    std::cout << "Creating tree..." << std::endl;
    Tree myTree;
    myTree.insert(33);
    myTree.insert(13);
    myTree.insert(11);
    myTree.insert(21);
    myTree.insert(15);
    myTree.insert(31);
    myTree.insert(53);
    myTree.insert(41);
    myTree.insert(61);
    std::cout << "Contents of tree are: ";
    myTree.printTree();
    std::cout << std::endl << "Contents of tree should be: [21, 13, 33, 11, 15, 31, 53, null, null, null, null, null, null, 41, 61, null, null, null, null]" << std::endl << std::endl;

    // Breadth-First Search
    std::cout << "Breadth-First Search: " << std::endl;
    std::cout << "\tOriginal Tree (as a vector):\n\t";
    myTree.printTree();
    std::cout << "\t(Format is: root, left child of root, right child of root, left child of left child of root, ...)";
    searchFor = 15;
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    algorithms.searchTreeFor(myTree, searchFor, "BFS");

    std::cout << std::endl << std::endl;
    searchFor = 20;

    std::cout << "Breadth-First Search: " << std::endl;
    std::cout << "\tOriginal Tree (as a vector):\n\t";
    myTree.printTree();
    std::cout << "\t(Format is: root, left child of root, right child of root, left child of left child of root, ...)";
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    algorithms.searchTreeFor(myTree, searchFor, "BFS");

    std::cout << std::endl << std::endl;

    // Depth-First Search
    std::cout << "Depth-First Search: " << std::endl;
    std::cout << "\tOriginal Tree (as a vector):\n\t";
    myTree.printTree();
    std::cout << "\t(Format is: root, left child of root, right child of root, left child of left child of root, ...)";
    searchFor = 15;
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    algorithms.searchTreeFor(myTree, searchFor, "DFS");

    std::cout << std::endl << std::endl;
    searchFor = 20;

    std::cout << "Depth-First Search: " << std::endl;
    std::cout << "\tOriginal Tree (as a vector):\n\t";
    myTree.printTree();
    std::cout << "\t(Format is: root, left child of root, right child of root, left child of left child of root, ...)";
    std::cout << "\n\tSearching For: " << searchFor << std::endl << std::endl;
    algorithms.searchTreeFor(myTree, searchFor, "DFS");

    std::cout << std::endl << std::endl << "**********************************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "*************** END **************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << "***** DOES PATH EXIST? *****" << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;

    // Does path exist?
    myTree.insert(20);
    int32_t node1 = 13, node2 = 20;
    std::cout << "Checking for path in tree:\n\t";
    myTree.printTree();
    std::cout << std::endl << "\tSearching if path exists between " << node1 << " and " << node2 << ", in no particular order." << std::endl << std::endl;
    isPresent = algorithms.findPath(myTree, node1, node2);
    if (isPresent)
        std::cout << "\tPath exists between " << node1 << " and " << node2 << "." << std::endl << std::endl;
    else
        std::cout << "\tPath does not exist between " << node1 << " and " << node2 << "." << std::endl << std::endl;

    node1 = 61;
    std::cout << "Checking for path in tree:\n\t";
    myTree.printTree();
    std::cout << std::endl << "\tSearching if path exists between " << node1 << " and " << node2 << ", in no particular order." << std::endl << std::endl;
    isPresent = algorithms.findPath(myTree, node1, node2);
    if (isPresent)
        std::cout << "\tPath exists between " << node1 << " and " << node2 << "." << std::endl << std::endl;
    else
        std::cout << "\tPath does not exist between " << node1 << " and " << node2 << "." << std::endl << std::endl;

    node1 = 53;
    node2 = 62;
    std::cout << "Checking for path in tree:\n\t";
    myTree.printTree();
    std::cout << std::endl << "\tSearching if path exists between " << node1 << " and " << node2 << ", in no particular order." << std::endl << std::endl;
    isPresent = algorithms.findPath(myTree, node1, node2);
    if (isPresent)
        std::cout << "\tPath exists between " << node1 << " and " << node2 << "." << std::endl << std::endl;
    else
        std::cout << "\tPath does not exist between " << node1 << " and " << node2 << "." << std::endl << std::endl;

    std::cout << "**********************************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "*************** END **************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "**********************************" << std::endl;

    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl;

    std::cout << "*********************************" << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "***** BEGINNING GRAPH TESTS *****" << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "*********************************" << std::endl << std::endl;

    Graph myGraph;
    myGraph.addVertex('A');
    myGraph.addVertex('B');
    myGraph.addVertex('C');
    myGraph.addVertex('D');
    myGraph.addVertex('E');
    myGraph.addVertex('F');
    myGraph.addVertex('G');
    myGraph.addVertex('H');
    myGraph.addVertex('I');

    // A
    myGraph.addEdge('A', 'B', 2);

    // B
    myGraph.addEdge('B', 'A', 2);
    myGraph.addEdge('B', 'C', 2);

    // C
    myGraph.addEdge('C', 'D', 2);

    // D
    myGraph.addEdge('D', 'F', 2);

    // E
    myGraph.addEdge('E', 'C', 2);
    myGraph.addEdge('E', 'G', 2);
    myGraph.addEdge('E', 'I', 6);

    // F
    myGraph.addEdge('F', 'G', 2);

    // G
    myGraph.addEdge('G', 'E', 2);
    myGraph.addEdge('G', 'F', 2);
    myGraph.addEdge('G', 'H', 3);

    // I
    myGraph.addEdge('I', 'G', 4);

    std::cout << "Contents of graph should be: " << std::endl;
    std::cout << "\tA: (B, 2) -> " << std::endl;
    std::cout << "\tB: (A, 2) -> (C, 2) -> " << std::endl;
    std::cout << "\tC: (D, 2) -> " << std::endl;
    std::cout << "\tD: (F, 2) -> " << std::endl;
    std::cout << "\tE: (C, 2) -> (G, 2) -> (I, 6) -> " << std::endl;
    std::cout << "\tF: (G, 2) -> " << std::endl;
    std::cout << "\tG: (E, 2) -> (F, 2) -> (H, 3) -> " << std::endl;
    std::cout << "\tH: " << std::endl;
    std::cout << "\tI: (G, 4) -> " << std::endl << "...in no particular order." << std::endl << std::endl;

    std::cout << "Testing..." << std::endl;
    myGraph.showAdjacencyList();

    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << "***** BEGINNING ALGORITHM TESTS *****" << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << "*************************************" << std::endl << std::endl;

    std::cout << "Testing for connection between E and H." << std::endl;
    std::cout << "Result should be true." << std::endl;
    if (myGraph.doesPathExist('E', 'H'))
        std::cout << "\tTrue." << std::endl << std::endl;
    else
        std::cout << "\tFalse." << std::endl << std::endl;

    std::cout << "Testing for connection between E and B." << std::endl;
    std::cout << "Result should be false." << std::endl;
    if (myGraph.doesPathExist('E', 'B'))
        std::cout << "\tTrue." << std::endl << std::endl;
    else
        std::cout << "\tFalse." << std::endl << std::endl;

    std::cout << "Testing for shortest path between E and H." << std::endl;
    std::cout << "Result should be \"E -> G -> H\"." << std::endl;
    std::cout << myGraph.shortestPath('E', 'H') << std::endl << std::endl;

    std::cout << "***************" << std::endl;
    std::cout << "***************" << std::endl;
    std::cout << "***** END *****" << std::endl;
    std::cout << "***************" << std::endl;
    std::cout << "***************" << std::endl;

    return 0;
}
