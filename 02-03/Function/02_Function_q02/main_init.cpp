#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    /// END  <TEST CODE>
    int arr[] = {-11, 111, -1111, -112, -101, 11, -19, 1, 145, 12};
    int size = sizeof(arr) / sizeof(int);

    cout << findMax(arr, size) << endl;
    /// END  <TEST CODE>

    return 0;
}