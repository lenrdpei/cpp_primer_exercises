#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data
{
    std::string bookno;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isbn() const { return bookno; }
    Sales_data &combine(const Sales_data &trans)
    {
        revenue += trans.revenue;
        units_sold += trans.units_sold;
        return *this;
    }
};
#endif