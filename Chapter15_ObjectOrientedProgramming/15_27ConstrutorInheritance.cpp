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
/**
 * @brief an abstract base type
 *
 */
class DiscQuote : public Quote
{
public:
    DiscQuote() = default;
    DiscQuote(const std::string &s, double ori, size_t min, double dis)
        : Quote(s, ori), min_qty(min), discount(dis) {}
    double net_price(size_t) const override = 0;

protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

class BulkQuote : public DiscQuote
{
    using DiscQuote::DiscQuote;

public:
    BulkQuote() = default;

        double net_price(size_t n) const override
    {
        if (n >= min_qty)
            return n * (orig_price - discount);
        else
            return n * orig_price;
    }
};