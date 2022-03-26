#include <iostream>
using namespace std;

int main()
{
    cout << "Please input the length of the string:";
    unsigned len;
    cin >> len;
    cin.ignore();
    char *s = new char[len + 1];
    cin.get(s, len + 1);
    cout << s << endl;
    delete[] s;
}