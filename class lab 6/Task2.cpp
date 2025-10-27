#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string in;
    cout << "Enter Postfix Expression: ";
    cin >> in;

    stack<int> s;

    for (int i = 0; i < in.length(); i++)
    {
        if (isdigit(in[i]))
        {
            s.push(in[i] - '0');
        }
        else
        {
            int oper2 = s.top();
            s.pop();
            int oper1 = s.top();
            s.pop();

            switch (in[i])
            {
            case '+':
                s.push(oper1 + oper2);
                break;
            case '-':
                s.push(oper1 - oper2);
                break;
            case '*':
                s.push(oper1 * oper2);
                break;
            case '/':
                s.push(oper1 / oper2);
                break;
            }
        }
    }

    cout << "The answer is: " << s.top() << endl;
    return 0;
}