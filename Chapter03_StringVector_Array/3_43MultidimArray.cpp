#include <iostream>
using namespace std;
int main()
{
    int ia[3][4] = {2, 1};
    // version 1
    for (const auto &a : ia)
        for (const auto &i : a)
            cout << i << " ";
    cout << endl;
    // version 2
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
        {
            cout << ia[i][j] << " ";
        }
    cout << endl;
    // version 3
    for (int(*ip)[4] = ia; ip != end(ia); ++ip)
        for (int *jp = *ip; jp != end(*ip); ++jp)
            cout << *jp << " ";
    cout << endl;
    // version 4 in 3.44
    using pint_array = int(*)[4];
    for (pint_array ip = ia; ip != end(ia); ++ip)
        for (int *jp = *ip; jp != end(*ip); ++jp)
            cout << *jp << " ";
    cout << endl;
    // version 5 in 3.45
    for (auto ip = ia; ip != end(ia); ++ip)
        for (int *jp = *ip; jp != end(*ip); ++jp)
            cout << *jp << " ";
    cout << endl;
}