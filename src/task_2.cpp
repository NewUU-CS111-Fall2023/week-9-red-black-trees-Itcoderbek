#include "task_2.h"
#include <iostream>
RedBlackTree::RedBlackTree() : root(nullptr) {}
RedBlackTree::~RedBlackTree() {
    destroyTree(root);
}
void RedBlackTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
void RedBlackTree::Insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->color = 'R'; 
    newNode->left = newNode->right = newNode->parent = nullptr;
    Node* y = nullptr;
    Node* x = root;
    while (x != nullptr) {
        y = x;
        if (value < x->data)
            x = x->left;
        else
            x = x->right;
    }
    newNode->parent = y;
    if (y == nullptr)
        root = newNode;
    else if (value < y->data)
        y->left = newNode;
    else
        y->right = newNode;
    insertFixup(newNode);
}
void RedBlackTree::PrintTree() {
    printTreeHelper(root, 0);
}
void RedBlackTree::printTreeHelper(Node* root, int space) {
    constexpr int COUNT = 5;
    if (root == nullptr)
        return;
    space += COUNT;
    printTreeHelper(root->right, space);
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->data << "(" << root->color << ")";
    printTreeHelper(root->left, space);
}
void RedBlackTree::leftRotate(Node* x) {
    if (x == nullptr || x->right == nullptr)
        return;
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}
void RedBlackTree::rightRotate(Node* y) {
    if (y == nullptr || y->left == nullptr)
        return;
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}
void RedBlackTree::leftRotate() {
    leftRotate(root);
}
void RedBlackTree::rightRotate() {
    rightRotate(root);
}