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

bool exists(BinaryTree* root, int key) {
    BinaryTree* currentNode = root;

    while (currentNode != NULL) {
        if (currentNode->data == key) return true;

        currentNode =
            (currentNode->data > key) ? currentNode->left : currentNode->right;
    }

    return false;
}