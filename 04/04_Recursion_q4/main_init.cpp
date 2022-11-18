#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    int n=5,m=1;
    int arr[5]={1, 2, 3, 4, 5};
    cout<<recursiveSearch(n,m,arr,0)<<endl;
    for(int i=0;i<n;i++) cout<< arr[i] <<" ";
    return 0;
    /// END  <TEST CODE>

}