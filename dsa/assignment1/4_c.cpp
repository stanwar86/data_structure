#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    int A[r][c], T[c][r];

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    // Transpose logic
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << T[i][j] << " ";
        cout << "\n";
    }
}

