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

bool isMirror(BinaryTree* left, BinaryTree* right) {
    if (left == nullptr && right == nullptr) return true;
    if ((left == nullptr || right == nullptr) || (left->data != right->data))
        return false;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool symmetricTree(BinaryTree* root) {
    if (root == nullptr) return true;
    return isMirror(root->left, root->right);
}
