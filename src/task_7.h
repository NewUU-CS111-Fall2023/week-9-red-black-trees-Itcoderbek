#ifndef TASK_7_H
#define TASK_7_H
class RedBlackTreeWithSearch {
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
    void updateBlackHeight(Node* node);
    void printBlackHeight(Node* root);
    Node* searchValue(int value, Node* root, int& height);
public:
    RedBlackTreeWithSearch();
    ~RedBlackTreeWithSearch();
    void Insert(int value);
    void Delete(int value);
    void PrintTree();
    void PrintBlackHeight();
    void Search(int value);
};
#endif 