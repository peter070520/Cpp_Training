#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 7;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    cout << removeDuplicates("abbaca");
    return 0;

    /// END  <TEST CODE>


}