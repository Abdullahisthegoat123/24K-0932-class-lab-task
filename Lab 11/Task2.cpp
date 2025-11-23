#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    Node* next;
    Node(string k) {
        key = k;
        next = nullptr;
    }
};

class Dictionary {
    Node* table[100];
    int hashfn(string s) {
        int sum = 0;
        for (char c : s) sum += c;
        return sum % 100;
    }
public:
    Dictionary() {
        for (int i = 0; i < 100; i++) table[i] = nullptr;
    }
    void Add_Record(string s) {
        int i = hashfn(s);
        Node* n = new Node(s);
        n->next = table[i];
        table[i] = n;
    }
    void Word_Search(string s) {
        int i = hashfn(s);
        Node* cur = table[i];
        while (cur) {
            if (cur->key == s) {
                cout << "Found\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Error: word not available\n";
    }
    void Print_Dictionary() {
        cout << "Dictionary:\n";
        for (int i = 0; i < 100; i++) {
            cout << "Bucket " << i << ": ";
            Node* cur = table[i];
            if (!cur) {
                cout << "NULL\n";
                continue;
            }
            while (cur) {
                cout << cur->key << " -> ";
                cur = cur->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    Dictionary dict;
    int choice;
    string word;

    while (true) {
        cout << "\n1. Add Record\n2. Search Word\n3. Print Dictionary\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter word: ";
            cin >> word;
            dict.Add_Record(word);
        }
        else if (choice == 2) {
            cout << "Enter word to search: ";
            cin >> word;
            dict.Word_Search(word);
        }
        else if (choice == 3) {
            dict.Print_Dictionary();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
