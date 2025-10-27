#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;
    for (char c : s) {
        if (isalnum(c)) result += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) > 0 &&
                  ((prec(c) < prec(st.top())) ||
                   (prec(c) == prec(st.top()) && !isRightAssociative(c)))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    cout<<"Infix expression: a+b*(c^d-e)^(f+g*h)-i"<<endl;
    string expr = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<"Postfix Expression: ";
    cout << infixToPostfix(expr);
}