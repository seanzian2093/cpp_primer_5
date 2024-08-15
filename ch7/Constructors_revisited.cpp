#include <string>
using namespace std;


struct Sales_data {
// Default Arguments and Constructors
    // - the default constructor implicitly use default constructor to initialized all members without default initializers 
        // - in Sales_data, it is string default constructor to initialize bookNo
        // - a constructor that supplies default arguments for all its parameters also defines the default constructor
        // - so we don't need to use =default
    Sales_data(string s = ""): bookNo(s) {}
    // Sales_data() = default;

    // a self-define constructor, which does not initialize bookNo,units_sold,revenue in constructor initializer list, such as below
    // Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(const string &, unsigned , double);
    Sales_data & combine(const Sales_data&);
    // data members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

Sales_data::Sales_data(const string &s, unsigned cnt, double price)
{
        // - before execution of this contructor body, bookNo,units_sold,revenue were default initialized
        // - in body, bookNo,units_sold,revenue are assigned
            // - distinct between such assignment and initialization is oftem trivial but, not always
                // - class members that must be initialized by constructor initializer list
                    // - const
                    // - ref
                    // - a class type that does not have a default constructor
    bookNo = s;
    units_sold = cnt;
    revenue = cnt * price;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

class ConstRef {
public:
    // ConstRef is a class that has not a default constructor
    ConstRef(int ii);
private:
    int i;
    // a const - must be initialized
    const int ci;
    // a reference - must be initialized
    int &ri;
};

// Order of member initialization
    // - members are initialized in the order in which they appear in class definition
        // - the order of initializers in constructor initializer does not matter
        // - best practice to write constructor initializers in same order as member declared
        // - avoid to initialize members using other 
        // - use constructor's parameter as possible
class X {
    // i will be initialized first
    int i;
    // then j
    int j;
public:
    // so i will be initialized with undefined j;
        // - compiler may warn
    // j will be initialized with val
    X(int val): j(val), i(j) {}
};


// Delegating constructor
    // - a constructor uses another constructor from its own class to perform its initialization
        // - delegating some or all of its work to this other constructor
            // - this other constructor can delegate too
    // - a delegating constructor has a member initializer list and a function body, too
        // - member initializer has one single entry that is the name of the class itself, 
            // - followed by a parethesized list of arguments 
struct Sales_data2 {
    // a nondelegating constructor which will be used by other delegating constructors
    Sales_data2(const string &s, unsigned cnt, double price):
        bookNo(s), units_sold(cnt), revenue(cnt * price) {}
    // delegating constructors - 
    Sales_data2(): Sales_data2("", 0, 0) {}
        // using explicit to surpress implicity conversion
            // works only with single argument constructor
            // only allowed for constructor declaration in class
                // not allowed to repteat on definition outside class
    explicit Sales_data2(string s): Sales_data2(s, 0, 0) {}
    Sales_data2 & combine(const Sales_data2&);
    // - need to find out how to import read()
    // Sales_data2(istream &is): Sales_data2() { read(is, *this); }
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

Sales_data2& Sales_data2::combine(const Sales_data2 &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// Implicit Class-Type Conversions
    // - a constructor that can be called with a single argument defines an implicit conversion
        // - from parameter type to the class type
    // - we can suppress such implicity conversion by declare the constructor explicit
        // - precede explicit keyword before constructor declare, line 90, Sales_data2
int main()
{
    string null_book = "9-99-999-1";
    string null_book2 = "9-99-999-2";
    Sales_data null_1 = Sales_data(null_book);
    // implicit conversion works with assignment
    Sales_data null_12 = null_book2;

    // combine() takes a Sales_data so null_book2 is converted to Sales_data from string
    null_1.combine(null_book2);
        // only one class-type conversion is allowed
            // - compiler will complain
            // - below call would require 2 conversion
                // - string literal to string and string to Sales_data
    // null_1.combine("9-99-999-3");

    Sales_data2 null2 = Sales_data2(null_book2);
    // when implicit conversion is surpress by explict keyword, init by assignment does not work
        // must use direct init, e.g., line 132
    Sales_data2 null_122 = null_book2;
    // null_book is a string, and will not be converted to Sales_data2
        // - precede explicit keyword before constructor declare, line 90, Sales_data2
    null2.combine(null_book);
    // we can use a static_case to perform an explicit conversion, even implicit conversion is surpressed 
    null2.combine(static_cast<Sales_data2>(null_book));
    return 0;
}