#include <iostream>
#include <vector>
using namespace std;
int add(int a, int b) { return a + b; }
int ded(int a, int b) { return a - b; }
int mut(int a, int b) { return a * b; }
int dvd(int a, int b) { return a / b; }
int main()
{
    vector<int (*)(int, int)> v{add, ded, mut, dvd};
    for (auto &p : v)
        cout << p(5, 6) << endl;
}