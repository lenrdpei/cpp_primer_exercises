#include "6_8Chapter6.h"
int fact(int n)
{
    int ret = 1;
    for (int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}