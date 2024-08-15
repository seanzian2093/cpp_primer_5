#include <iostream>
using std::cout;
using std::endl;

// Class-type conversions, aka user-defined conversions
    // - defined by converting constructors and conversion operators

// A conversion operator
    // - a special kind of member function that converts a value of a class type to a value of other type
        // - general form `operator type() const;`
    // - can be defined for any type that can be a function return type 
        // - except void
    // - no explicitly stated return type
    // - no parameter
    // - must be defined as member
    // - ordinarily should not change the object they are converting
        // - so should be a const member
    // - compiler apples only one user-defined conversion at a time
        // - but an implicit user-defined conversion can be preceded or followed by a built-in conversion
    // - use `explicit` keyword to specify an explicit conversion operator
        // - compiler generally will not use an explicit conversion operator for implicit conversion 
        // - except an expression is used as 
            // - condition of `if`, `when`, and `do` statement, i.e., flow control
            // - condition expression in a `for` statement header
            // - an operand to logical NOT(!), OR(||), or AND(&&) operator
            // - in a conditional operator(?:)
        // - `operator bool()` ordinarily should be defined as explicit
    // - generally bad idea to define
        // - multiple conversion to built-in type, e.g., to int and to double
        // - mutual conversions. e.g., class A to classB, and class B to class A

class SmallInt {
public:
    // constructor SmallInt from int
    SmallInt(int i = 0): val(i)
    {
        if (i <0 | i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
    // Conversion operator -  int to SmallInt
    operator int() const { return val; }
private:
    std::size_t val;
};

class SmallInt2 {
public:
    // constructor SmallInt from int
    SmallInt2(int i = 0): val(i)
    {
        if (i <0 | i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
    // Explicit conversion -  double to SmallInt
    explicit operator double () const { return val; }
private:
    std::size_t val;
};

int main()
{
    SmallInt si;
    si =4;
    cout << "si is: " << si << '\n';
    // implicitly conversion to int by add operator
    auto i = si + 3;
    cout << "i is: " << i << '\n';

    // si is implicitly converted to int and then to double by built-in conversion
    cout << "si + 3.14 is: " << si + 3.14 << '\n';

    // constructor is not explicit, so it works
    SmallInt2 si2 = 7;
        // - cannot print directly since we do not define such operator form SmallInt2
    // cout << "si2 is: " << si2 << '\n';
    // works but with a warning,saying 3.19 be converted to int from double 
    si2 = 3.19;
    // error - implicit conversion required but conversion operator is explicit
    // cout << "si2 + 3.14 is: " << si2 + 3.994 << '\n';
    // ok - call conversion operaotr explicitly
    cout << "si2 + 3.994 is: " << static_cast<double>(si2) + 3.994 << '\n';
    return 0;
}