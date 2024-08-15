#include <iostream>

int main()
{
    // pi is a const
    const double pi = 3.14;

    // ptr is a plain pointer, can not point to a const
    // double *ptr = &pi;
    // Must use pointer to const to point to a const
    const double *cptr = &pi;
    std::cout << "cptr is a const pointer that points to the const pi: " << *cptr << std::endl;
    // error: A point to const can not be used to change its underlying obj
    // *cptr = 42

    // But a pointer to const can point to a non-const obj
    // dval is non-const
    double dval = 3.15;
    // ok;but can change dval through cptr2
    const double *cptr2 = &dval;
    std::cout << "cptr2 is a const pointer that points to non-const dval:" << *cptr2 << std::endl;

    return 0;
}
