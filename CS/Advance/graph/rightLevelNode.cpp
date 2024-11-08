#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
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

vector<int> rightLevelNode(BinaryTree* root) {
    vector<int> result;
    if (root == nullptr) return result;

    queue<BinaryTree*> queue;
    queue.push(root);

    while (!queue.empty()) {
        int currentLevel = queue.size();

        for (int i = 0; i < currentLevel; i++) {
            BinaryTree* currentNode = queue.front();
            queue.pop();

            if (i == currentLevel - 1) result.push_back(currentNode->data);

            if (currentNode->left != nullptr) queue.push(currentNode->left);
            if (currentNode->right != nullptr) queue.push(currentNode->right);
        }
    }
    return result;
}
