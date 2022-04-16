#include <string>
#include <iostream>
class Quote
{
public:
    Quote() = default;
    Quote(const std::string &No, double price) : bookNo(No), orig_price(price) {}
    virtual ~Quote() = default;

    std::string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const
    {
        return n * orig_price;
    }
    virtual void debug() const
    {
        std::cout << "bookNo: " << bookNo << '\n'
                  << "orig_price: " << orig_price << std::endl;
    }

private:
    std::string bookNo;

protected:
    double orig_price = 0.0;
};
void print_total(std::ostream &os, const Quote &item, size_t n)
{
    os << "ISBN: " << item.isbn() << '\n'
       << "Total due: " << item.net_price(n) << std::endl;
}

class BulkQuote : public Quote
{
public:
    BulkQuote() = default;
    BulkQuote(const std::string No, double price, size_t minqty, double discnt)
        : Quote(No, price), min_qty(minqty), discount(discnt) {}
    double net_price(size_t n) const
    {
        if (n >= min_qty)
            return n * (orig_price - discount);
        else
            return n * orig_price;
    }
    void debug() const override
    {
        Quote::debug();
        std::cout << "min_qty: " << min_qty << '\n'
                  << "discount: " << discount << std::endl;
    }

private:
    size_t min_qty = 0;
    double discount = 0.0;
};