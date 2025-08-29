#include <iostream>
using namespace std;

class Test{
    public:
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;  
        }
    }
    return n;  
}


int findMissingBinary(int arr[], int n) {
    int l = 0, r = n - 2;  
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == mid + 1) {
            l = mid + 1;  
        } else {
            r = mid - 1;  
        }
    }
    return l + 1;  
}
};
int main() {
    Test t;
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[n - 1];
    cout << "Enter " << n - 1 << " sorted numbers from 1 to " << n << ": ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number (Linear): " << t.findMissingLinear(arr, n) << endl;
    cout << "Missing number (Binary): " << t.findMissingBinary(arr, n) << endl;

    return 0;
}
