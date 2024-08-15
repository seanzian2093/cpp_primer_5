#include <iostream>

int main()
{
    // A const must be initialized
    const int bufSize = 512;
    // Error - any attempt to assign to a const is an error
    // bufSize = 512;

    int i = 42;
    //ok; the value of i is copied into ci
    const int ci = i;
    //ok: value of ci is copied to j
    const int j = ci;

    // const is local to file
    // Use the keyword extern on both definition and declaration to share the const across files
    // in file_1.cc
    // extern const int bufSize2 = 1024;
    // in file_1.h
    extern const int bufSize2;

    return 0;
}
