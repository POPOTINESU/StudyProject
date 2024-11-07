#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class BinaryTree {
   public:
    int data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int value) : data(value), left(nullptr), right(nullptr) {}
    BinaryTree(int value, BinaryTree* left, BinaryTree* right)
        : data(value), left(left), right(right) {}
};

BinaryTree* invertTree(BinaryTree* root) {
    if (root == nullptr) return nullptr;

    BinaryTree* left = invertTree(root->left);
    BinaryTree* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}
