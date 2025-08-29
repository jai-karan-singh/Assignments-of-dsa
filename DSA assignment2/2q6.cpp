#include <iostream>
using namespace std;

#define MAX 100

struct Triplet {
    int row, col, val;
};

void display(Triplet T[], int count) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= count; i++) {
        cout << T[i].row << " " << T[i].col << " " << T[i].val << endl;
    }
}

void transpose(Triplet A[], Triplet T[]) {
    int n = A[0].val; 
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].val = n;

    int k = 1;
    for (int i = 0; i < A[0].col; i++) { 
        for (int j = 1; j <= n; j++) {
            if (A[j].col == i) {
                T[k].row = A[j].col;
                T[k].col = A[j].row;
                T[k].val = A[j].val;
                k++;
            }
        }
    }
}

void add(Triplet A[], Triplet B[], Triplet C[]) {
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        cout << "Addition not possible!\n";
        return;
    }

    int m = A[0].val, n = B[0].val;
    C[0].row = A[0].row;
    C[0].col = A[0].col;

    int i = 1, j = 1, k = 1;
    while (i <= m && j <= n) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        } else { 
            int sum = A[i].val + B[j].val;
            if (sum != 0) {
                C[k].row = A[i].row;
                C[k].col = A[i].col;
                C[k].val = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= m) C[k++] = A[i++];
    while (j <= n) C[k++] = B[j++];
    C[0].val = k - 1;
}

void multiply(Triplet A[], Triplet B[], Triplet C[]) {
    if (A[0].col != B[0].row) {
        cout << "Multiplication not possible!\n";
        return;
    }

    Triplet B_T[MAX];
    transpose(B, B_T);

    C[0].row = A[0].row;
    C[0].col = B[0].col;
    C[0].val = 0;

    int k = 1;
    for (int i = 1; i <= A[0].row; i++) {
        for (int j = 1; j <= B_T[0].row; j++) {
            int sum = 0;
            for (int x = 1; x <= A[0].val; x++) {
                if (A[x].row == i) {
                    for (int y = 1; y <= B_T[0].val; y++) {
                        if (B_T[y].row == j && B_T[y].col == A[x].col) {
                            sum += A[x].val * B_T[y].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k].row = i;
                C[k].col = j;
                C[k].val = sum;
                k++;
            }
        }
    }
    C[0].val = k - 1;
}

int main() {
    Triplet A[MAX] = {
        {3, 3, 4}, 
        {0, 0, 5}, {0, 2, 8}, {1, 1, 3}, {2, 0, 6}
    };

    Triplet B[MAX] = {
        {3, 3, 3},
        {0, 0, 1}, {1, 1, 4}, {2, 2, 7}
    };

    Triplet T[MAX], C[MAX], M[MAX];

    cout << "Matrix A:\n";
    display(A, A[0].val);

    cout << "\nMatrix B:\n";
    display(B, B[0].val);

    transpose(A, T);
    cout << "\nTranspose of A:\n";
    display(T, T[0].val);

    add(A, B, C);
    cout << "\nA + B:\n";
    display(C, C[0].val);

    multiply(A, B, M);
    cout << "\nA * B:\n";
    display(M, M[0].val);

    return 0;
}
