#include <string>
using std::string;

#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::make_shared;

#include <vector>
using std::vector;


// When we defind a class, we specify what happens when obejcts of said class type are
    // - copied, moved, assigned, and destroyed
    // - explicitly or implicitly
    // - A class controls below operations by defining special functions
        // - copy constructor, copy-assignment operator, move constructor, move-assignment operator, destructor
        // - refered as copy control
    // - if a class does not define all of copy-control members, compiler automatically defines missing ones.
    // - use =default to explicity ask compiler to generate synthesized versions of copy-control member functions
        // - by defining them as =default

// Copy Constructor
    // - a constructor if its first parameter is a ref to the class type
    // - and any addional parameters have default values
    // - should not be explicit, i.e., modified by `explicit` keyword
    // - memberwise copies the member of its argument into the object being created
        // - non-static member
        // - member of class type are copied by its copy constructor
        // - member of built-in type are copied directly
        // - member of array are copied by copying each of its elements
    // - when use direct initialization, we are asking compiler to use ordinary function matching to select constructor that best matches arguments provided.
    // - we use copy initialization, we asking compiler to copy the right-hand operand into the object being created, converting if necessary
        // - during copy initialization, compiler is permitted but not obligated, to skip copy/move constructor and create teh object directly

// Copy-Assignment Operator
    // - assignment operator is one of overloaded operators which
        // - are functions that have the name `operator` followed by teh symbol for operator being defined 
            // - e.g., assignment operator is a function named `operator=`
            // - has return type and parameter list
            // - parameters represent the operands of the operator 
            // - some operators, e.g., assignment operator, must be defined as member functions
                // - in such cases, left-hand operand is bound to the implicit `this` parameter
                // - right-hand operand in a binary, i.e., assignment, is passed as an explicit parameter
        // - assignment operator takes an argument of same type as the class
        // - return a ref to left-hand operand, to be consistent with assignment for built-in types

// Destructor
    // - do whatever is needed to free resources used by an object and 
    // - destroy the non-static data members of the object.
    // - a member function with same name of class, prefixed by a tilde~
        // - has no return type
        // - takes no parameters
            // - thus cannot be overloaded so only one destructor for a given class
    // - function body is executed first and then
    // - members are destroyed
        // - members are destroyed in reverse order from the order in which they were initialized
        // - member of class type are destroyed by running the member's own destructor
        // - built-in types do not have destructors, so nothing is done to destroy them
            // - built-in pointer type does not delete the object to which that pointer points
            // - smart pointers are class type and has their own destructors
    // - constructor is not run when a ref/pointer to an object goes out of scope

// Ruel of Three/Five
    // - Classes that need destructors need copy and assignment
    // - most classed should define, implicitly or explicitly, the default constructor, copy constructor, and copy-assignment operator

// Defining a Function as Deleted
    // - since C++11, we can prevent copies by defining the copy constructor the copy-assignment operator as deleted functions which 
        // - is one that is declared but may not be used in any other way
        // - by following its parameter list with `=delete`

// For some classes, compiler defines these syhthesized members as deleted functions
    // - in essence, the copy-control members are synthesized as deleted when it is impossible to copy, assign, or destroy a member of the class. More specifically
    // - synthesized destructor is defined as deleted if the class has a member whose own destrucotr is deleted or inacceessible, e.g., private 
    // - synthesized copy constructor is defined as deleted 
        // - if the class has a member whose own copy constructor is deleted or inacceessible, e.g., private 
        // - if the class has a member whose own destructor is deleted or inacceessible, e.g., private 
    // - synthesized copy-assignment operator is defined as deleted 
        // - if the class has a member has deleted or inacceessible copy-assignment operator
        // - if the class has a const or reference member
    // - synthesized default constructor is defined as deleted 
        // - if the class has a member has deleted or inacceessible destructor
        // - if the class has a reference member that does not have an in-class initializer
        // - if the class has a const member 
            // - whose type does not explicitly define a default constructor and 
            // - does not have in-class initializer


struct NoCopy {
    NoCopy() = default;
    // no copy
    NoCopy(const NoCopy&) = delete;
    // no assignment
    NoCopy &operator=(const NoCopy&) = delete;
    ~NoCopy() = default;
};
    // - Destructor should not be a deleted member
        // - not possible to define an object of a type with a deleted destructor
        // - not possible to delete a pointer to a dynamically allocated object of a type with deleted destrutor
struct NoDtor {
    NoDtor() = default; 
    ~NoDtor() = delete; 
};

void fcn()
{
    NoDtor nd;// error - NoDtor is a type with a deleted destructor
    NoDtor *p = new NoDtor();
    delete p;// error - p points to a dynamically allocated object of  type NoDtor whch is with a deleted destructor
}


class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    // A self-defined destructor means we need define copy operator and assignment operator too
    ~HasPtr() { delete ps; }
private:
    string *ps;
    int i;
};

// hp is copied from argument to parameter
HasPtr f(HasPtr hp)
{
    // hp is copied to ret
    HasPtr ret = hp;
    // ret is copied to returned value
    return ret;
} 
// when f returns, both hp and ret are destroyed by the HasPtr destructor which deletes the `ps` in each object
    // - but `ps` in hp and ret point to same object/memory
    // - deleting a dynamic memory twice is undefined
    // - caller of f may use the object that is passed to f as parameter


class Foo {
public:
    // declare an assignment operator
    Foo & operator=(const Foo&);
    // declare an destructor
    ~Foo();
};


class Sales_data {
public:
    // declare default constructor
        // explicitly generate synthesized versions of constructor by using = default
            // - inline function
    Sales_data() = default;

    // declare a copy constructor
    Sales_data(const Sales_data&);
        // explicitly generate synthesized versions of copy operator by using = default
            // - inline function
    Sales_data(const Sales_data&) = default;

    // declare a copy-assignment operator 
    Sales_data& operator=(const Sales_data &);

    // declare and define destructor
        // - no work to do other than destroying the members, which happens automatically
    ~Sales_data() {}
        // explicitly generate synthesized versions of destructor by using = default
            // - inline function
    ~Sales_data()=default;
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// Define own copy constructor 
    //- which is equivalent to synthesized copy constructor
Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),
    units_sold(orig.units_sold),
    revenue(orig.revenue)
    { }

// Define own copy-assignment operator 
    //- which is equivalent to synthesized copy-assignment operator 
Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    // return a ref to `this` object
    return *this;
}

    // explicitly generate synthesized versions of copy-assignment operator by using = default
            // - inline function
Sales_data& Sales_data::operator=(const Sales_data &rhs) = default;


int main()
{
    string dots(10, '.'); // direct init
    string s(dots); // direct init
    string s2 = dots;// copy init
    string null_book = "9-999-99999-9";// copy init
    string null_book("9-999-99999-9");// compiler may rewrite above to omit copy constructor 
    string nines = string(100, '9');// copy init

    // WHen destructor is called
    {// new local scope
        // p is a built-in pointer
        Sales_data *p = new Sales_data;
        // p2 is a shared_ptr, a smart pointer
        auto p2 = make_shared<Sales_data>();
        // copy constructo copies *p into item, an object of class type
        Sales_data item(*p);
        // vec is a local object
        vector<Sales_data> vec;
        // copy p2's underlying object to vec
        vec.push_back(*p2);
        // destructor called on object that is pointed to by p
        delete p;
    }// exit local scope: desturctor called on item, p2, and vec
        // - destroying p2 decrements its reference count, if which goes to 0, the object is freed
        // - destryoing vec by destroying elements in vec

    return 0;
}