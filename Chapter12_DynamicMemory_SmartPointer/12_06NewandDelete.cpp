#include <vector>
#include <cstdio> //practice for c standard io
using namespace std;
vector<int> *alloc_vector()
{
    auto p = new vector<int>();
    return p;
}
void read(vector<int> *p)
{
    int tmp;
    while (scanf("%d", &tmp) != EOF)
        p->push_back(tmp);
}
void print(vector<int> *p)
{
    for (const int &i : *p)
    {
        printf("%d ", i);
    }
    printf("\n");
}
int main()
{
    auto p = alloc_vector();
    read(p);
    print(p);
    delete p;
}