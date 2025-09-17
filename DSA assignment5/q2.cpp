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

int deleteOccurrences(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* t = curr->next;
            curr->next = t->next;
            delete t;
            count++;
        } else curr = curr->next;
    }
    return count;
}

void display(Node* head) {
    while (head) { cout << head->data; if(head->next) cout<<"->"; head = head->next; }
    cout << "\n";
}

int main() {
    Node* head = NULL;
    int n, val, key;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> val; insertEnd(head, val); }
    cin >> key;
    int c = deleteOccurrences(head, key);
    cout << "Count: " << c << " , Updated Linked List: ";
    display(head);
    return 0;
}
