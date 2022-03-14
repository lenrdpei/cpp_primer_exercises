#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int tmp;
    while (cin >> tmp)
        v.push_back(tmp);
    for (int i : v)
        cout << i << endl;
}