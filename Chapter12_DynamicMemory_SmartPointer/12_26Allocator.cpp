#include <memory>
#include <iostream>
using namespace std;
int main()
{
    cout << "Please input the length of the string:";
    unsigned len;
    cin >> len;
    cin.ignore();
    allocator<char> alloc;
    auto p = alloc.allocate(len + 1);
    cin.get(p, len + 1);
    cout << p << endl;
    alloc.destroy(p);
    alloc.deallocate(p, len + 1);
}