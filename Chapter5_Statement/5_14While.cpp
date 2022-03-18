#include <iostream>
using namespace std;
int main()
{
    int cnt = 0, rec = 0;
    string s, last, recs;
    while (cin >> s)
    {
        if (s == last)
            ++cnt;
        else
        {
            if (cnt > rec)
            {
                recs = last;
                rec = cnt;
            }
            last = s;
            cnt = 1;
        }
    }
    if (cnt > rec)
    {
        recs = last;
        rec = cnt;
    }
    if (rec > 1)
        cout << recs + " "
             << "repeated for " << rec << " times" << endl;
    else
        cout << "No successive words." << endl;
}