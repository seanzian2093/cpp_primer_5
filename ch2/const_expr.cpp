#include <iostream>

int main()
{
    // A const expr is an expr whose value cannot change and
    // can be evaluated at compile time

    // a literal is a const expr
    // a const obj that is initialized from a const expr is also const expr
    
    // max_files is a const and is initialized from a const expr, i.e. literal
    // so it is const expr too
    const int max_files = 20;
    // so is limit;
    const int limit = max_files + 1;

    // staff_size is non-const so it is not a const expr
    int staff_size = 27;


    // sz is a const but initialized at run time so it is not a const expr
    const int sz = get_size();

    // under c++ 11 we use constexpr to declare
    // - a const and  
    // it must be initialized by conxt expr

    constexpr int mf = 20;
    constexpr int limit = mf +1;
    // ok only if size() is a constexpr function
    constexpr int sz = size();

}
