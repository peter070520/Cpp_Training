#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    int n=5;
    //cin>>n;
    //int *ar = new int[n];
    //for(int i=0;i<n;i++) cin>>ar[i];
	ar[5]={1, 2, 3, 4, 5};
    cout<<checkDuplicate(ar, n);
    return 0;

    /// END  <TEST CODE>


}