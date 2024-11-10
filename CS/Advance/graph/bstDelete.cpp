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

    BinaryTree* findMinNode() {
        BinaryTree* currentNode = this;
        while (currentNode && currentNode->left)
            currentNode = currentNode->left;
        return currentNode;
    }
};

BinaryTree* bstDelete(BinaryTree* root, int key) {
    if (root == nullptr) return nullptr;

    if (root->data > key) {
        root->left = bstDelete(root->left, key);
    } else if (root->data < key) {
        root->right = bstDelete(root->right, key);
    } else {
        if (root->left == nullptr) {
            BinaryTree* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BinaryTree* temp = root->left;
            delete root;
            return temp;
        }

        // 　二つノードがある場合
        BinaryTree* minNode = root->right->findMinNode();
        root->data = minNode->data;
        root->right = bstDelete(root->right, minNode->data);
    }

    return root;
}