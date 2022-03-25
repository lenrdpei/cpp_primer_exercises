#include <iostream>
int call_cnt()
{
    static int cnt = -1;
    ++cnt;
    return cnt;
}
int main()
{
    call_cnt();
    call_cnt();
    std::cout << call_cnt() << std::endl;
}