#ifndef TASK_10_H
#define TASK_10_H
class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;
    void destroyTree(Node* node);
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    void printInOrder(Node* node);
    int calculateHeight(Node* node);
    int calculateDepth(Node* node, int value, int depth);
    Node* convertToAVL(Node* node);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    void remove(int value);
    void print();
    int height();
    int depth(int value);
    void convertToAVL();
};
#endif 