#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include "valuelike.hpp"
#include "pointerlike.hpp"

// if a class defines its own swap, then algorithm uses that class-specific version
    // - otherwise, it uses the swap function defined by the library(?)
    // - not as necessary as copy-control members

inline void swap(HaPtrV &lhs, HaPtrV &rhs)
{
    // use std::swap since both ps and i and built-in types
        // - if they are class type, use their own swap members
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    HaPtrV hpv1("first  hpv");
    HaPtrV hpv2("second hpv");
    cout << "Before swap(): \n";
    print(cout, hpv1);
    print(cout, hpv2);
    cout << "After swap(): \n";
    swap(hpv2, hpv1);
    print(cout, hpv1);
    print(cout, hpv2);


    return 0;
}