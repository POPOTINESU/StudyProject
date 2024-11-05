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
    BinaryTree(int value, BinaryTree* left, BinaryTree* right)
        : data(value), left(left), right(right) {}
};

BinaryTree* successor(BinaryTree* root, int key) {
    if (root == nullptr) return nullptr;
    BinaryTree* currentNode = root;
    BinaryTree* successor = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->data > key) {
            successor = currentNode;
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    return successor;
}