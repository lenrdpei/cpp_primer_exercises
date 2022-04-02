#include <memory>
#include <iostream>
#include <vector>
using namespace std;
shared_ptr<vector<int>> alloc_vector()
{
    return make_shared<vector<int>>();
}
void read(istream &is, shared_ptr<vector<int>> p)
{
    int tmp;
    while (is >> tmp)
        p->push_back(tmp);
}
void print(shared_ptr<vector<int>> p)
{
    for (const int &i : *p)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    auto p = alloc_vector();
    read(cin, p);
    print(p);
}