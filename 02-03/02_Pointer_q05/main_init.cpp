#include "utils.h"
#include "answer.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    /// BEGIN  <TEST CODE>
    int r = 0, c = 0;
    cin >> r >> c;
    int** matrix = new int*[r];
    for (int i = 0; i < r; i++) {
        matrix[i] =  new int[c];
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
    int row = 0;
    cin >> row;
    int* newRow = new int[c];
    for (int j = 0; j < c; j++) {
        cin >> newRow[j];
    }
    insertRow(matrix, r, c, newRow, row);
    for (int i = 0; i < r + 1; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    /// END  <TEST CODE>

    return 0;
}