#include <iostream>
using std::cout;
using std::endl;

int main()
{
    unsigned u = 10, u2 = 42;
    int i = 10, i2 = 42;
    cout << u2 - u << endl;
    cout << u - u2 << endl;

    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;
}