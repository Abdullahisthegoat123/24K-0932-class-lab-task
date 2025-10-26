#include <iostream>
#include <string>
using namespace std;

class Call {
public:
    string name;
    string number; 
    int duration;
};

class CallStack {
private:
    Call calls[100];
    int topIndex;

public:
    CallStack() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool full() {
        return topIndex == 99;
    }

    void push(Call c) {
        if (full()) {
            cout << "Call log is full!\n";
            return;
        }
        calls[++topIndex] = c;
        cout << "Call added.\n";
        display();
    }

    void pop() {
        if (empty()) {
            cout << "No call history to delete.\n";
            return;
        }
        cout << "Deleting call: " << calls[topIndex].name << "\n";
        topIndex--;
        display();
    }

    void top() {
        if (empty()) {
            cout << "No recent calls.\n";
            return;
        }
        cout << "Most recent call:\n";
        cout << "Name: " << calls[topIndex].name
             << " | Number: " << calls[topIndex].number
             << " | Duration: " << calls[topIndex].duration << " sec\n";
    }

    void display() {
        if (empty()) {
            cout << "Call log is empty.\n";
            return;
        }
        cout << "\n ---Current Call Log--- \n";
        for (int i = topIndex; i >= 0; i--) {
            cout << i + 1 << ". Name: " << calls[i].name<<endl; 
            cout << "Number: " << calls[i].number<<endl; 
            cout << "Duration: " << calls[i].duration << " sec\n";
        }
        cout << "-------------------------\n\n";
    }
};

int main() {
    CallStack history;
    int choice;
    do {
        cout << "1. Add Call (Push)\n";
        cout << "2. Delete Most Recent Call (Pop)\n";
        cout << "3. View Most Recent Call (Top)\n";
        cout << "4. Check if Call Log is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Call c;
            cout << "Enter Name: ";
            getline(cin, c.name);
            cout << "Enter Number: ";
            getline(cin, c.number);
            cout << "Enter Duration (in seconds): ";
            cin >> c.duration;
            history.push(c);
        }
        else if (choice == 2) {
            history.pop();
        }
        else if (choice == 3) {
            history.top();
        }
        else if (choice == 4) {
            if (history.empty())
                cout << "Call log is empty.\n";
            else
                cout << "Call log has entries.\n";
        }
        else if (choice != 5) {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    cout << "Exiting program.\n";
    return 0;
}
