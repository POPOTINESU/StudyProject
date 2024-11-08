#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class BinaryTree {
   public:
    int data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int value) { this->data = value; };
    BinaryTree(int value, BinaryTree* left, BinaryTree* right) {
        this->data = value;
        this->left = left;
        this->right = right;
    };
};

int minDepth(BinaryTree* root) {
    if (root == nullptr) return -1;

    if (root->left != nullptr) return minDepth(root->right) + 1;
    if (root->right != nullptr) return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}