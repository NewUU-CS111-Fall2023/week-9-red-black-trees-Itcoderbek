#ifndef TASK_6_H
#define TASK_6_H
class RedBlackTreeWithBlackHeight {
private:
    struct Node {
        int data;
        char color; 
        Node* parent;
        Node* left;
        Node* right;
        int blackHeight;
    };
    Node* root;
    void insertFix(Node* newNode);
    void deleteFix(Node* x, Node* xParent, bool isLeftChild);
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void transplant(Node* u, Node* v);
    Node* findMinimum(Node* startNode);
    void deleteNode(int value, Node* x);
    void updateBlackHeight(Node* node); 
    void printBlackHeight(Node* root);
public:
    RedBlackTreeWithBlackHeight();
    ~RedBlackTreeWithBlackHeight();
    void Insert(int value);
    void Delete(int value);
    void PrintTree();
    void PrintBlackHeight(); 
};
#endif