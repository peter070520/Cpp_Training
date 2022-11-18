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

    float Xa, Xb, Ya, Yb;
    cin >> Xa >> Xb >> Ya >> Yb;
    Coordinate a(1,2);
    Coordinate b(0,1);
    cout << a.distanceTo(b) << endl;
    a.setX(Xa); a.setY(Ya);
    b.setX(Xb); b.setY(Yb);
    cout << abs(a.getX() - b.getX()) + abs(a.getY() - b.getY()) << endl;
    cout << a.distanceTo(b) << endl;
    cout << abs(Xa - Xb) + abs(Ya - Yb);

    return 0;
}