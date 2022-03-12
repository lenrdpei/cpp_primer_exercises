#include <iostream>
#include <string>
using namespace std;
int main()
{
    const string s = "Keep out!";
    for (auto &c : s)
    {
    };
}
//范围for语句合法，其中的c类型为 const char& 。