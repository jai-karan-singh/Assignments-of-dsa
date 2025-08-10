#include <iostream>
using namespace std;
//part a
int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n / 2; i++) {
        int t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
//part b
/*int main() {
    int a[10][10], b[10][10], c[10][10], n, m, p, q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    cin >> p >> q;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++) cin >> b[i][j];
    if (m != p) return 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < q; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}*/
//part c
/*int main() {
    int a[10][10], t[10][10], n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t[j][i] = a[i][j];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << t[i][j] << " ";
        cout << endl;
    }
    return 0;
}*/
