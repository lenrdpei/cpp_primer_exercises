#include <initializer_list>
#include <iostream>
using namespace std;

int sum(initializer_list<int> lst)
{
    int sum = 0;
    for (const int &i : lst)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    cout << sum({1, 2, 3, 4, 5}) << " " << sum({1, 2}) << endl;
}