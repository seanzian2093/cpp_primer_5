
#include <iostream>
using namespace std;

// We use access specifiers to enforce encapsulation
    // - members defined after a `public` specifier are accessible to all parts of program
        // - i.e., the interface to the class
    // - members defined after a `private` specifier are accessible only to member functions of the class
        // - i.e., the private sections encapsulate the implementation

// Redefine Sales_data
    // - using `struct`, the members defined before 1st access specifier are public;
        // - use `struct` to define a class intending for all its members to be public
    // - using `class`, they are private.
        // - use `class` to define a class intending to have private members. 
class Sales_data {
    // - functions that are not members of the class
        // - using `friend` keyword makes such functions a friend
        // - a friend is allowed to access its non-public members.
        // - friend declaration may appear only inside a class defition
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
    // - there can be more than one public or private specifiers.
public:
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &is);
    string isbn() const { return bookNo; }
    Sales_data & combine(const Sales_data&);

private:
    double avg_price() const
        { return units_sold ? revenue/units_sold : 0; }
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    return 0;
}