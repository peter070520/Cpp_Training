#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    SLinkedList<int> list;
    int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
    int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
    int expvalues[]= {8,  15, 2,  4,  7, 10,  40,  6}; 

    for (int idx = 0; idx < 8; idx++){
        list.add(index[idx], values[idx]);
    }

    assert( list.size() == 8 );
            
    for (int idx = 0; idx < 8; idx++){
        assert( list.get(idx) == expvalues[idx] );
    }

    cout << list.toString();
    return 0;

    /// END  <TEST CODE>


}