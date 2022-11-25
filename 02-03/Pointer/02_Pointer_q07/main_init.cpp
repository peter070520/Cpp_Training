#include "utils.h"
#include "answer.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    /// BEGIN  <TEST CODE>
    char s1[] = "Hello, ";
    char s2[] = "how are you?";
    char *s = concatStr(s1, s2);
    cout << s;
    delete[] s;
    /// END  <TEST CODE>

    return 0;
}