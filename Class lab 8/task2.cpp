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
    int countNodes(Node* node) {
        if (node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaves(Node* node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int calcHeight(Node* node) {
        if (node == NULL) return 0;
        int leftH = calcHeight(node->left);
        int rightH = calcHeight(node->right);
        return 1 + max(leftH, rightH);
    }

public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* createNode(int val) {
        return new Node(val);
    }

    int totalNodes() {
        return countNodes(root);
    }

    int totalLeafNodes() {
        return countLeaves(root);
    }

    int height() {
        return calcHeight(root);
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.createNode(5);
    tree.root->left = tree.createNode(3);
    tree.root->right = tree.createNode(8);
    tree.root->left->left = tree.createNode(1);
    tree.root->left->right = tree.createNode(4);
    tree.root->right->left = tree.createNode(7);

    cout << "Total Nodes: " << tree.totalNodes() << endl;
    cout << "Leaf Nodes: " << tree.totalLeafNodes() << endl;
    cout << "Height of Tree: " << tree.height() << endl;

    return 0;
}
