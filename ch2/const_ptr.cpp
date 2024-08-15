#include <iostream>

int main()
{
    // const ref actually means a ref that refers to a const
    // I.E. a ref itself cannot be a const

    // top-level constness- const pointer means a pointer itself is a const
    int errNumb = 0;
    // curErr is a const pointer to an int that is errNumb
    // It always points to errNumb
    int *const curErr = &errNumb;

    // low-level constness - pi is a pointer to a const object
    const double pi = 3.14159;
    // pip is a const pointer that points to a const obj - a const double
    const double *const pip = &pi;
}
