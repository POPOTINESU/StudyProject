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

BinaryTree* predecessor(BinaryTree* root, int key) {
    if (root == nullptr) return nullptr;

    BinaryTree* currentNode = root;
    BinaryTree* predecessor = nullptr;

    while (currentNode != NULL) {
        if (currentNode->data >= key) {
            currentNode = currentNode->left;
        } else {
            predecessor = currentNode;
            currentNode = currentNode->right;
        }
    }
    return predecessor;
}
