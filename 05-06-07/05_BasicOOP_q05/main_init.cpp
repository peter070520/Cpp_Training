#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    // BEGIN  <TEST CODE>
    
    ClockType myClock;
    myClock.setTime(5, 4, 30);
    int hours,minutes,seconds;
    myClock.getTime(hours, minutes, seconds);
    cout << "Hours = " << hours << ", minutes = " << minutes << ", seconds = " << seconds << endl;

    /// END  <TEST CODE>

    return 0;
}