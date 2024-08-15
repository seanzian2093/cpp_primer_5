#include <string>

// Pure Virtual Function
    // - specify that a virtual function is a pure virtual by writing =0 in place of a function body
        // - =0 may only appear in declaration of a virtual function in the class body
        // - we can define it outside class body.
    // - a pure virtual function does not need to be defined

// Abstract Base Class
    // - a class containing, or inheriting without overriding, a pure virtual function is an abstract base class
    // - we cannot directly create objects of a type that is abstract base class
        // - we can define objects of classes that inherit from abstract base class, so long as those classes override the pure virtual functions  

// Protected Member
    // - members and friends of a derived class can access the `protected` members
        // - only in base-class objects that are embedded inside a derived type object.
            // - no special access to ordinary objects of the base type

// Purpose of drivation access specifiers
    // - to control the access users have to the members inherited from base class
        // - users of derived classes, i.e, children classes
            // - subsequnt derived classes, i.e. grand-children classes 
    // - derivation access specifier used by a derived class also controls access from classes that inherit from that derived class

// Friendship and Inheritance
    // - friendship is not transtive, and also inherited
        // - Friends of base have no special access to members of its derived classes
        // - Friends of a derived class have no special access to the base class
    // - use `using` declaration to change the access levef of a name that a derived class inherits
        // - can only use `using` for names it has access to

// Default Inheritance Protection Levels
    // - a derived class that is defined with `struct` has `public` inheritance 
    // - a derived class that is defined with `class` has `private` inheritance 
    // - best practice to make it clear by using derivation specifier explicitly
        // - by default, `struct D1 : Base {};` is equivalent to `struct D1 : public Base {};`
        // - by default, `class D2 : Base {};` is equivalent to `class D2 : private Base {};`

class Base {
    // Pal has no access to classes derived from Base
friend class Pal;
public:
    void pub_mem();
    std::size_t size() const { return n; }
protected:
    // protected member
    int prot_mem;
    std::size_t n;
private:
    char priv_mem;
};

class Sneaky : public Base {
    // this clobber is a friend
    friend void clobber(Sneaky&);
    // this clobber is a friend 
    friend void clobber(Base&);
    // j is private by default
    int j;
};

// this clobber can access protected member embedded inside/via a Sneaky object, a derived object
    // - and private member which the `friend` implies
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
// this clobber cannot access protected member of a Base object
void clobber(Base &b) { b.prot_mem = 0; }

struct Pub_Derv : public Base {
    // ok - derived classes can access protected members of base class
    int f() { return prot_mem; }
    // error - derived classes cannot access private member of base class
    char g() { return priv_mem; }
};

struct Priv_Derv : private Base {
    // ok - derived class can access protected members, even the derivation access specifier `private` in declaration
        // - derivation specifier control the access that users of this class have to base class members 
    int f1() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
};

struct Derived_from_Private: public Priv_Derv {
    // error - because Priv_Derv has a `private` derivation specifier so Base::prot_mem remains private 
    int use_base() { return prot_mem; }
};

class Pal {
public:
    // ok - Pal is a friend of Base
    int f(Base b) { return b.prot_mem; }
    // error - Pal is not a friend of Base
    int f2(Sneaky s) { return s.j; }
    // ok - access to Base is control by base, even inside a derived object
    int f3(Sneaky s) { return s.prot_mem; }
};

class D2 : public Pal {
public:
    // D2 is a derived class of Pal, but does not inherit friendship, i.e, it has no access to Base
    int mem(Base b) { return b.pub_mem; }
};

// Derived has private inherihtance from Base
class Derived : private Base {
public:
    // but we want users of Derived have access to size of Base
    using Base::size;
protected:
    // but we want derived of Derived have access to n of Base
    using Base::n;
}

int main()
{
    // main is a user of derived class of Base class
        // - members inherited from Base are public
    Pub_Derv d1;
        // - members inherited from Base are private
    Priv_Derv d2;
        //ok - members inherited from Base are public
    d1.pub_mem();
        //error - members inherited from Base are private, even they are public members
    d2.pub_mem();

    return 0;
}