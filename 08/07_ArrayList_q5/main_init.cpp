#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

void printVector(vector<int> vec) {
    cout << "[";
    for (auto i = 0u; i < vec.size(); i++) {
        if (i > 0u) cout << ", ";
        cout << vec[i];
    }
    cout << "]";
}
int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations));
    return 0;

    /// END  <TEST CODE>


}