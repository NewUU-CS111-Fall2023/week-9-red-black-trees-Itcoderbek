#ifndef TASK_9_H
#define TASK_9_H
class RedBlackTreeWithSubtreeCount {
    private:
    struct Node {
        int data;
        char color;
        Node* parent;
        Node* left;
        Node* right;
        int subtreeSize; 
    };
    Node* root;
    void insertFix(Node* newNode);
    void deleteFix(Node* x, Node* xParent, bool isLeftChild);
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void transplant(Node* u, Node* v);
    Node* findMinimum(Node* startNode);
    void deleteNode(int value, Node* x);
    void updateSubtreeSize(Node* node);
    void printSubtreeCount(Node* root);
public:
    RedBlackTreeWithSubtreeCount();
    ~RedBlackTreeWithSubtreeCount();
    void Insert(int value);
    void Delete(int value);
    void PrintTree();
    void PrintSubtreeCount();
};
#endif 