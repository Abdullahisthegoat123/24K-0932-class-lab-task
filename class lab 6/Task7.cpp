#include <iostream>
#include <queue>
using namespace std;

class Patron
{
    string name;

public:
    Patron(string name = "") : name(name) {}
    string getName() const { return name; }
};

int main()
{
    queue<Patron> q;
    int enter = 0;
    while (enter != 4)
    {
        cout << " 1 - Add Patron\n";
        cout << " 2 - Serve Patron\n";
        cout << " 3 - Show Current Queue\n";
        cout << " 4 - Exit\n";
        cout << "Enter your choice: ";
        cin >> enter;
        cout << endl;

        switch (enter)
        {
        case 1:
        {
            string name;
            cout << "Enter patron name: ";
            cin >> name;
            q.push(Patron(name));
            cout << name << " has been added to the queue.\n";
            break;
        }
        case 2:
        {
            if (!q.empty())
            {
                cout << "Now serving: " << q.front().getName() << endl;
                q.pop();
            }
            else
                cout << "No patrons in the queue.\n";
            break;
        }
        case 3:
        {
            if (q.empty())
                cout << "No patrons are currently waiting.\n";
            else
            {
                queue<Patron> temp = q;
                cout << "Current queue:\n";
                cout << "-------------------------------------\n";
                int count = 1;
                while (!temp.empty())
                {
                    cout << count++ << ". " << temp.front().getName() << endl;
                    temp.pop();
                }
                cout << "-------------------------------------\n";
            }
            break;
        }
        case 4:
            cout << "Exiting the system...\n";
            break;
        default:
            cout << "Invalid input. Please try again.\n";
        }
    }
}
