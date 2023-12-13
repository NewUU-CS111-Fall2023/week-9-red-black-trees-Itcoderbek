#include "task_5.h"
#include <iostream>
RedBlackTreeWithChildrenCount::RedBlackTreeWithChildrenCount() : root(nullptr) {}
RedBlackTreeWithChildrenCount::~RedBlackTreeWithChildrenCount() {
    destroyTree(root);
}
void RedBlackTreeWithChildrenCount::Insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->color = 'R';
    newNode->left = newNode->right = newNode->parent = nullptr;
    newNode->childrenCount = 0; 
    Node* y = nullptr;
    Node* x = root;
    while (x != nullptr) {
        y = x;
        if (value < x->data) {
            x->childrenCount++;
            x = x->left;
        } else {
            x->childrenCount++; 
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
void RedBlackTreeWithChildrenCount::Delete(int value) {
    deleteNode(value, root);
}
void RedBlackTreeWithChildrenCount::deleteNode(int value, Node* x) {
    updateChildrenCount(x);
}
void RedBlackTreeWithChildrenCount::updateChildrenCount(Node* node) {
    while (node != nullptr) {
        node->childrenCount = 0; 
        if (node->left != nullptr)
            node->childrenCount += (1 + node->left->childrenCount);
        if (node->right != nullptr)
            node->childrenCount += (1 + node->right->childrenCount);

        node = node->parent;
    }
}
void RedBlackTreeWithChildrenCount::PrintChildrenCount() {
    printChildrenCount(root);
    std::cout << std::endl;
}
void RedBlackTreeWithChildrenCount::printChildrenCount(Node* root) {
    if (root == nullptr)
        return;
    printChildrenCount(root->left);
    std::cout << "Node " << root->data << ": " << root->childrenCount << " children\n";
    printChildrenCount(root->right);
}