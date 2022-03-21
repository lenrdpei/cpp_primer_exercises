#include <iostream>
using namespace std;
string make_plural(int cnt, const string &word, const string &ending = "s")
{
    return cnt > 1 ? word + ending : word;
}
int main()
{
    cout << make_plural(2, "success", "es") << " " << make_plural(2, "failure") << endl;
}