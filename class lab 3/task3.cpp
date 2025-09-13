#include <iostream>
using namespace std;

class Compartment {
public:
    int num;
    Compartment* nxt;
    Compartment* prv;

    Compartment(int x) : num(x), nxt(nullptr), prv(nullptr) {}
};

class Train {
private:
    Compartment* start;

public:
    Train() : start(nullptr) {}

    ~Train() {
        Compartment* cur = start;
        while (cur) {
            Compartment* nxtNode = cur->nxt;
            delete cur;
            cur = nxtNode;
        }
    }

    void removeFront() {
        if (!start) return;
        Compartment* temp = start;
        start = start->nxt;
        if (start) start->prv = nullptr;
        delete temp;
    }

    bool find(int key) {
        Compartment* cur = start;
        while (cur) {
            if (cur->num == key) return true;
            cur = cur->nxt;
        }
        return false;
    }

    void insertEnd(int val) {
        Compartment* node = new Compartment(val);
        if (!start) {
            start = node;
            return;
        }
        Compartment* cur = start;
        while (cur->nxt) {
            cur = cur->nxt;
        }
        cur->nxt = node;
        node->prv = cur;
    }

    void show() {
        cout << "Train: ";
        Compartment* cur = start;
        while (cur) {
            cout << cur->num << " <-> ";
            cur = cur->nxt;
        }
        cout << "null" << endl;
    }
};

int main() {
    Train t;

    t.insertEnd(5);
    t.insertEnd(15);
    t.insertEnd(25);
    t.insertEnd(35);
    cout << "Initial compartments:" << endl;
    t.show();

    cout << "Searching 25: ";
    if (t.find(25)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching 50: ";
    if (t.find(50)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    t.removeFront();
    cout << "After removing first compartment:" << endl;
    t.show();

    t.removeFront();
    cout << "After removing another compartment:" << endl;
    t.show();

    return 0;
}
