#include <iostream>
using namespace std;

int arr[100], n = 0;

void create() {
    cout << "Enter size: ";
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void display() {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insert() {
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deletePos() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void search() {
    int val, f = 0;
    cout << "Enter value: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) { f = 1; break; }
    }
    if (f) cout << "Found\n";
    else cout << "Not Found\n";
}

int main() {
    int ch;
    do {
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cin >> ch;
        if (ch == 1) create();
        else if (ch == 2) display();
        else if (ch == 3) insert();
        else if (ch == 4) deletePos();
        else if (ch == 5) search();
    } while (ch != 6);
    return 0;
}

