#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int evaluatePostfix(string postfix) {
    Stack s;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int b = s.pop();
            int a = s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (digits only): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
