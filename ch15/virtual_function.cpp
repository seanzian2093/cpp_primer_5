#include <iostream>
using std::cout;
using std::endl;

#include "quote.hpp"

// Calls to Virtual Functions May Be Resolved at Run Time
    // - virtual functions are resolved at run time only if the call is made through a ref or pointer

// When a derived class override a virtual function
    // - it may, not requrired to, repeat the virtual keyword
    // - once a function is declared virtual, it remains virtual in all the derived classes
    // - must have exact the same parameter type(s) as the base-class function that it overrides
    // - must have same return type
        // - except when virtuals return a ref or pointer to types that are related by inheritance
            // - requires that derived-to-base conversion is accessible
             
// legal for a derived class to define a function 
    // - with same name as a virtual function in its base class
    // - but with different parameter list
    // - compiler considers such function to be independent from the base-class virtual
    // - in such cases, the derived version does not override the base version
        // - often a mistake, not intention
    // - in new standard, we can specify `override` on the derived verson virtual function
        // - to make our intention clear
        // - to enlist compiler in finding such problems for us
            // - compiler will reject a program if a function marked `override` does not override

// - we can designate a function as `final` so attempt to override it is compile error

// Virtual Functions and Default Arguments
    // - a virtual functon can have default arguments, just like any other functions.
    // - if a call uses default argument, the value used is 
        // - the one defined by the static type through which the function is called
    // - e.g., when a call is made thru a ref/pointer to base, default argument will be 
        // - those defined in base class
        // - even when the derived version of the function is run
    // - best practice is virtual functions that have default arguments should 
        // - use same argument values in the base and derived class

// Circumventing the Virtual Mechanism
    // - use scope operator to force the call to use a particular version of a virtual function

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : B {
    virtual void f1(int) const override; // ok - f1 matches f1 in B, so override successfully
    virtual void f2(int) override;// error - f2 marked override, but base B has not f2(int), not override
    void f3() override;//error - f3() in B is not virtual
    void f4() override;//error - B has not f4()
};

struct D2 : B {
    void f1(int) const final; // subsequent classes cannot override f1(int)
};

struct D3 : D2 {
    void f2(); //ok - override f2() in B, i.e., indirect base
    void f1(int) const; // error - D2 declared f2 as final
};

int main()
{
    Quote base("0-1-23-456-7890", 50);
    // call Quote::net_price because base is of Quote type
    print_total(cout, base, 10);
    // call Bulk_quote::net_price because derived is of Bulk_quote type
    Bulk_quote derived("0-1-23-456-7890", 50, 5, 0.19);
    print_total(cout, derived, 10);

    return 0;
}