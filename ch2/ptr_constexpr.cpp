#include <iostream>

int main()
{
    // When we define a pointer in a constexpr declaration
    // - constexpr applies to the pointer
    // - not the type to which the pointer points

    // p is a pointer that points to a const int - nullptr is an const int
    const int *p = nullptr;
    // q is a const pointer that points to a int- the value of nullptr
    constexpr int *q = nullptr;

    // Like any other const pointer, a constexpr pointer may point to a const or non-const
    constexpr int *np = nullptr;
    int j = 0;
    constexpr int i = 42; 
    // What is going on warong?
    constexpr const int *p2 = &i; 
    constexpr int *p3 = &j; 


}