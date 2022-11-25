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
    int** m1 = new int*[r];
    for(int i = 0; i < r; i++) {
        m1[i] = new int[c];
        for(int j = 0; j < c; j++) cin >> m1[i][j];
    }
    int** m2 = transposeMatrix(m1, r, c);
    if (m2)
        for(int i = 0; i < c; i++)
        {
            for(int j = 0; j < r; j++) cout << m2[i][j] << " ";
            cout << endl;
        }
    else cout << "NULL";
    for(int i = 0 ; i < r; i++) delete[] m1[i];
    delete[] m1;
    for(int i = 0 ; i < c; i++) delete[] m2[i];
    delete[] m2;
    /// END  <TEST CODE>

    return 0;
}