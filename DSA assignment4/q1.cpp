#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isFull() { return rear == SIZE - 1; }
    bool isEmpty() { return front == -1 || front > rear; }
    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
        }
    }
    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Deleted: " << arr[front++] << "\n";
    }
    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front: " << arr[front] << "\n";
    }
    void display() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Queue q; int choice, val;
    do {
        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    } while(choice != 5);
    return 0;
}
