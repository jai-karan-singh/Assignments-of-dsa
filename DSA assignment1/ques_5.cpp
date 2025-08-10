#include <iostream>
using namespace std;

int main() {
    int a[10][10], n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) sum += a[i][j];
        cout << "Row " << i << " sum: " << sum << endl;
    }
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += a[i][j];
        cout << "Col " << j << " sum: " << sum << endl;
    }
    return 0;
}
