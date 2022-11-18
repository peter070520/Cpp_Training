#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    SLinkedList<int> list;
    
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
            
    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    for(it = list.begin(); it != list.end(); it++){
        assert(*it == expvalue);
        expvalue += 1;
    }
    return 0;

    /// END  <TEST CODE>


}