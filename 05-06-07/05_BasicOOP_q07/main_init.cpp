#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main()
{
    // codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    // BEGIN  <TEST CODE>
    // (No testcode)
    /// END  <TEST CODE>

    Book * pBook = new Book("To Kill a Mockingbird");
    pBook->display();
    delete pBook;

    return 0;
}