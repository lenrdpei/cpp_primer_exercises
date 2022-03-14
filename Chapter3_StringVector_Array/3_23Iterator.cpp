#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(10, 3);
    for (auto it = v.begin(); it != v.end(); ++it)
        *it *= 2;
    for (int i : v)
        cout << i << endl;
}