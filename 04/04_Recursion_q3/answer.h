#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
bool palindromeRecursion(string s)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    if (s.size()<=1) return true;
    if (s.front()!=s.back()) return false;
    return (palindromeRecursion(s.substr(1,s.size()-2)));
    // END YOUR EMPLEMENTATION [1]
}


/// END  <STUDENT ANSWER>