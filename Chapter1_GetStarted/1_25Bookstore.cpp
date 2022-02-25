#include <iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
    Sales_item trans, tot;
    if (cin >> tot)
        while (cin >> trans)
        {
            if (trans.isbn() == tot.isbn())
                tot += trans;
            else
            {
                cout << tot << endl;
                tot = trans;
            }
        }
    else
        cout << "No data!" << endl;
}