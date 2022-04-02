#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
class Sales_data
{
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);

public:
    explicit Sales_data(const std::string &s = "") : bookno(s){};

    std::string isbn() const { return bookno; }
    Sales_data &combine(const Sales_data &trans)
    {
        revenue += trans.revenue;
        units_sold += trans.units_sold;
        return *this;
    }

private:
    std::string bookno;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
std::ostream &operator<<(std::ostream &os, const Sales_data &obj)
{
    os << obj.bookno << " " << obj.units_sold << " " << obj.revenue;
}
#endif