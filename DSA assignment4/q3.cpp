#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    int half = n / 2;
    queue<int> firstHalf;
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front()); q.pop();
    }
    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); firstHalf.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    int n, val; cin >> n;
    for (int i = 0; i < n; i++) { cin >> val; q.push(val); }
    interleave(q);
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    return 0;
}
