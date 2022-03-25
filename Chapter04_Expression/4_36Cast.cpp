#include <iostream>
int main()
{
    int i = 6;
    double d = 6.66;
    std::cout << (i *= static_cast<int>(d)) << std::endl;
}