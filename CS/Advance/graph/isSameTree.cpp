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
    BinaryTree(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isSameTree(BinaryTree* root1, BinaryTree* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    if (root1->data != root2->data) return false;

    return isSameTree(root1->left, root2->left) &&
           isSameTree(root1->right, root2->right);
}