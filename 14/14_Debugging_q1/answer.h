#include<iostream>

using namespace std;

int ** allocateArray2D(int nRow, int nCol) {
    int ** arr = new int*[nRow];
    for (int i = 0; i < nRow; ++i) {
        arr[i] = new int[nCol];
    }

    return arr;
}

void inputArray2D(int ** arr, int nCol, int nRow) {
    for (int i = 0; i < nCol; ++i) {
        for (int j = 0; j < nRow; ++j) {
            cin >> arr[i][j];
        }
    }
}

void deleteArray2D(int ** & arr, int nRow) {
    for (int i = 0; i < nRow; ++i) {
        delete arr[i];
    }
    delete arr;
}

void tempMain() {
    int nCol = 3, nRow = 5;
    int ** arr = allocateArray2D(nCol, nRow);
    inputArray2D(arr, nCol, nRow);
    deleteArray2D(arr, nRow);
}