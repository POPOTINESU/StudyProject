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

bool isCompleteBinaryTree(BinaryTree* root) {
    queue<BinaryTree*> queue;
    queue.push(root);

    while (!queue.empty()) {
        int queueSize = queue.size();
        bool isNullCounter = false;
        for (int i = 0; i < queueSize; i++) {
            BinaryTree* currentNode = queue.front();
            queue.pop();

            if (!isNullCounter && currentNode == nullptr)
                isNullCounter = true;
            else if (isNullCounter && currentNode != nullptr)
                return false;

            if (currentNode != nullptr) queue.push(currentNode->left);
            if (currentNode != nullptr) queue.push(currentNode->right);
        }
    }
    return true;
}
