#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
private:
    bool checkFull(Node* node) {
        if (node == NULL) return true;
        if (node->left == NULL && node->right == NULL) return true;
        if (node->left != NULL && node->right != NULL)
            return checkFull(node->left) && checkFull(node->right);
        return false;
    }

public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* newNode(int val) {
        return new Node(val);
    }

    bool isFullTree() {
        return checkFull(root);
    }
};

int main() {
    BinaryTree tree;

    tree.root = tree.newNode(10);
    tree.root->left = tree.newNode(20);
    tree.root->right = tree.newNode(30);
    tree.root->left->left = tree.newNode(40);
    tree.root->left->right = tree.newNode(50);
    tree.root->right->left = tree.newNode(60);
    tree.root->right->right = tree.newNode(70);

    if (tree.isFullTree())
        cout << "The tree is a full binary tree." << endl;
    else
        cout << "The tree is not a full binary tree." << endl;

    return 0;
}
