#include "task_7.h"
#include <iostream>
RedBlackTreeWithSearch::RedBlackTreeWithSearch() : root(nullptr) {}
RedBlackTreeWithSearch::~RedBlackTreeWithSearch() {
    destroyTree(root);
}
void RedBlackTreeWithSearch::Search(int value) {
    int height = 0;
    Node* resultNode = searchValue(value, root, height);

    if (resultNode != nullptr) {
        std::cout << value << " is found, its height is " << height << "\n";
    } else {
        std::cout << value << " is not found\n";
    }
}
Node* RedBlackTreeWithSearch::searchValue(int value, Node* root, int& height) {
    while (root != nullptr) {
        if (value == root->data) {
            return root; 
        } else if (value < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
        height++;
    }
    return nullptr;
}