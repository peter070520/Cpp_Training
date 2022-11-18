#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    cout << "Constructor test" << endl;
    Integer i(10);
    Integer i2(-10);
    Integer *i3 = new Integer(20);
    delete i3;

    /// END  <TEST CODE>

    return 0;
}