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

int deepestLeaves(BinaryTree* root) {
    if (root == nullptr) return 0;

    queue<BinaryTree*> queueData;
    queueData.push(root);
    int deepestSum;

    while (!queueData.empty()) {
        int currentLevel = queueData.size();
        deepestSum = 0;

        for (int i = 0; i < currentLevel; i++) {
            BinaryTree* currentNode = queueData.front();
            queueData.pop();

            deepestSum += currentNode->data;

            if (currentNode->left) queueData.push(currentNode->left);
            if (currentNode->right) queueData.push(currentNode->right);
        }
    }

    return deepestSum;
}
