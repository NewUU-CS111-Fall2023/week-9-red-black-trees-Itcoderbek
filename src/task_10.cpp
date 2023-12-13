#include "task_10.h"
#include <iostream>
BinarySearchTree::BinarySearchTree() : root(nullptr) {}
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}
void BinarySearchTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
Node* BinarySearchTree::insert(Node* node, int value) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}
void BinarySearchTree::insert(int value) {
    root = insert(root, value);
}
Node* BinarySearchTree::remove(Node* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}
void BinarySearchTree::remove(int value) {
    root = remove(root, value);
}
void BinarySearchTree::printInOrder(Node* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}
void BinarySearchTree::print() {
    printInOrder(root);
    std::cout << "\n";
}
int BinarySearchTree::calculateHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}
int BinarySearchTree::height() {
    return calculateHeight(root);
}
int BinarySearchTree::calculateDepth(Node* node, int value, int depth) {
    if (node == nullptr) {
        return -1;
    }   
    if (value == node->data) {
        return depth;
    } else if (value < node->data) {
        return calculateDepth(node->left, value, depth + 1);
    } else {
        return calculateDepth(node->right, value, depth + 1);
    }
}
int BinarySearchTree::depth(int value) {
    return calculateDepth(root, value, 0);
}
Node* BinarySearchTree::convertToAVL(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    Node* left = convertToAVL(node->left);
    Node* right = convertToAVL(node->right);
    int leftHeight = calculateHeight(left);
    int rightHeight = calculateHeight(right);
    if (leftHeight > rightHeight + 1) {      
        Node* temp1 = left->right;
        left->right = node;
        node->left = temp1;
        return left;
    } else if (rightHeight > leftHeight + 1) {
        Node* temp2 = right->left;
        right->left = node;
        node->right = temp2;
        return right;
    } else {
        return node;
    }
}
void BinarySearchTree::convertToAVL() {
    root = convertToAVL(root);
}