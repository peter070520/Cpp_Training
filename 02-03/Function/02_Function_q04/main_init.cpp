#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    /// END  <TEST CODE>
    const char* str = "abba";
    cout << (isPalindrome(str) ? "true" : "false") << endl;
    /// END  <TEST CODE>

    return 0;
}