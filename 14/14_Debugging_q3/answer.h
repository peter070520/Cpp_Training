#include<iostream>

using namespace std;

char * concat(char * s1, char * s2) {
    char * p;
    while (*p != '\0') {
        ++p;
    }
    while (*s2 != '\0') {
        *p = *s2;
        ++p;
        ++s2;
    }
    return s1;
}

void tempMain() {
    char s1[] = "Hello";
    char s2[] = ", world!";
    cout << concat(s1, s2) << endl;
}