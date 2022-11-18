#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    string a[]={"abccba","abc", "a","*"};
    for (int i=0;i<4;i++){
        if (a[i][0]=='*') break;
        (palindromeRecursion(a[i]))?cout<<"true true":cout<<"false false";
        cout<<endl;
    }

    /// END  <TEST CODE>

    return 0;
}
