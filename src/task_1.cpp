// task_1.cpp
#include "task_1.h"
#include <iostream>

RedBlackTree::RedBlackTree() : root(nullptr) {}
void RedBlackTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
RedBlackTree::~RedBlackTree() {
    destroyTree(root);
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

void RedBlackTree::PrintTree() {
    printTreeHelper(root, 0);
}
void RedBlackTree::insertFixup(Node* newNode) {
        while (newNode != root && newNode->parent->color == 'R') {
        if (newNode->parent == newNode->parent->parent->left) {
            Node* y = newNode->parent->parent->right;
            if (y != nullptr && y->color == 'R') {
                newNode->parent->color = 'B';
                y->color = 'B';
                newNode->parent->parent->color = 'R';
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotate(newNode);
                }
                newNode->parent->color = 'B';
                newNode->parent->parent->color = 'R';
                rightRotate(newNode->parent->parent);
            }
        } else {
            Node* y = newNode->parent->parent->left;
            if (y != nullptr && y->color == 'R') {
                newNode->parent->color = 'B';
                y->color = 'B';
                newNode->parent->parent->color = 'R';
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotate(newNode);
                }
                newNode->parent->color = 'B';
                newNode->parent->parent->color = 'R';
                leftRotate(newNode->parent->parent);
            }
        }
    }
    root->color = 'B';
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