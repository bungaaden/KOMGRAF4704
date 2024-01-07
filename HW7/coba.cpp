#include <iostream>
using namespace std;

void display(int row, int col, int matrix[10][10]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void reflect(int row, int col, int matrix[10][10], bool x_axis, bool y_axis) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (x_axis && i < col - i - 1) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[col - i - 1][j];
                matrix[col - i - 1][j] = temp;
            }
            if (y_axis && j < row - j - 1) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][row - j - 1];
                matrix[i][row - j - 1] = temp;
            }
        }
    }
}

int main() {
    int row, col;

    cout << "Masukkan jumlah baris matriks: ";
    cin >> row;

    cout << "Masukkan jumlah kolom matriks: ";
    cin >> col;

    int matrix[10][10];

    cout << "Masukkan elemen matriks: \n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matriks sebelum refleksi: \n";
    display(row, col, matrix);

    reflect(row, col, matrix, true, true);

    cout << "Matriks setelah refleksi: \n";
    display(row, col, matrix);

    return 0;
}


