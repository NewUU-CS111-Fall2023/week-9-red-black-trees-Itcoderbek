#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"
#include "task_6.h"
#include "task_7.h"
#include "task_8.h"
#include "task_9.h"
#include "task_10.h"
#include "task_1.h"
#include <iostream>
int main() {
    RedBlackTree rbTree;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        rbTree.Insert(value);
    }
    std::cout << "\nRed-Black Tree after insertion:\n";
    rbTree.PrintTree();
    std::cout << "\n\n";
    std::cout << "Performing left rotation...\n";
    rbTree.leftRotate();
    std::cout << "Red-Black Tree after left rotation:\n";
    rbTree.PrintTree();
    std::cout << "\n\n";
    std::cout << "Performing right rotation...\n";
    rbTree.rightRotate();
    std::cout << "Red-Black Tree after right rotation:\n";
    rbTree.PrintTree();
    std::cout << "\n\n";
    //task 3
RedBlackTree rbTree;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        rbTree.Insert(value);
    }
    std::cout << "\nRed-Black Tree after insertion:\n";
    rbTree.PrintTree();
    std::cout << "\n\n";
    int valueToDelete;
    std::cout << "Enter the value to delete: ";
    std::cin >> valueToDelete;
    rbTree.Delete(valueToDelete);
    std::cout << "\nRed-Black Tree after deletion:\n";
    rbTree.PrintTree();
    std::cout << "\n\n";
    //task 4
     ReversedRedBlackTree reversedRbTree;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        reversedRbTree.Insert(value);
    }
    std::cout << "\nReversed Red-Black Tree:\n";
    reversedRbTree.PrintTree();
    std::cout << "\n\n";
    //task 5
    RedBlackTreeWithChildrenCount rbTreeWithChildrenCount;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        rbTreeWithChildrenCount.Insert(value);
    }
    std::cout << "\nNumber of children for each node:\n";
    rbTreeWithChildrenCount.PrintChildrenCount();
    std::cout << "\n";
    //task 6
    RedBlackTreeWithBlackHeight rbTreeWithBlackHeight;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        rbTreeWithBlackHeight.Insert(value);
    }
    std::cout << "\nBlack Height for each node:\n";
    rbTreeWithBlackHeight.PrintBlackHeight();
    std::cout << "\n";
    //task 7
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        rbTreeWithSearch.Insert(value);
    }
    std::cout << "\nRed-Black Tree:\n";
    rbTreeWithSearch.PrintTree();
    std::cout << "\n\n";
    int valueToSearch;
    std::cout << "Enter the value to search: ";
    std::cin >> valueToSearch;
    rbTreeWithSearch.Search(valueToSearch);
    //task 8
      RedBlackTreeWithMedian rbTreeWithMedian;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        rbTreeWithMedian.Insert(value);
    }
    std::cout << "\nRed-Black Tree:\n";
    rbTreeWithMedian.PrintTree();
    std::cout << "\n";
    std::cout << "Number of nodes in every subtree:\n";
    rbTreeWithMedian.PrintSubtreeCount();
    std::cout << "\n";
    rbTreeWithMedian.Median();
    //task 9
    RedBlackTreeWithSubtreeCount rbTreeWithSubtreeCount;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        rbTreeWithSubtreeCount.Insert(value);
    }
    std::cout << "\nRed-Black Tree:\n";
    rbTreeWithSubtreeCount.PrintTree();
    std::cout << "\n";
    std::cout << "Number of nodes in every subtree:\n";
    rbTreeWithSubtreeCount.PrintSubtreeCount();
    std::cout << "\n";
    //task 10
    BinarySearchTree binarySearchTree;
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Enter the values of nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        binarySearchTree.insert(value);
    }
    std::cout << "\nOriginal Binary Search Tree (In-order traversal):\n";
    binarySearchTree.print();
    std::cout << "\n";
    std::cout << "Height of the Binary Search Tree: " << binarySearchTree.height() << "\n";
    binarySearchTree.convertToAVL();
    std::cout << "\nAVL Tree (In-order traversal):\n";
    binarySearchTree.print();
    std::cout << "\n";
    return 0;
}