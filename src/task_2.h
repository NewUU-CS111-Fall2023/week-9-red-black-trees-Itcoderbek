#ifndef TASK_2_H
#define TASK_2_H
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
    void rightRotate(Node* y);
    void printTreeHelper(Node* root, int space);
public:
    RedBlackTree();
    ~RedBlackTree();
    void Insert(int value);
    void PrintTree();
    void leftRotate(); 
    void rightRotate(); 
};
#endif 