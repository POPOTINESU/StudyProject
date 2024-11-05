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

BinaryTree* maximumNode(BinaryTree* root) {
    if (root == NULL) return nullptr;

    BinaryTree* currentNode = root;
    BinaryTree* maxNode = NULL;

    bool isBinary = true;
    while (currentNode->left != NULL || currentNode->right != NULL) {
        if (isBinary && currentNode->left == NULL || currentNode->left < currentNode->right) {
            maxNode = currentNode->right;
            isBinary = false;
        } else if (isBinary && currentNode->right == NULL) {
            maxNode = currentNode;
            isBinary = false;
        } else {
            isBinary = true;
        }

        
        currentNode = (currentNode->right == NULL) ? currentNode->left
                                                   : currentNode->right;
    }
   return maxNode;
}