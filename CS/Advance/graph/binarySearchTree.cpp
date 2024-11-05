
#include <cmath>
#include <iostream>
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
};

class BinarySearchTree {
   public:
    BinaryTree* root;

    BinarySearchTree(vector<int> array) {
        this->root = binarySearchTreeHelper(array, 0, array.size() - 1);
    }

    BinaryTree* search(int key) {
        BinaryTree* current = this->root;

        while (current != nullptr) {
            if (current->data == key) {
                return current;
            } else if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return nullptr;
    }

    bool keyExist(int key) {
        BinaryTree* current = this->root;

        while (current != NULL) {
            if (current->data == key) return true;

            current = (current->data < key) ? current->left : current->right;
        }

        return false;
    }

   private:
    BinaryTree* binarySearchTreeHelper(vector<int>& arr, int start, int end) {
        if (start > end) return nullptr;

        int center = (start + end) / 2;
        BinaryTree* left = binarySearchTreeHelper(arr, start, center - 1);
        BinaryTree* right = binarySearchTreeHelper(arr, center + 1, end);

        return new BinaryTree(arr[center], left, right);
    }
};

int main() {
    BinarySearchTree* balancedBST =
        new BinarySearchTree({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    cout << boolalpha << balancedBST->keyExist(6) << endl;
    cout << balancedBST->search(6) << endl;
    cout << boolalpha << balancedBST->keyExist(2) << endl;
    cout << balancedBST->search(2) << endl;
    cout << balancedBST->search(34) << endl;
}