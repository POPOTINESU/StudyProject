#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <stack>
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

BinaryTree* mergeBST(BinaryTree* root1, BinaryTree* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return nullptr;
    }

    int val1 = (root1 != nullptr) ? root1->data : 0;
    int val2 = (root2 != nullptr) ? root2->data : 0;

    BinaryTree* newNode = new BinaryTree(val1 + val2);

    newNode->left = mergeBST((root1 != nullptr) ? root1->left : nullptr,
                             (root2 != nullptr) ? root2->left : nullptr);
    newNode->right = mergeBST((root1 != nullptr) ? root1->right : nullptr,
                              (root2 != nullptr) ? root2->right : nullptr);

    return newNode;
}
