#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* nxt) : val(x), next(nxt) {}
};

class List {
public:
    Node* head;
    List() : head(nullptr) {}
    List(Node* h) : head(h) {}

    static List* makeFromVec(const vector<int>& arr) {
        if (arr.empty()) return new List();
        Node* h = new Node(arr[0]);
        Node* cur = h;
        for (int i = 1; i < arr.size(); i++) {
            cur->next = new Node(arr[i]);
            cur = cur->next;
        }
        return new List(h);
    }

    void pushFront(int x) {
        head = new Node(x, head);
    }

    void pushBack(int x) {
        if (!head) {
            head = new Node(x);
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new Node(x);
    }

    void show() const {
        Node* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    vector<int> toVec() const {
        vector<int> arr;
        Node* cur = head;
        while (cur) {
            arr.push_back(cur->val);
            cur = cur->next;
        }
        return arr;
    }

    void sortList() {
        if (!head || !head->next) return;
        vector<int> arr = toVec();
        sort(arr.begin(), arr.end());
        Node* cur = head;
        for (int x : arr) {
            cur->val = x;
            cur = cur->next;
        }
    }

    void concat(List* l) {
        if (!head) {
            head = l->head;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = l->head;
    }

    Node* middle() const {
        if (!head) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void removeDup() {
        if (!head || !head->next) return;
        vector<int> arr = toVec();
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        Node* cur = head;
        for (int x : arr) {
            cur->val = x;
            if (!cur->next && &x != &arr.back()) {
                cur->next = new Node(0);
            }
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < arr.size() - 1; i++) cur = cur->next;
        cur->next = nullptr;
    }

    void mergeSorted(List* l) {
        Node* cur2 = l->head;

        while (cur2 && cur2->val < head->val) {
            Node* n = new Node(cur2->val, head);
            head = n;
            cur2 = cur2->next;
        }

        Node* cur1 = head;
        while (cur2) {
            if (!cur1->next || cur1->next->val >= cur2->val) {
                Node* n = new Node(cur2->val, cur1->next);
                cur1->next = n;
                cur2 = cur2->next;
                cur1 = cur1->next;
            } else {
                cur1 = cur1->next;
            }
        }
    }
};

int main() {
    vector<int> v1 = {12, 3, 7, 19, 1};
    List* L1 = List::makeFromVec(v1);

    cout << "Original List: " << endl;
    L1->show();

    L1->sortList();
    cout << "Sorted List: " << endl;
    L1->show();

    vector<int> v2 = {8, 14, 2, 9, 6};
    List* L2 = List::makeFromVec(v2);
    cout << "Another List: " << endl;
    L2->show();

    L1->concat(L2);
    cout << "After Concatenation: " << endl;
    L1->show();

    Node* mid = L1->middle();
    if (mid) {
        cout << "Middle element is: " << mid->val << endl;
    } else {
        cout << "List is empty!" << endl;
    }

    L2->sortList();
    cout << "Sorted second list: " << endl;
    L2->show();

    L1->mergeSorted(L2);
    cout << "After Merging: " << endl;
    L1->show();

    L1->removeDup();
    cout << "After Removing Duplicates: " << endl;
    L1->show();

    return 0;
}
