#ifndef TASK_4_H
#define TASK_4_H
class ReversedRedBlackTree {
private:
    struct Node {
        int data;
        char color; 
        Node* parent;
        Node* left;
        Node* right;
    };
    Node* root;
    void insertFix(Node* newNode);
    void deleteFix(Node* x, Node* xParent, bool isLeftChild);
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void transplant(Node* u, Node* v);
    Node* findMinimum(Node* startNode);
    void deleteNode(int value, Node* x);
    void reversePrintTreeHelper(Node* root, int space); 
public:
    ReversedRedBlackTree();
    ~ReversedRedBlackTree();
    void Insert(int value);
    void Delete(int value);
    void PrintTree();
};
#endif 