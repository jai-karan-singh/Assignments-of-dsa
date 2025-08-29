#include <iostream>
using namespace std;

bool isBalanced(string expr) {
    int n = expr.length();
    char stack[n];   
    int top = -1;    

    for (int i = 0; i < n; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return false; 

            char topChar = stack[top--];

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return (top == -1);
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Expression is balanced" << endl;
    else
        cout << "Expression is NOT balanced" << endl;

    return 0;
}
