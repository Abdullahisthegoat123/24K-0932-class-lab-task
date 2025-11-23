#include <iostream>
#include <string>
using namespace std;

class StudentHashTable {
private:
    int size;
    int rolls[15];
    string names[15];
    bool occupied[15];

    int hashFn(int key) const {
        return key % size;
    }

public:
    StudentHashTable() {
        size = 15;
        for (int i = 0; i < size; ++i) {
            occupied[i] = false;
            rolls[i] = 0;
            names[i] = "";
        }
    }

    void InsertRecord(int roll, const string& name) {
        int base = hashFn(roll);
        for (int attempt = 0; attempt < size; ++attempt) {
            int idx = (base + attempt * attempt) % size;
            if (!occupied[idx]) {
                occupied[idx] = true;
                rolls[idx] = roll;
                names[idx] = name;
                return;
            }
            if (occupied[idx] && rolls[idx] == roll) {
                names[idx] = name;
                return;
            }
        }
        cout << "Hash table is full. Could not insert record.\n";
    }

    void SearchRecord(int roll) const {
        int base = hashFn(roll);
        for (int attempt = 0; attempt < size; ++attempt) {
            int idx = (base + attempt * attempt) % size;
            if (!occupied[idx]) {
                cout << "Record not found\n";
                return;
            }
            if (rolls[idx] == roll) {
                cout<<"Record found: ";
                cout << names[idx] << "\n";
                return;
            }
        }
        cout << "Record not found\n";
    }
};

int main() {
    StudentHashTable ht;
    ht.InsertRecord(100, "Abdullah");
    ht.InsertRecord(101, "Karim");
    ht.InsertRecord(102, "Goat");
    ht.SearchRecord(100);
    ht.SearchRecord(101);
    ht.SearchRecord(121);
    return 0;
}
