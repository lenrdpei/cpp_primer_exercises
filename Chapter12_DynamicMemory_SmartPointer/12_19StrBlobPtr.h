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
    StrBlobPtr() : curr(0)
    {
    }
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wp(a.data), curr(sz) {}

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

#endif