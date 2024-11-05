#include <iostream>
#include <string>
#include <cmath>
#include <deque>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

class BinaryTree{
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;
        BinaryTree(int value){ this->data = value;};
        BinaryTree(int value, BinaryTree* left, BinaryTree* right){
            this->data = value;
            this->left = left;
            this->right = right;
        };
};

void postorderTraversalHelper(vector<int> & arr, BinaryTree * currentNode){
    if (currentNode == nullptr) return;

    postorderTraversalHelper(arr, currentNode->left);
    postorderTraversalHelper(arr, currentNode->right);
    arr.push_back(currentNode->data);
}

vector<int> postorderTraversal(BinaryTree* root){
    vector<int> arr;
    postorderTraversalHelper(arr, root);

    return arr;
}