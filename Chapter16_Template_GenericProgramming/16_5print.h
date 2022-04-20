#ifndef PRINT_H
#define PRINT_H
#include <iostream>
template <typename T, size_t N>
void print(const T (&a)[N])
{
    for (auto &i : a)
        std::cout << i << std::endl;
}

#endif