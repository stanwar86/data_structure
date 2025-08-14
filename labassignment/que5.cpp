#include<iostream>
using namespace std;

int main() {
    int mat[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter the elements of the matrix: ";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    
    cout << "Sum of each row:";
    for(int i = 0; i < rows; i++) {
        int rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += mat[i][j];
        }
        cout << "Row " << i << ": " << rowSum << endl;
    }

  
    cout << "Sum of each column: ";
    for(int j = 0; j < cols; j++) {
        int colSum = 0;
        for(int i = 0; i < rows; i++) {
            colSum += mat[i][j];
        }
        cout << "Column " << j << ": " << colSum << endl;
    }

    return 0;
}

