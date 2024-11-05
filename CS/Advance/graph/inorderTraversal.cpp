#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
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

    void binaryToInorderTraversal(vector<int>& arr, BinaryTree* currentNode) {
        if (currentNode == nullptr) return;
        binaryToInorderTraversal(arr, currentNode->left);
        arr.push_back(currentNode->data);
        binaryToInorderTraversal(arr, currentNode->left);
    }
};

vector<int> inorderTraversal(BinaryTree* root) {
    vector<int> arr;
    root->binaryToInorderTraversal(arr, root);

    return arr;
}
