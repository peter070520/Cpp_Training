#include <iostream>

using namespace std;

class subRange
{
public:
    subRange( int, int );
    void getValue(int);
private:
    int lower, upper;
};

subRange::subRange( int low, int high )
{
    lower = low;
    upper = high;
}

void subRange::getValue(int a)
{
    //TODO
}