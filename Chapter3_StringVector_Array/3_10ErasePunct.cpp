#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i)
        if (ispunct(s.at(i)))
            s.erase(i, 1);
    cout << s << endl;
}