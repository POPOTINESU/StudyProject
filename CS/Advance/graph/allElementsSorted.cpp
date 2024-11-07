#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
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

vector<int> allElementsSorted(BinaryTree* root1, BinaryTree* root2) {
    stack<BinaryTree*> stack1, stack2;
    vector<int> answer;

    while (root1 != nullptr || !stack1.empty() || root2 != nullptr ||
           !stack2.empty()) {
        // 再帰をstackを使って表現
        while (root1 != nullptr) {
            stack1.push(root1);
            root1 = root1->left;
        }

        while (root2 != nullptr) {
            stack2.push(root2);
            root2 = root2->left;
        }

        if (stack2.empty() ||
            (!stack1.empty() && stack1.top()->data <= stack2.top()->data)) {
            root1 = stack1.top();
            stack1.pop();
            answer.push_back(root1->data);
            root1 = root1->right;
        } else {
            root2 = stack2.top();
            stack2.pop();
            answer.push_back(root2->data);
            root2 = root2->right;
        }
    }

    return answer;
}
