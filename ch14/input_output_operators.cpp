#include <iostream>
using namespace std;
// Overloaded teh Output Operator <<
    // - first parameter is a ref to a non-const `ostream` object
        // - non-const because writing to it changes its state
        // - a ref because we cannot copy an `ostream` object
    // - second parameter ordinarily should be a ref to a const of the class type we want to print
        // - use ref to avoid copying it
        // - const because printing an object ordinarily does not change it
    // - normally returns its `ostream` parameter
        // - to be consistent with other output operators
    // - usually do minimal formatting
        // - e.g. does not print a new line
    // - IO operators must be non-member functions
        // - otherwise, the left-hand operand, i.e. first parameter, would have to be an object of target class type
            // - if we want to conform to conventions of `iostream` library
            // - we would have to write `Sales_data data; data << cout;` if `operator<<` is a member of Sales_data
        // - usually be declared as friends to target class because they need to read/write non-public data members.

// Overloaded the Iutput Operator >>
    // - first parameter is a ref to the stream from which it is to read
    // - second is a ref to the non-const object into which to read, thus non-constness
    // - return its given stream, i.e., first parameter

ostream &operator<<(ostream &os, Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}
istream &operator>>(istream &is, Sales_data &item)
{
    // no need to init since we will read into it
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    // check that the inputs succeeded
        // - additional data verification based on business logic may be needed
    if (is)
        item.revenue = item.units_sold * price;
    else
        // input failed; give teh object default state
        item = Sales_data();
    return is;
}