#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    // BEGIN  <TEST CODE>
    int arr[][1000] = {{1, 4, 6}, {4, 5, 3}, {6, 3, 9}};
    cout << isSymmetric(arr, 3, 3);
    /// END  <TEST CODE>

    return 0;
}