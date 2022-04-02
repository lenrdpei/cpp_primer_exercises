#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    int ele = 50;
    while (ele <= 100)
    {
        sum += ele;
        ++ele;
    }
    cout << sum << endl;
}