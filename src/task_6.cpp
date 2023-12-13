#include "task_6.h"
#include <iostream>
RedBlackTreeWithBlackHeight::RedBlackTreeWithBlackHeight() : root(nullptr) {}
RedBlackTreeWithBlackHeight::~RedBlackTreeWithBlackHeight() {
    destroyTree(root);
}
void RedBlackTreeWithBlackHeight::Insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->color = 'R'; 
    newNode->left = newNode->right = newNode->parent = nullptr;
    newNode->blackHeight = 1; 
    Node* y = nullptr;
    Node* x = root;
    while (x != nullptr) {
        y = x;
        if (value < x->data) {
            x->blackHeight++; 
            x = x->left;
        } else {
            x->blackHeight++;
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
void RedBlackTreeWithBlackHeight::Delete(int value) {
    deleteNode(value, root);
}
void RedBlackTreeWithBlackHeight::deleteNode(int value, Node* x) {
    updateBlackHeight(x);
}
void RedBlackTreeWithBlackHeight::updateBlackHeight(Node* node) {
    while (node != nullptr) {
        int leftBlackHeight = (node->left != nullptr) ? node->left->blackHeight : 0;
        int rightBlackHeight = (node->right != nullptr) ? node->right->blackHeight : 0;
        node->blackHeight = std::max(leftBlackHeight, rightBlackHeight) + (node->color == 'B');
        node = node->parent;
    }
}
void RedBlackTreeWithBlackHeight::PrintBlackHeight() {
    printBlackHeight(root);
    std::cout << std::endl;
}
void RedBlackTreeWithBlackHeight::printBlackHeight(Node* root) {
    if (root == nullptr)
        return;
    printBlackHeight(root->left);
    std::cout << "Node " << root->data << ": Black Height = " << root->blackHeight << "\n";
    printBlackHeight(root->right);
}