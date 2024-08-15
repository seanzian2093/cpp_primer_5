
#include "quote.hpp"

// Virtual Destructors
    // - destructor is run when we `delete` a pointer to a dynamically allocated object
    // - if that pointer points to a type in an inheritance hierarchy, it is possible that
        // - static type of that pointer might differ from
        // - the dynamic type of the object being destroyed 
        // - e.g. p is a pointer of type Quote*, but may point to a Bulk_quote object
        // - when we `delete p;`, the compiler has to know that it should run Bulk_quote destructor
    // - use `virtual` and `override` to arrange to run proper destructor
        // - executing `delete` on a pointer of Base type that points to a object of Derived type has undefined behavior if
            // - base class's destructor is not `virtual`
        // - if a base class has virtual destructr, it does not need to have assignment operator or copy constructor
            // - compiler will not synthesize a move operator for the class

// Synthesized Copy Control and Inheritance
    // - synthesized default constructor, or any copy-control member of a base or derived class may be defined as deleted
        // - the way in which a base class is defined can cuase a derived-class member to be defined as deleted
        // - if the defulat constructor, copy constructor, copy-assignment operator, or destructor in base class is `deleted` or inaccessible
            // - coresponding member in derived class is defined as `deleted` bacause
                // - compiler cannot use the base-class member to construct, assign, destroy the base-class part of the object
        // - if the base class has an inaccessible or `deleted` destructor 
            // - the synthesized default and copy constructor in the derived classes are defined as deleted, because
                // - there is no way to destroy the base-class part of the derived object 
        // - compiler will not synthesize a `deleted` move operation
            // - if we use `=default` to request a move operation, it will be a `delted` function in the derived 
                // - if corresponding operation in the base is deleted or inaccessible, because
                    // - the base-class part cannot be moved 
            // - move constructor will also be `deleted` if base-class destructor is deleted or inaccessible 
        // - in practice, if a base class does not have a default, copy, or move constructor
            // - then its derived classes usually don't either
    
// Derived-Class Copy-Contro Members
    // - in derived_copy_control.cpp

// Inheritated Constructor
    // - Under new standard, a derived class can reuse the constructors defined by its direct base class
        // - also referred as inheritaed, not in the normal sense
        // - only from its directly base
        // - cannot inherit the default, copy, and move constructor
            // - if a derived class does not direcly define those constructors, compiler synthesizes them
    // - a derived class inherits its base-class constructors by providing a `using` declaration that names its direct base class 
        // - if the derived class has any members of its own, those member are default initialized in such constructors
        // - does not change the access level of inherited constructors, regardless of where the `using` declaration appears
            // - a `private` constructor in the base is a `private` constructor in the derived, similarly for `protected` and `public`
        // - cannot specify `explicit` or `constexpr`, inheritaed constructor has same property

class Bulk_quote : public Disc_quote {
public:
    // inherit Disc_quote's constructor
    using Disc_quote::Disc_quote;
    // Euqivalent to 
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
    // other members
}


class B {
public:
    B();
    B(const B&) = delete;
};

class D : public B {
    // no constructors
};

int main()
{
    // same static and dynamic type - pointer of Quote* and points to a Quote object
    Quote *itemP = new Quote;
    // - destructor for Quote called
    delete itemP;
    // different static and dynamic type - pointer of Quote* but points to a Bulk_quote object
    itemP = new Bulk_quote;
    // - destructor for Bulk_quote called
    delete itemP;

    // ok - compiler synthesizes D's default constructor using B's default constructor
    D d;
    // error - compiler synthesizes a `delete` copy constructor for D since its base class B's copy constructor is `deleted`
    D d2(d); 
    // error - move implicitly uses D's copy constructor which is `deleted`
    D d3(std::move(d));

    return 0;
}
        