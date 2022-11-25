#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    /// BEGIN  <TEST CODE>
    int arr[] = {1, 2, 3, 4, 5};
    cout << findMax(arr, sizeof(arr) / sizeof(arr[0]));
    /// END  <TEST CODE>

    return 0;
}