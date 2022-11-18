#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    DLinkedList<int> list;
    int size = 10;
    int value[] = {2,5,6,3,67,332,43,1,0,9};

    for(int idx=0; idx < size; idx++){
    list.add(value[idx]);
    }
    list.removeAt(0);
    cout << list.toString();
    return 0;

    /// END  <TEST CODE>


}