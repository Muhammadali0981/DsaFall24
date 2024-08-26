/*
    Name:Muhammad Ali
    Date:26/08/24
    Desc: matrix multipliction
*/

#include <iostream>

using namespace std;

void multiply(int mat1[2][2], int mat2[3][2], int colA, int rowA, int colB, int rowB) {
    if (colA != rowB){
        cout << "cant multiply" << endl;
        return;
    }
    int **arr = new int*[rowA];
    for (int i = 0; i < rowA; i++) arr[i] = new int[colB];
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                arr[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) cout << "[" << arr[i][j] << "]";
        cout << endl;
    }
}

int main() {
    int A[2][2] = { {1, 0}, {0, 1} };
    int B[3][2] = { {7, 8}, {9, 10}, {11, 12} };
    multiply(A, B, 3, 2, 2, 3);
}