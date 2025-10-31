#include <iostream>
#include <string>
using namespace std;

class TourPackage {
public:
    string name;
    TourPackage* left;
    TourPackage* right;

    TourPackage(string n) {
        name = n;
        left = right = NULL;
    }
};

class TourTree {
private:
    TourPackage* root;

    void display(TourPackage* node, int space) {
        if (node == NULL) return;
        space += 5;
        display(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) cout << " ";
        cout << node->name << endl;
        display(node->left, space);
    }

    TourPackage* add(TourPackage* node, string parent, string name, char side) {
        if (node == NULL) return NULL;
        if (node->name == parent) {
            if (side == 'L' && node->left == NULL)
                node->left = new TourPackage(name);
            else if (side == 'R' && node->right == NULL)
                node->right = new TourPackage(name);
            return node;
        }
        TourPackage* leftResult = add(node->left, parent, name, side);
        if (leftResult != NULL) return leftResult;
        return add(node->right, parent, name, side);
    }

public:
    TourTree() {
        root = NULL;
    }

    void createRoot(string name) {
        if (root == NULL)
            root = new TourPackage(name);
    }

    void addPackage(string parent, string name, char side) {
        if (root == NULL) return;
        add(root, parent, name, side);
    }

    void displayTree() {
        if (root == NULL)
            cout << "No packages to display.\n";
        else
            display(root, 0);
    }
};

int main() {
    TourTree tree;

    tree.createRoot("Abdullah");
    tree.addPackage("Abdullah", "choco", 'L');
    tree.addPackage("Abdullah", "icecream", 'R');
    tree.addPackage("choco", "roti", 'L');
    tree.addPackage("choco", "naan", 'R');
    tree.addPackage("icecream", "puri", 'L');
    tree.addPackage("icecream", "chicken", 'R');

    cout << "TOUR PACKAGE HIERARCHY\n";
    tree.displayTree();

    return 0;
}
