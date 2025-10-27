#include <iostream>
#include <stack>
using namespace std;

int main() {
    string in;
    cout<<"Enter your input: ";
    cin>>in;

    stack<int> s;
    for(int i=in.length()-1;i>=0;i--) {
        if(isdigit(in[i])) s.push(in[i] - '0');
        else {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            switch (in[i]) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    cout<<"\nThe Answer is: "<<s.top();
}