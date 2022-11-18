#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 4;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    birthday(29,2,2020);
    birthday(29,2,2022);
    birthday(15,13,2022);
    return 0;

    /// END  <TEST CODE>

}