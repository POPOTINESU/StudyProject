#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>
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

    void preorderTraversalHelper(vector<int>& arr, BinaryTree* currentNode) {
        if (currentNode == nullptr) return;

        arr.push_back(currentNode->data);
        preorderTraversalHelper(arr, currentNode->left);
        preorderTraversalHelper(arr, currentNode->right);
    }
};

vector<int> preorderTraversal(BinaryTree* root) {
    vector<int> arr;
    root->preorderTraversalHelper(arr, root);
    return arr;
}
