#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(0) == list.removeAt(0));

    cout << list.toString();
    return 0;

    /// END  <TEST CODE>


}