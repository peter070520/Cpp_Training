#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;


int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    LinkedList* l1 = new LinkedList();
    l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);
    l1->partition(45);
    cout << l1->toString() << "\n";
    return 0;

    /// END  <TEST CODE>


}