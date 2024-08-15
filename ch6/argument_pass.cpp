#include <iostream>

using namespace std;

// Pointer parameter - passed by value, i.e., address
void reset(int *ip)
// takes a pointer to int as parameter
// - address of that int is copied to a local pointer ip
// - the address of that int is unchanged
// - in c++, reference parameters are generally used, rather than pointer parameter
{
    // set the underlying int to 0 since it is still the address of that int
    *ip = 0;
    // ip is a local copy of the original ip; will not change the provied argument
    ip = 0;
    cout << "ip = " << ip << endl;
}

// reset by ref
// the parameter is a ref to int so argument is passed by ref
void reset_ref(int &i)
{
    // i is another name for the object passed here
    // operation on ref is direcly on the underlying object
    i = 0;
}
int main()
{
    // Passed by ref
    // - when a parameter is a reference
    // - the function is called by ref
    // - parameter is an alias for the argument and the underlying object

    // Passed by value
    // - when argument value is copied
    // - the function is called by value
    // - argument and parameter are independent objects.

    int i = 42;
    // pass i's address to parameter *ip
    reset(&i);
    // i reset to 0
    cout << "i = " << i << endl;
    // i's address is not changed to 0
    cout << "&i = " << &i << endl;

    int j = 99;
    reset_ref(j);
    // j reset to 0
    cout << "j = " << j << endl;
}
