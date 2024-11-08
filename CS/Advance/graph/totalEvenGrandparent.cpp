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

int totalEvenGrandparent(BinaryTree* root) {
    if (root == nullptr) return 0;

    int sum = 0;

    if (root->data % 2 == 0) {
        if (root->left != nullptr) {
            BinaryTree* leftNode = root->left;
            if (leftNode->left != nullptr) sum += leftNode->left->data;
            if (leftNode->right != nullptr) sum += leftNode->right->data;
        }
        if (root->right != nullptr) {
            BinaryTree* rightNode = root->right;
            if (rightNode->left != nullptr) sum += rightNode->left->data;
            if (rightNode->right != nullptr) sum += rightNode->right->data;
        }
    }

    sum += totalEvenGrandparent(root->left) + totalEvenGrandparent(root->right);

    return sum;
}
