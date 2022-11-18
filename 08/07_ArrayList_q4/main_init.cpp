#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
    return 0;

    /// END  <TEST CODE>


}