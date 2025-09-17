#include <iostream>
#include <queue>
using namespace std;

// Stack using Two Queues
class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) cout << "Empty\n";
        else q1.pop();
    }
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    bool empty() { return q1.empty(); }
};

// Stack using One Queue
class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) cout << "Empty\n";
        else q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    bool empty() { return q.empty(); }
};

int main() {
    StackTwoQ st2;
    StackOneQ st1;
    int choice, val;

    do {
        cout << "\nChoose:\n";
        cout << "1. Push (Two Queues)\n2. Pop (Two Queues)\n3. Top (Two Queues)\n";
        cout << "4. Push (One Queue)\n5. Pop (One Queue)\n6. Top (One Queue)\n7. Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cin >> val; st2.push(val); break;
            case 2: st2.pop(); break;
            case 3: cout << "Top (Two Q): " << st2.top() << "\n"; break;
            case 4: cin >> val; st1.push(val); break;
            case 5: st1.pop(); break;
            case 6: cout << "Top (One Q): " << st1.top() << "\n"; break;
        }
    } while(choice != 7);
    return 0;
}
