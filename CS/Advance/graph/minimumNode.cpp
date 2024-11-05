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

BinaryTree* minimumNode(BinaryTree* root) {
    if (root == NULL) return nullptr;
    BinaryTree* currentNode = root;
    BinaryTree* answerNode = root;
    bool isBinary = true;

    while (currentNode != NULL) {
        if ((isBinary) && (currentNode->left == NULL || currentNode->right == NULL)) {
            answerNode = currentNode;
            isBinary = false;
        } else {
            isBinary = true;
        }

        currentNode = (currentNode->left == NULL) ? currentNode->right
                                                  : currentNode->left;
    }

    return answerNode;
}
