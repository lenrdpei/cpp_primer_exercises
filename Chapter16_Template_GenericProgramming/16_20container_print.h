#ifndef CONTAINER_PRINT_H
#define CONTAINER_PRINT_H
#include <iostream>
template <typename T>
void container_print(std::ostream &os, const T &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        os << *it << ' ';
}

#endif