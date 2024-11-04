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

int sumOfThreeNodes(BinaryTree* root) {
    if (root == NULL) return 0;

    int rootData = (root != NULL) ? root->data : 0;
    int leftData = (root->left != NULL) ? root->left->data : 0;
    int rightData = (root->right != NULL) ? root->right->data : 0;

    return rootData + leftData + rightData;
}