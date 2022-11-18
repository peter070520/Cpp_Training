#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    int N=4;
    //cin >> N;
    vector<int> nums{15,2,4,10};
    vector<int> greaterNums = nextGreater(nums);
    for(int i : greaterNums) 
        cout << i << ' ';
    cout << '\n';   
    return 0;

    /// END  <TEST CODE>


}