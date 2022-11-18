#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 4;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    check_time(13,30,5,"PM");
	check_time(1,20,30,"PM");
    check_time(10,70,59,"AM");
    check_time(12,30,5,"AM");
    return 0;

    /// END  <TEST CODE>

}