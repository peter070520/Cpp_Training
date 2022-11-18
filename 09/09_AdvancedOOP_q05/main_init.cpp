#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    Matrix matrix(2,3);
    int** arr;
    arr = new int*[2];
    for(int i = 0; i < 2; i++){
        arr[i] = new int[3];
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = i + j;
        }
    }
    matrix.setMatrix(2, 3, arr);
    matrix.printMatrix();

    // TESTCODE FOR TEMPLATE IMPLEMENTATION
    // Matrix<double> matrix(2,3);
    // double** arr;
    // arr = new int*[2];
    // for(int i = 0; i < 2; i++){
    //     arr[i] = new int[3];
    // }
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 3; j++){
    //         arr[i][j] = (double)i/j;
    //     }
    // }
    // matrix.setMatrix(2, 3, arr);
    // matrix.printMatrix();
    return 0;
}