#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node* partition(Node* low, Node* high) {
        int pivot = high->data;
        Node* i = low->prev;
        for (Node* j = low; j != high; j = j->next) {
            if (j->data <= pivot) {
                i = (i == nullptr) ? low : i->next;
                swap(i, j);
            }
        }
        i = (i == nullptr) ? low : i->next;
        swap(i, high);
        return i;
    }
    
    void quickSort(Node* low, Node* high) {
        if (low && high && low != high && low != high->next) {
            Node* pi = partition(low, high);
            quickSort(low, pi->prev);
            quickSort(pi->next, high);
        }
    }

    void quickSort() {
        quickSort(head, tail());
    }

    Node* tail() {
        Node* temp = head;
        while (temp && temp->next) {
            temp = temp->next;
        }
        return temp;
    }
};

int main() {
    LinkedList list;
    list.append(10);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(1);
    list.append(5);
    list.append(3);
    cout << "Original list: ";
    list.print();
    list.quickSort();
    cout << "Sorted list using quicksort: ";
    list.print();
    return 0;
}
