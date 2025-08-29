#include <iostream>
using namespace std;

class Diagonal {
    int *A; 
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
        for (int i = 0; i < n; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) cout << A[i-1] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};

class TriDiagonal {
    int *A; 
    int n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
        for (int i = 0; i < 3*n-2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i-j == 1) A[i-2] = x;                
        else if (i-j == 0) A[n-1 + i-1] = x;     
        else if (i-j == -1) A[2*n-1 + i-1] = x;  
    }
    int get(int i, int j) {
        if (i-j == 1) return A[i-2];
        else if (i-j == 0) return A[n-1 + i-1];
        else if (i-j == -1) return A[2*n-1 + i-1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

class LowerTriangular {
    int *A;
    int n;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for (int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + j-1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + j-1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

class UpperTriangular {
    int *A;
    int n;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for (int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    void set(int i, int j, int x) {
        if (i <= j) A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

class Symmetric {
    int *A;
    int n;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for (int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + j-1] = x;
        else A[j*(j-1)/2 + i-1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + j-1];
        else return A[j*(j-1)/2 + i-1];
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4;

    cout << "Diagonal Matrix:\n";
    Diagonal d(n);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9); d.set(4,4,12);
    d.display();

    cout << "\nTri-diagonal Matrix:\n";
    TriDiagonal td(n);
    td.set(1,1,1); td.set(1,2,2);
    td.set(2,1,3); td.set(2,2,4); td.set(2,3,5);
    td.set(3,2,6); td.set(3,3,7); td.set(3,4,8);
    td.set(4,3,9); td.set(4,4,10);
    td.display();

    cout << "\nLower Triangular Matrix:\n";
    LowerTriangular lt(n);
    lt.set(1,1,1);
    lt.set(2,1,2); lt.set(2,2,3);
    lt.set(3,1,4); lt.set(3,2,5); lt.set(3,3,6);
    lt.set(4,1,7); lt.set(4,2,8); lt.set(4,3,9); lt.set(4,4,10);
    lt.display();

    cout << "\nUpper Triangular Matrix:\n";
    UpperTriangular ut(n);
    ut.set(1,1,1); ut.set(1,2,2); ut.set(1,3,3); ut.set(1,4,4);
    ut.set(2,2,5); ut.set(2,3,6); ut.set(2,4,7);
    ut.set(3,3,8); ut.set(3,4,9);
    ut.set(4,4,10);
    ut.display();

    cout << "\nSymmetric Matrix:\n";
    Symmetric sm(n);
    sm.set(1,1,1); sm.set(2,1,2); sm.set(2,2,3);
    sm.set(3,1,4); sm.set(3,2,5); sm.set(3,3,6);
    sm.set(4,1,7); sm.set(4,2,8); sm.set(4,3,9); sm.set(4,4,10);
    sm.display();

    return 0;
}
