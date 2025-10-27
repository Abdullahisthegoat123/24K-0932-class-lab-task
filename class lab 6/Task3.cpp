#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    string url;
    Node *next;
    Node(string u) : url(u), next(NULL) {}
};

void addAtBeginning(Node *&head, string url)
{
    Node *newNode = new Node(url);
    newNode->next = head;
    head = newNode;
}

void DeleteAtBeginning(Node *&head)
{
    if (!head)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

int main()
{
    stack<string> history;
    Node *head = NULL;

    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (string s : sites)
    {
        addAtBeginning(head, s);
        history.push(s);
    }

    cout << "Current page of Original Linked list: " << history.top() << endl;
    cout << "Original Linked list:\n";
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        cout << curr->url << " ";
    }
    cout << endl
         << endl;
    history.pop();
    DeleteAtBeginning(head);
    history.pop();
    DeleteAtBeginning(head);
    
    cout << "After clicking Back button twice: " << endl;
    cout << "Current page: " << history.top() << endl;
    cout << "Linked list after clicking back:\n";
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        cout << curr->url << " ";
    }
}