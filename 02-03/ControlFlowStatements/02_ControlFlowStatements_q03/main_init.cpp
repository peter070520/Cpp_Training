#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);
    
    // BEGIN  <TEST CODE>
    string input = "140";
    istringstream oss(input);
    cin.rdbuf(oss.rdbuf());
    tempMain();
    /// END  <TEST CODE>

    return 0;
}