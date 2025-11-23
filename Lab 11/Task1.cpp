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

class HashTable {
    public:
    Node** table;
    int buckets;
    int hashfn(string s) {
        int sum = 0;
        for (char c : s) sum += c;
        return sum % buckets;
    }

    HashTable(int n) {
        buckets = n;
        table = new Node*[buckets];
        for (int i = 0; i < buckets; i++) table[i] = nullptr;
    }
    void insert(string s) {
        int i = hashfn(s);
        Node* n = new Node(s);
        n->next = table[i];
        table[i] = n;
    }
    bool search(string s) {
        int i = hashfn(s);
        Node* cur = table[i];
        while (cur) {
            if (cur->key == s) return true;
            cur = cur->next;
        }
        return false;
    }
    void print() {
        cout << "Hash Table:\n";
        for (int i = 0; i < buckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* cur = table[i];
            while (cur) {
                cout << cur->key << " -> ";
                cur = cur->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert("apple");
    ht.insert("mango");
    ht.insert("apple");
    ht.insert("grapes");
    ht.insert("peach");
    ht.insert("banana");
    ht.print();
    cout << "\nSearching apple: ";
    if (ht.search("apple")){
         cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }
    cout << "Searching orange: ";
    if (ht.search("orange")) {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }
}
