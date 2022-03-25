#include <iostream>
#include <string>
struct Sales_data
{
    explicit Sales_data(const std::string &s = "") : bookno(s){};

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
int main()
{
    std::string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);
    Sales_data item2("9-999-99999-9");
}
//答：不论构造函数是否是explicit的，构造都可以成功。发生从 const char* 到 string 的隐式类类型转换。