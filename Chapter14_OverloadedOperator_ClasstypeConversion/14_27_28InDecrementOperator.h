#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <memory>
#include <string>
#include <vector>
#include "12_02StrBlob.h"
class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wp(a.data), curr(sz) {}
    std::string &operator[](size_t n)
    {
        auto p = check(curr + n, "subscript n");
        return (*p)[curr + n];
    }
    const std::string &operator[](size_t n) const
    {
        auto p = check(curr + n, "subscript n");
        return (*p)[curr + n];
    }
    StrBlobPtr &operator++()
    {
        check(curr, "increment");
        ++curr;
        return *this;
    }
    StrBlobPtr &operator--()
    {
        --curr;
        check(curr, "decrement");
        return *this;
    }
    StrBlobPtr &operator++(int)
    {
        StrBlobPtr ret = *this;
        ++*this;
        return ret;
    }
    StrBlobPtr &operator--(int)
    {
        StrBlobPtr ret = *this;
        --*this;
        return ret;
    }

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t pos, const std::string &msg) const
    {
        auto ret = wp.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (pos >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wp;
    std::size_t curr;
};
bool operator==(const StrBlobPtr &a, const StrBlobPtr &b)
{
    return a.wp.lock() == b.wp.lock();
}
bool operator!=(const StrBlobPtr &a, const StrBlobPtr &b)
{
    return !(a == b);
}

#endif