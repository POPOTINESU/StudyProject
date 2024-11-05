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
};
void reverseInorderTraversal(vector<int> &arr, BinaryTree* currentNode) {
    if (currentNode == nullptr) return;

    reverseInorderTraversal(arr, currentNode->right);
    arr.push_back(currentNode->data);
    reverseInorderTraversal(arr, currentNode->left);
}
vector<int> reverseInorderTraversal(BinaryTree* root) {
    // 関数を完成させてください
    vector<int> arr;
    reverseInorderTraversal(arr, root);

    return arr;
}