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
BinaryTree* bstInsert(BinaryTree* root, int key) {
    if (root == nullptr) return new BinaryTree(key);

    BinaryTree* center = root;

    while (center != nullptr) {
        if (center->data == key) break;

        if (center->data > key) {
            if (center->left == nullptr) {
                center->left = new BinaryTree(key);
                break;
            }
            center = center->left;

        } else {
            if (center->right == nullptr) {
                center->right = new BinaryTree(key);
                break;
            }
            center = center->right;
        }
    }

    return root;
}