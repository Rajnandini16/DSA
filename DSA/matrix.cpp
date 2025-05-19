#include <iostream>
using namespace std;

int main() {
    int rows, cols, choice;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int A[rows][cols], B[rows][cols], C[rows][cols], T[cols][rows];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> B[i][j];

    cout << "Choose operation:\n1. Addition\n2. Multiplication\n3. Transpose\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Matrix Addition:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                C[i][j] = A[i][j] + B[i][j];
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    } else if (choice == 2) {
        if (cols != rows) {
            cout << "Matrix multiplication not possible!\n";
            return 0;
        }else{
        cout << "Matrix Multiplication:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                C[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
                cout << C[i][j] << " ";
            }
        }
            cout << endl;
        }
    } else if (choice == 3) {
        cout << "Matrix Transpose:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                T[j][i] = A[i][j];
            }
        }
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                cout << T[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Invalid choice!";
    }

    return 0;
}