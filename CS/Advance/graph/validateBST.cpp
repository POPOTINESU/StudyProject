#include <climits>
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

bool validateBSTHelper(BinaryTree* root, int minValue, int maxValue) {
    if (root == nullptr) return true;

    if (root->data <= minValue || root->data >= maxValue) return false;

    return validateBSTHelper(root->left, minValue, root->data) &&
           validateBSTHelper(root->right, root->data, maxValue);
}
bool validateBST(BinaryTree* root) {
    return validateBSTHelper(root, INT_MIN, INT_MAX);
}
