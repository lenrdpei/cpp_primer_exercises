#include <iostream>
#include <string>
int main()
{
    std::string s(10, '*');
    for (auto &ch : s)
        ch = 'X';
    std::cout << s << std::endl;
}