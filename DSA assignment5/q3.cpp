#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

void insertEnd(Node*& head, int val) {
    Node* temp = new Node(val);
    if (!head) { head = temp; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = temp;
}

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow ? slow->data : -1;
}

int main() {
    Node* head = NULL;
    int n, val; cin >> n;
    for (int i = 0; i < n; i++) { cin >> val; insertEnd(head, val); }
    cout << findMiddle(head);
    return 0;
}
