#include <string>
using std::string;
class HasPtr
{
public:
    HasPtr(int k = 0, const string &s = string()) : i(k), ps(new string(s)), use(new size_t(1)) {}
    HasPtr(const HasPtr &src) : i(src.i), ps(src.ps), use(src.use) { ++*use; }
    HasPtr &operator=(const HasPtr &rhs)
    {
        ++*rhs.use;
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
        i = rhs.i;
        ps = rhs.ps;
        use = rhs.use;
    }
    ~HasPtr()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

private:
    int i;
    string *ps;
    size_t *use;
};
