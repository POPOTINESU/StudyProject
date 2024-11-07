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

bool treeWithTheSameValue(BinaryTree* root) {
    queue<BinaryTree*> queueData;

    int target = root->data;

    if (root == nullptr) return true;
    queueData.push(root);

    while (!queueData.empty()) {
        BinaryTree* currentNode = queueData.front();
        queueData.pop();

        if (currentNode->data != target) return false;

        if (currentNode->left != nullptr) queueData.push(currentNode->left);
        if (currentNode->right != nullptr) queueData.push(currentNode->right);
    }

    return true;
}