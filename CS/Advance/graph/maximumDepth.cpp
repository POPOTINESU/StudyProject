#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
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

int maximumDepth(BinaryTree* root) {
    if (root == nullptr) return -1;

    int leftDepth = maximumDepth(root->left);  
    int rightDepth = maximumDepth(root->right);

    return max(leftDepth, rightDepth) + 1; 
}