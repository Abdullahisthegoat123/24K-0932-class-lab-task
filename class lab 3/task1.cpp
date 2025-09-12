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
        cout << "Book List: ";
        StringNode* current = head;
        while (current) {
            cout << current->value << " \n";
            current = current->next;
        }
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
};

int main() {
    LinkedList list;
    list.addAtStart("Artificial intelligence");
    list.addAtStart("operating systems");
    list.addAtEnd("Machine Learning");
    list.insertAfter("operating systems", "cyber security");

    list.display();
    cout<<"Checking if database systems book is in the list: ";
    if(list.find("DataBase systems"))
        cout << "The Book is in the list" << endl;
    else
        cout << "The Book is Not in the list" << endl;

    return 0;
}
