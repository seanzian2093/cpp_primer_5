#include <iostream>
#include <string>

// Base class
class Quote {
public:
    // Constructors
        // - default constructor
    Quote() = default;
        // - copy constructor
    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
        // - copy assignment
    Quote& operator=(const Quote&) = default;
        // - move assignment
    Quote& operator=(Quote&&) = default;
    Quote(const std::string &book, double sales_price): bookNo(book), price(sales_price) {}

    std::string isbn() const { return bookNo; }

    // - use `virtual` keyword to indicate that derived classes must define net_price() for themselves
    virtual double net_price(std::size_t n) const { return n * price; }
    // destructor
    virtual ~Quote() = default;
private:
    std::string bookNo;
    // - derived classes will have access to price of base class, 
        // - others do not
protected:
    double price = 0.0;
};

// Derive class - Bulk_quote
    // - a class derivation list
        // - must appear in clas body, i.e., cannot in declaration
class Bulk_quote : public Quote {
public:
    Bulk_quote() = default; 
    // Bulk_quote, a derived class, initializes its base-class part and its derived-class part
    Bulk_quote(const std::string&, double, std::size_t, double); 
    // define its own net_price()
        // - use `override` keyword to explicitly indicate that it intends to override the virtual funcion it inherits
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : 
                        // - initialize base-class first
                       Quote(book, p),
                       // - then derived-class members in the order they were declared
                       min_qty(qty), discount(disc) {} 
            
double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= min_qty)
        // a derived class may access the `public` and `protected` members of its base class
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// Derive class - Disc_quote
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    // net_price is a pure virtual function
    double net_price(std::size_t) const = 0;
    std::pair<size_t, double> discount_policy() const { return {quantity, discount}; }
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

// Utilities
double print_total(std::ostream &os, const Quote &item, size_t n)
{
    // depending on the type of object that item points to, call Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}