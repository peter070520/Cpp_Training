#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    lengthconverse(2, 1);
    lengthconverse(-2,1);

    return 0;

    /// END  <TEST CODE>


}