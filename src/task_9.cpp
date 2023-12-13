#include "task_9.h"
#include <iostream>
RedBlackTreeWithSubtreeCount::RedBlackTreeWithSubtreeCount() : root(nullptr) {}
RedBlackTreeWithSubtreeCount::~RedBlackTreeWithSubtreeCount() {
    destroyTree(root);
}
void RedBlackTreeWithSubtreeCount::PrintSubtreeCount() {
    printSubtreeCount(root);
    std::cout << std::endl;
}
void RedBlackTreeWithSubtreeCount::printSubtreeCount(Node* root) {
    if (root == nullptr)
        return;

    printSubtreeCount(root->left);
    std::cout << "Node " << root->data << ": Subtree size = " << root->subtreeSize << "\n";
    printSubtreeCount(root->right);
}
void RedBlackTreeWithSubtreeCount::Insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->color = 'R'; 
    newNode->left = newNode->right = newNode->parent = nullptr;
    newNode->subtreeSize = 1; 
    Node* y = nullptr;
    Node* x = root;
    while (x != nullptr) {
        y = x;
        x->subtreeSize++;
        if (value < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    newNode->parent = y;
    if (y == nullptr)
        root = newNode;
    else if (value < y->data)
        y->left = newNode;
    else
        y->right = newNode;
    insertFix(newNode);
}
void RedBlackTreeWithSubtreeCount::Delete(int value) {
    deleteNode(value, root);
}
void RedBlackTreeWithSubtreeCount::deleteNode(int value, Node* x) {
    updateSubtreeSize(x);
}
void RedBlackTreeWithSubtreeCount::updateSubtreeSize(Node* node) {
    while (node != nullptr) {
        node->subtreeSize = calculateSubtreeSize(node);
        node = node->parent;
    }
}