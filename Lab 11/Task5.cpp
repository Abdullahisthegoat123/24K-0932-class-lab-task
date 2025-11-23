#include <iostream>
#include <string>
using namespace std;

class EmployeeHashTable {
private:
    int size;
    string table[50];
    bool occupied[50];

    int primaryHash(const string& s){
        int sum = 0;
        for (char c : s) sum += (char)c;
        return sum % 50;
    }

    int secondaryHash(const string& s){
        int sum = 0;
        for (char c : s) sum += (char)c;
        return 7 - (sum % 7);
    }

public:
    EmployeeHashTable() {
        size = 50;
        for (int i = 0; i < size; ++i) {
            occupied[i] = false;
            table[i].clear();
        }
    }

    void Add_Employee(const string& name) {
        int h1 = primaryHash(name);
        int h2 = secondaryHash(name);

        if (!occupied[h1]) {
            table[h1] = name;
            occupied[h1] = true;
            return;
        }
        if (occupied[h1] && table[h1] == name) return;

        for (int i = 1; i < size; ++i) {
            int idx = (h1 + i * h2) % 50;
            if (!occupied[idx]) {
                table[idx] = name;
                occupied[idx] = true;
                return;
            }
            if (table[idx] == name) return;
        }
        cout << "Directory is full. Could not add employee.\n";
    }

    void Search_Employee(const string& name){
        int h1 = primaryHash(name);
        int h2 = secondaryHash(name);

        if (occupied[h1] && table[h1] == name) {
            cout<<"Employee found: ";
            cout << name << "\n";
            return;
        }
        if (!occupied[h1]) {
            cout << "Employee not found in the directory.\n";
            return;
        }
        for (int i = 1; i < size; ++i) {
            int idx = (h1 + i * h2) % 50;
            if (!occupied[idx]) {
                cout << "Employee not found in the directory.\n";
                return;
            }
            if (table[idx] == name) {
                cout << name << "\n";
                return;
            }
        }
        cout << "Employee not found in the directory.\n";
    }

    void Display_Table() const {
        for (int i = 0; i < size; ++i) {
            if (occupied[i]) cout << i << ": " << table[i] << "\n";
            else cout << i << ": " << "\n";
        }
    }
};

int main() {
    EmployeeHashTable ht;
    ht.Add_Employee("Abdullah");
    ht.Add_Employee("Karim");
    ht.Add_Employee("Goat");
    cout<<"Employee table:"<<endl;
    ht.Display_Table();
    cout<<"\nSearching employee:"<<endl;
    ht.Search_Employee("Abdullah");
    ht.Search_Employee("saad");

    
    return 0;
}
