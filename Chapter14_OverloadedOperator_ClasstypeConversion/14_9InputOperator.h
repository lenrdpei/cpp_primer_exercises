#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
class Sales_data
{
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);

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
std::istream &operator>>(std::istream &is, Sales_data &obj)
{
    double price;
    is >> obj.bookno >> obj.units_sold >> price;
    if (is)
        obj.revenue = price * obj.units_sold;
    else
        obj = Sales_data();
}
#endif