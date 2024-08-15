#include <iostream>
using std::cout;
using std::endl;

#include "quote.hpp"

// Each class defines its own scope
    // - its members are defined within this scope
    // - under inheritance, scope of a derived class is nested inside the scope of its base class
    // - if a name is unresolved within the scope of derived class, the enclosing base-class scopes are searched for a definition of that name

// Name Lookup Happens at Compile Time
    // - static type of an object/ref/pointer determines which members of the object are visible
    // - a derived-class member with the same name as a member in base-class hides the direct use of the base-class member
        // - use scope operator to access the hidden names
        // - best practice is not to reuse names
    // - functions declared in an inner scope do not overload functions declared in an outer scope
        // - as a result, functions defined in a derived class do not overload members defined in base classes
            // - if same function name, base member function is hidden, even with different parameter lists

// Overriding Overloaded Functions 
    // - a derived class can override zero or more instances of the overloaded functions it inherits.
        // - to make all overloaded versions available through its type, it must override all of them, or none of them 
        // - this is tedious
    // - use `using` declaration for overloaded member to all all overloaded instances of that function to the scope of derived class
        // - then the derived hass needs to define only those functions that truly depend on derived-class type
            // - and use the inherited definitions for others.

class Base {
public:
    int memfcn();
    virtual int fcn();
};

class D1: public Base {
public:
    // memfnc hides memfcn in Base
    int memfcn(int);
    // fcn hides fcn in Base::fcn()
        // - but D1 inherits the definition of Base::fcn()
    int fcn(int);
    // v2 is virtual and does not exist in Base
    virtual void f2();
};

class D2: public D1 {
public:
    // fcn(int) hides D1::fcn(int)
    int fcn(int);
    // fcn() overrides virtual Base::fcn()
    int fcn();
    // f2() overrides virtual D1::f2()
    void f2();
};

int main()
{
    // hierarchy: Bulk_quote -> Disc_quote -> Quote
    Bulk_quote bulk;
    // by calling bukl.isbn(), search of isbn 
        // - starts in Bulk_quote, if not found 
        // - then Disc_quote, if not found 
        // - Quote, found
        // - so isbn is resolved to Quote::isbn();
    cout << bulk.isbn();

    Bulk_quote bulk;
    // static and dynamic types are the same
        // - i.e., Bulk_quote and pointer to Bulk_quote
    Bulk_quote *bulkP = &bulk;
    // static and dynamic types are NOT the same
        // - i.e., Bulk_quote and pointer to Quote 
    Quote *itemP= &bulk;
    // bulkP is derived class of Disc_quote so discount_policy() can be found
    bulkP->discount_policy();
    // itemP is of Base class, not a class or derived class of Disc_quote, so discount_policy() can be found
    itemP->discount_policy();

    Base b;
    D1 d;
    // ok - call Base::memfcn
    b.memfcn();
    // ok - call Derived::memfcn
    d.memfcn(10);
    // error - call Derived::memfcn which requires a int argument
    d.memfcn();
    // ok - call Base::memfn in d
    d.Base::memfcn();


    Base bobj; D1 d1obj; D2 d2obj;
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();// call Base::fcn() at run time
    bp2->fcn();// call Base::fcn() at run time
    bp3->fcn();// call D2::fcn() at run time because overriding

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    bp2->f2();//erro - bp2 is a pointer to Base class object, Base has no member named f2; though bp2 points to the address of d1obj
    d1p->f2();//ok - call D1::fcn() at run time
    d2p->f2();//ok - call D2::fcn() at run time because D2 override f2()

    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
    p1->fcn(42);//error - p1 points to a Base object though holds address of a D2 object. there is not Base::fcn(int) version
    p2->fcn(42);//ok - p2 points to a D1 object though holds address of a D2 object. call D1::fcn(int)
    p3->fcn(42);//ok - p3 points to a D2 object and holds address of a D2 object. call D2::fcn(int) becasue D2 has a fcn(int), which hides D1:fcn(int)

    return 0;
}