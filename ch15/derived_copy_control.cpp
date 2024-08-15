#include <iostream>

// Derived-Class Copy-Contro Members
    // - when we define a copy or move constructor for a derived class, we ordinarily use the corresponding base-class constructor to initialize the base part of object
    // - a derived-class assignment operator msut assign its base-class part explicitly.
    // - a derived-class dustructor is responsible only for destroying the resourses allocated by the derived class
        // - base-class parts of an object are implicitly destroyed


class Base {
};

class D : public Base {
public:
    // default constructor
        // - compiler use Base's default constructor to initialize the Base part of D object
    // copy constructor
        // - use Base's copy constructor to copy the Base part
            // - d is a D object, its Base part is copied to the temp Base object that is being created
            // - if this is omiited, Base default constructor would be used to initialize the Base-part, i,e,. 
                // - Base-part would hold default values
                // - derived-part would hold values copied from d
    D(const D& d) : Base(d) {}
    // Move concstructor
        // - use Base's move constructor to copy the Base part
    D(D&& d) : Base(std::move(d)) {}

    // Assignment operator
    D& operator=(const D&);

    // Destructor
    ~D() {}
};

    // - Base::operator(const Base&) is not automatically involved
D &D::operator=(const D &rhs)
{
        // - call Base::operator() explicitly to assgin the Base part
    Base::operator=(rhs);
        // - assign derived -members as usual
    return *this;
}

int main()
{


    return 0;
}