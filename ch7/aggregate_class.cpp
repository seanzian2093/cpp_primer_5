#include <iostream>
#include <string>
using namespace std;

// A class is an aggregate class if
    // - all data members are public
    // - does not define any constructors
    // - has no in-class initializers
    // - no base classes or virtual functions - ch15

// Literal class
    // - an aggregate class whose data members arge all of literal type is a literal class
    // - an non-aggregate class that meets following restrictions, is also a literal class
        // - the class's data members all have lteral type
        // - the class must have at least one constexpr constructor
        // - if a data member has an in-class initializer
            // - if the member is a built-in type, the in-class initializer must be a constexpr
            // - if the member is a class type, the in-class initializer must use the member's own constexpr constructor
        // - the class must use default definition for its destructor which is the member that destroy objects of the class type

    // - a literal class must provide at least one constexpr constructor
        // - a constexpr constructor can be declared as =default, 
            // - or a deleted function, ch13 
        // - or a regular constructor
            // - no return statment, 
            // - of a constexpr function, i.e., only executable statement it can have is a return statement 
                // - a typical constexpr constructor has empty body
        // - a constexpr constructor must initialize every data member
            // - using a constexpr constructor or be a const expression

class Debug {
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
    constexpr bool any() { return hw || io || other;}
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }
private:
    bool hw; // hardware errors other than IO errors
    bool io; // IO error
    bool other; // other errors
};



struct Data {
    int ival;
    string s;
};

int main()
{
    // Initialize an aggregate class by a braced list of member initializers.
        // - order of member initializers matters 
        // - the list must not have more initializers than members
        // - if less, trailing members will be value initialized
    Data val1 = {0, "Anna"};


    // with constexpr constructor, we can generate objects that are constexpr
        // for parameter and return types in constexpr functions

    constexpr Debug io_sub(false, true, false);
    if (io_sub.any())
        cerr << "print appropriate error messages" << endl;
    constexpr Debug prod(false);
    if (prod.any())
        cerr << "print error messages" << endl;

    return 0;
}
/*
The C++03 Standard 8.5/5 aptly defines each:

To zero-initialize an object of type T means:

— if T is a scalar type (3.9), the object is set to the value of 0 (zero) converted to T;
— if T is a non-union class type, each nonstatic data member and each base-class subobject
is zero-initialized;
— if T is a union type, the object’s first named data member is zero-initialized;
— if T is an array type, each element is zero-initialized;
— if T is a reference type, no initialization is performed.

To default-initialize an object of type T means:
— if T is a non-POD class type (clause 9), the default constructor for T is called (and the initialization is ill-formed if T has no accessible default constructor);
— if T is an array type, each element is default-initialized;
— otherwise, the object is zero-initialized.

To value-initialize an object of type T means:
— if T is a class type (clause 9) with a user-declared constructor (12.1), then the default constructor for T is called (and the initialization is ill-formed if T has no accessible default constructor);
— if T is a non-union class type without a user-declared constructor, then every non-static data member and base-class component of T is value-initialized;
— if T is an array type, then each element is value-initialized;
— otherwise, the object is zero-initialized
*/