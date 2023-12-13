#ifndef TASK_5_H
#define TASK_5_H
class RedBlackTreeWithChildrenCount {
private:
    struct Node {
        int data;
        char color; 
        Node* parent;
        Node* left;
        Node* right;
        int childrenCount; 
    };
    Node* root;
    void insertFix(Node* newNode);
    void deleteFix(Node* x, Node* xParent, bool isLeftChild);
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void transplant(Node* u, Node* v);
    Node* findMinimum(Node* startNode);
    void deleteNode(int value, Node* x);
    void updateChildrenCount(Node* node); 
    void printChildrenCount(Node* root);
public:
    RedBlackTreeWithChildrenCount();
    ~RedBlackTreeWithChildrenCount();
    void Insert(int value);
    void Delete(int value);
    void PrintTree();
    void PrintChildrenCount(); 
};
#endif 

