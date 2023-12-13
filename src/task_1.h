#ifndef TASK_1_H
#define TASK_1_H
class RedBlackTree {
private:
    struct Node {
        int data;
        char color;
        Node* parent;
        Node* left;
        Node* right;
    };
    Node* root;
    void insertFixup(Node* newNode);
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void printTreeHelper(Node* root, int space);

public:
    RedBlackTree();
    ~RedBlackTree();
    void Insert(int value);
    void PrintTree();
};
#endif 