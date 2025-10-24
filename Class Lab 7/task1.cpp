#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(string name, int score) {
        Node* newNode = new Node(name, score);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    int getMaxScore() {
        int maxScore = 0;
        Node* temp = head;
        while (temp) {
            if (temp->score > maxScore)
                maxScore = temp->score;
            temp = temp->next;
        }
        return maxScore;
    }

    void radixSort() {
        int exp = 1;
        int maxScore = getMaxScore();
        while (maxScore / exp > 0) {
            sortByDigit(exp);
            exp *= 10;
        }
    }

    void sortByDigit(int exp) {
        Node* buckets[10] = {nullptr};
        Node* tails[10] = {nullptr};
        Node* temp = head;
        while (temp) {
            int digit = (temp->score / exp) % 10;
            Node* nextNode = temp->next;
            temp->next = nullptr;
            if (!buckets[digit]) {
                buckets[digit] = tails[digit] = temp;
            } else {
                tails[digit]->next = temp;
                tails[digit] = temp;
            }
            temp = nextNode;
        }
        Node* newHead = nullptr;
        Node* newTail = nullptr;
        for (int i = 0; i < 10; i++) {
            if (buckets[i]) {
                if (!newHead) {
                    newHead = buckets[i];
                    newTail = tails[i];
                } else {
                    newTail->next = buckets[i];
                    newTail = tails[i];
                }
            }
        }
        head = newHead;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->name << " " << temp->score << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name and score of student " << i + 1 << ": ";
        cin >> name >> score;
        list.append(name, score);
    }
    cout << "\nOriginal list:\n";
    list.print();
    list.radixSort();
    cout << "\nSorted list:\n";
    list.print();
    return 0;
}
