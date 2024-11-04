#include <iostream>
#include <string>

using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class BinaryTree {
   public:
    Node* root;
    Node* left;
    Node* right;

    BinaryTree(int root) {
        this->root = new Node(root);
        this->left = NULL;
        this->right = NULL;
    }
};

void entry() {
    BinaryTree binaryTree(10);
    BinaryTree node2(6);
    BinaryTree node3(8);

    binaryTree.left = node2.root;
    binaryTree.right = node3.root;

    cout << binaryTree.root->data << endl;
    cout << binaryTree.left->data << endl;
    cout << binaryTree.right->data << endl;
}