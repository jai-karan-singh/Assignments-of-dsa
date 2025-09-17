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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void display(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int n, val; cin >> n;
    for (int i = 0; i < n; i++) { cin >> val; insertEnd(head, val); }
    head = reverse(head);
    display(head);
    return 0;
}
