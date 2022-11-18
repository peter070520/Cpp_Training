#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    cout<<"Constructor test";
    Room r(20,3,4);
    Room *r2=new Room(10.5,5.5,5.4);
    delete r2;

    /// END  <TEST CODE>

    return 0;
}