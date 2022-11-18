#include <iostream>
#include<fstream>
#include<string>

using namespace std;
bool check_st(string str) {
    int n=str.length();
    if(n==1){
        if (isdigit(str[0]) == false || str[0]=='-')    return false;
        else return true;
    }
    else {
        for (int i = 1; i < n; i++){
            if (isdigit(str[i]) == false)
                return false;
        }
   } 
    return true;
}

int number(string fileName){
    //TODO
}
