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
    deleteMatrix(matrix, r);
    // check if matrix is deallocated
    /// END  <TEST CODE>

    return 0;
}