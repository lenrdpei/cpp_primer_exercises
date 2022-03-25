#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int a[] = {3, 5, 2};
    vector<int> v(begin(a), end(a));
}