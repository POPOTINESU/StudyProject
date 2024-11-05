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
BinaryTree* sortedArrToBSTHelper(vector<int> numberList, int start, int end) {
    if (start == end) return new BinaryTree(numberList[start]);

    int center = (start + end) / 2;
    BinaryTree* left = sortedArrToBSTHelper(numberList, start, center - 1);
    BinaryTree* right = sortedArrToBSTHelper(numberList, center + 1, end);

    BinaryTree* centerNode = new BinaryTree(numberList[center], left, right);

    return centerNode;
}

BinaryTree* sortedArrToBST(vector<int> numberList) {
    return sortedArrToBSTHelper(numberList, 0, numberList.size()-1);
}
