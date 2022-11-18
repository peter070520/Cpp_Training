#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 6;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    cout << baseballScore("52CD+");
    return 0;

    /// END  <TEST CODE>


}