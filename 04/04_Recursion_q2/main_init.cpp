#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    //hiddenCheck();
    int p=123456,q=12345678;
    //cin>>p>>q;
    cout<<gcdRecursion(p,q)<< " "<<gcdIteration(p,q);
    return 0;
}