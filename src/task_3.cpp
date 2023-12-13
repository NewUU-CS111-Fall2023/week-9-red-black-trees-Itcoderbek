#include "task_3.h"
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
    insertFix(newNode);
}
void RedBlackTree::Delete(int value) {
    deleteNode(value, root);
}
void RedBlackTree::deleteNode(int value, Node* x) {
    if (x == nullptr) {
        std::cout << "Node with value " << value << " not found.\n";
        return;
    }
    if (value < x->data) {
        deleteNode(value, x->left);
    } else if (value > x->data) {
        deleteNode(value, x->right);
    } else {
        char originalColor = x->color;
        if (x->left == nullptr) {
            Node* y = x->right;
            transplant(x, x->right);
            delete x;
            if (originalColor == 'B')
                deleteFix(y, y->parent, y->parent->left == y);
        } else if (x->right == nullptr) {
            Node* y = x->left;
            transplant(x, x->left);
            delete x;
            if (originalColor == 'B')
                deleteFix(y, y->parent, y->parent->left == y);
        } else { 
            Node* y = findMinimum(x->right);
            originalColor = y->color;
            if (y->parent != x) {
                transplant(y, y->right);
                y->right = x->right;
                y->right->parent = y;
            }
            transplant(x, y);
            y->left = x->left;
            y->left->parent = y;
            y->color = x->color;
            delete x;
            if (originalColor == 'B')
                deleteFix(y, y->parent, y->parent->left == y);
        }
    }
}
void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent;
}
Node* RedBlackTree::findMinimum(Node* startNode) {
    while (startNode->left != nullptr)
        startNode = startNode->left;
    return startNode;
}
void RedBlackTree::insertFix(Node* newNode) {
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
void RedBlackTree::deleteFix(Node* x, Node* xParent, bool isLeftChild) {
    while (x != root && (x == nullptr || x->color == 'B')) {
        if (isLeftChild) {
            Node* w = xParent->right;
            if (w != nullptr) {
                if (w->color == 'R') {
                    w->color = 'B';
                    xParent->color = 'R';
                    leftRotate(xParent);
                    w = xParent->right;
                }
                if ((w->left == nullptr || w->left->color == 'B') &&
                    (w->right == nullptr || w->right->color == 'B')) {
                    w->color = 'R';
                    x = xParent;
                    xParent = x->parent;
                    isLeftChild = (x == nullptr || x == xParent->left);
                } else {
                    if (w->right == nullptr || w->right->color == 'B') {
                        if (w->left != nullptr)
                            w->left->color = 'B';
                        w->color = 'R';
                        rightRotate(w);
                        w = xParent->right;
                    }
                    w->color = xParent->color;
                    xParent->color = 'B';
                    if (w->right != nullptr)
                        w->right->color = 'B';
                    leftRotate(xParent);
                    x = root; 
                }
            } else {
                x = root;
            }
        } else {
            Node* w = xParent->left;
            if (w != nullptr) {
                if (w->color == 'R') {
                
                    w->color = 'B';
                    xParent->color = 'R';
                    rightRotate(xParent);
                    w = xParent->left;
                }
                if ((w->right == nullptr || w->right->color == 'B') &&
                    (w->left == nullptr || w->left->color == 'B')) {               
                    w->color = 'R';
                    x = xParent;
                    xParent = x->parent;
                    isLeftChild = (x == nullptr || x == xParent->left);
                } else {
                    if (w->left == nullptr || w->left->color == 'B') {               
                        if (w->right != nullptr)
                            w->right->color = 'B';
                        w->color = 'R';
                        leftRotate(w);
                        w = xParent->left;
                    }            
                    w->color = xParent->color;
                    xParent->color = 'B';
                    if (w->left != nullptr)
                        w->left->color = 'B';
                    rightRotate(xParent);
                    x = root; 
                }
            } else {                
                x = root;
            }
        }
    }
    if (x != nullptr)
        x->color = 'B';
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