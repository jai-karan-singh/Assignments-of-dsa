#include <iostream>
#define SIZE 5
using namespace std;

class CQueue {
    int arr[SIZE], front, rear;
public:
    CQueue() { front = -1; rear = -1; }
    bool isFull() { return (front == 0 && rear == SIZE - 1) || (front == rear + 1); }
    bool isEmpty() { return front == -1; }
    void enqueue(int x) {
        if (isFull()) cout << "Queue Full\n";
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
        }
    }
    void dequeue() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            cout << "Deleted: " << arr[front] << "\n";
            if (front == rear) front = rear = -1;
            else front = (front + 1) % SIZE;
        }
    }
    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << "\n";
    }
    void display() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << "\n";
        }
    }
};

int main() {
    CQueue q; int choice, val;
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
