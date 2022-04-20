#ifndef FIND_H
#define FIND_H
#include <vector>
#include <string>
#include <list>
template <typename I, typename T>
I find(const I &begin, const I &end, const T &val)
{
    for (auto it = begin; it != end; ++it)
    {
        if (*it == val)
            return it;
    }
    return end;
}

#endif