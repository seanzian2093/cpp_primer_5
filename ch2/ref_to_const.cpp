#include <iostream>

int main()
{
    const int ci2 = 1024;
    // r1 is a reference to a const, ci2
    const int &r1 = ci2;
    //error; r1 is a ref to const, we can not assign to it
    // r1 = 42;
    //error: attempt to create an int refernece to a const 
    // int &r2 = ci;
    const int &r2 = 1025;
    const int &r3 = r1 * 2;
    // error : r4 is a ref to int, but r2 is ref to const int; does not match
    // int &r4 = r2 * 2;

    // A ref to const may refer to an object that is not const
    int i4 = 42;
    // r4 refers to i4
    int &r4 = i4;
    // r5 is a ref to const, it refers to i4 also but can not be used to change i4;
    const int &r5 = i4;
    // change i4 to 0
    r4 = 0;
    // error: r5 is a ref to const
    // r5 = 0;

    return 0;
}

