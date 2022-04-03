#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    void push_back(const std::string &s)
    {
        data->push_back(s);
    }
    void pop_back()
    {
        check(0, "pop back");
        data->pop_back();
    }
    std::string &front()
    {
        check(0, "front");
        return data->front();
    }
    std::string &back()
    {
        check(0, "back");
        return data->back();
    }
    const std::string &front() const
    {
        check(0, "front");
        return data->front();
    }
    const std::string &back() const
    {
        check(0, "back");
        return data->back();
    }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

#endif