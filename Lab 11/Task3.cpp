#include <iostream>
using namespace std;

class Hash {
private:
    int data[100];
    int count;

public:
    Hash() {
        count = 0;
    }

    void insert(int value) {
        int pos = count - 1;
        while (pos >= 0 && data[pos] > value) {
            data[pos + 1] = data[pos];
            pos--;
        }
        data[pos + 1] = value;
        count++;
    }

    void deleteValue(int value) {
        int idx = -1;
        for (int i = 0; i < count; i++) {
            if (data[i] == value) {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return;

        for (int i = idx; i < count - 1; i++)
            data[i] = data[i + 1];

        count--;
    }

    void search(int value) {
        for (int i = 0; i < count; i++) {
            if (data[i] == value) {
                cout << value << " found" << endl;
                return;
            }
        }
        cout << value << " not found" << endl;
    }

    void display() {
        for (int i = 0; i < count; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Hash hashTable;
    hashTable.insert(1);
    hashTable.insert(3);
    hashTable.insert(4);
    hashTable.insert(5);
    hashTable.insert(7);

    hashTable.display();

    cout << "Removing 4" << endl;
    hashTable.deleteValue(4);

    hashTable.display();

    hashTable.search(5);
    hashTable.search(6);

    return 0;
}
