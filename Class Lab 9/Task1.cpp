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

int getHeight(Node *n) {
    return n == NULL ? 0 : n->height;
}

int getMax(int a, int b) {
    return a > b ? a : b;
}

int getBalance(Node *n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* insertNode(Node* node, int key) {
    if (node == NULL)
        return new Node(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
        root = insertNode(root, arr[i]);

    root = insertNode(root, 15);

    cout << "Preorder after inserting 15: ";
    preOrder(root);
    cout << endl;

    cout << "Height of AVL tree: " << getHeight(root) << endl;

    return 0;
}
