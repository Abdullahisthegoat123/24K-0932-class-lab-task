#include <iostream>
using namespace std;

class StringNode {
public:
    string value;
    StringNode* next;

    StringNode(string val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    StringNode* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        StringNode* current = head;
        while (current) {
            StringNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void addAtStart(string item) {
        if (!head) {
            head = new StringNode(item);
            return;
        }
        StringNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new StringNode(item);
    }

    void addAtEnd(string item) {
        StringNode* newNode = new StringNode(item);
        if (!head) {
            head = newNode;
            return;
        }
        StringNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() {
        cout << "String List: ";
        StringNode* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool find(string item) {
        StringNode* current = head;
        while (current) {
            if (current->value == item)
                return true;
            current = current->next;
        }
        return false;
    }

    void insertAfter(string target, string item) {
        StringNode* current = head;
        while (current) {
            if (current->value == target) {
                StringNode* newNode = new StringNode(item);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
    }

    void deleteFromStart() {
        if (!head) return;
        StringNode* temp = head;
        head = head->next;
        delete temp;
    }

    string searchByPosition(int position) {
        if (position < 0) return "";
        StringNode* current = head;
        int index = 0;
        while (current) {
            if (index == position) {
                return current->value;
            }
            current = current->next;
            index++;
        }
        return "";
    }
};

int main() {
    LinkedList list;
    list.addAtEnd("book1");
    list.addAtEnd("book2");
    list.addAtEnd("book3");

    list.deleteFromStart();
    list.display();

    if (list.find("book2")) {
        cout << "Found book2 in the list." << endl;
    }

    string value = list.searchByPosition(1);
    cout << "Element at position 1: " << value << endl;
    return 0;
}
