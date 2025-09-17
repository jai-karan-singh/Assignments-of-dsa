#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertBeginning(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void insertEnd(int val) {
        Node* temp = new Node(val);
        if (!head) { head = temp; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = temp;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertBeginning(val); return; }
        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (t->next) {
            Node* temp = new Node(val);
            temp->next = t->next;
            t->next = temp;
        }
    }

    void insertAfter(int key, int val) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (t) {
            Node* temp = new Node(val);
            temp->next = t->next;
            t->next = temp;
        }
    }

    void deleteBeginning() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* t = head;
        while (t->next->next) t = t->next;
        delete t->next;
        t->next = NULL;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) { deleteBeginning(); return; }
        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (t->next) {
            Node* del = t->next;
            t->next = del->next;
            delete del;
        }
    }

    void search(int key) {
        Node* t = head; int pos = 1;
        while (t) {
            if (t->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            t = t->next; pos++;
        }
        cout << "Not Found\n";
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList l;
    int choice, val, key;
    do {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertBefore 4.InsertAfter\n";
        cout << "5.DelBeg 6.DelEnd 7.DelNode 8.Search 9.Display 10.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cin >> val; l.insertBeginning(val); break;
            case 2: cin >> val; l.insertEnd(val); break;
            case 3: cin >> key >> val; l.insertBefore(key,val); break;
            case 4: cin >> key >> val; l.insertAfter(key,val); break;
            case 5: l.deleteBeginning(); break;
            case 6: l.deleteEnd(); break;
            case 7: cin >> key; l.deleteNode(key); break;
            case 8: cin >> key; l.search(key); break;
            case 9: l.display(); break;
        }
    } while(choice != 10);
    return 0;
}
