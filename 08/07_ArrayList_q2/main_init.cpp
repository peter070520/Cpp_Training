#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    vector<int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
    return 0;

    /// END  <TEST CODE>


}