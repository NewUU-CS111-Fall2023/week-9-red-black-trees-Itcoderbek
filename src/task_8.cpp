#include "task_8.h"
#include <iostream>
RedBlackTreeWithMedian::RedBlackTreeWithMedian() : root(nullptr) {}
RedBlackTreeWithMedian::~RedBlackTreeWithMedian() {
    destroyTree(root);
}
void RedBlackTreeWithMedian::Median() {
    int totalNodes = root != nullptr ? root->subtreeSize : 0;
    if (totalNodes == 0) {
        std::cout << "Tree is empty. No median.\n";
        return;
    }
    if (totalNodes % 2 == 0) {
        int medianIndex1 = totalNodes / 2;
        int medianIndex2 = medianIndex1 + 1;
        Node* medianNode1 = findKthSmallest(root, medianIndex1);
        Node* medianNode2 = findKthSmallest(root, medianIndex2);
        std::cout << "Median: " << medianNode1->data << " and " << medianNode2->data << " are medians.\n";
    } else {
        int medianIndex = (totalNodes / 2) + 1;
        Node* medianNode = findKthSmallest(root, medianIndex);
        std::cout << "Median: " << medianNode->data << " is the median.\n";
    }
}
Node* RedBlackTreeWithMedian::findKthSmallest(Node* node, int k) {
    int leftSubtreeSize = node->left != nullptr ? node->left->subtreeSize : 0;
    if (k == leftSubtreeSize + 1) {
        return node;
    } else if (k <= leftSubtreeSize) {
        return findKthSmallest(node->left, k);
    } else {
        return findKthSmallest(node->right, k - leftSubtreeSize - 1);
    }
}