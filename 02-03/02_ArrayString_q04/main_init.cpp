#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);
    
    // BEGIN  <TEST CODE>
    char str[] = "this is my school" ;
    char *outstr = new char[strlen(str) + 1];
    process(str, outstr);
    cout << outstr;
    /// END  <TEST CODE>

    return 0;
}