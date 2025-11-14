#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    int height;

    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

int h(Node* n) {
    return n ? n->height : 0;
}

int mx(int a, int b) {
    return a > b ? a : b;
}

int balance(Node* n) {
    return n ? h(n->left) - h(n->right) : 0;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + mx(h(x->left), h(x->right));
    y->height = 1 + mx(h(y->left), h(y->right));

    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + mx(h(y->left), h(y->right));
    x->height = 1 + mx(h(x->left), h(x->right));

    return x;
}

Node* insertNode(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + mx(h(node->left), h(node->right));
    int bf = balance(node);

    if (bf > 1 && key < node->left->key) return rightRotate(node);
    if (bf < -1 && key > node->right->key) return leftRotate(node);
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(Node* r) {
    if (!r) return;
    cout << r->key << " ";
    preorder(r->left);
    preorder(r->right);
}

class AVLTree {
public:
    Node* root;
    AVLTree() { root = NULL; }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void leftRotateRoot() {
        root = leftRotate(root);
    }

    void display() {
        preorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree t;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) t.insert(arr[i]);

    t.insert(55);
    t.leftRotateRoot();
    t.display();

    return 0;
}
