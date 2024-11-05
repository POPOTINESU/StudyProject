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

BinaryTree* sortedArrToBST(vector<int> numberList) {
    if (numberList.size() == 1) return new BinaryTree(numberList[0]);

    int center = numberList.size() / 2;
    center = (numberList.size() % 2 == 0) ? center - 1 : center;

    BinaryTree* centerNode = new BinaryTree(numberList[center]);
    BinaryTree* left = nullptr;
    BinaryTree* right;

    // numberList size 2だった場合必ず、centerとrightに入る
    if (numberList.size() == 2) {
        centerNode = new BinaryTree(numberList[0]);
        centerNode->right = new BinaryTree(numberList[1]);
    } else {
        centerNode->left = sortedArrToBST(
            vector<int>(numberList.begin(), numberList.begin() + center));
        centerNode->right = sortedArrToBST(
            vector<int>(numberList.begin() + center + 1, numberList.end()));
    }

    return centerNode;
}
