#include <iostream>
using namespace std;

int main()
{
    // Type alia - typedef
    // wages is a synonym for double
    typedef double wages;
    // base is a synonym for double, p for a pointer to wages/double
    typedef wages base, *p;

    wages w = 1000.00;
    cout << "w: " << w << endl;
    wages *pw = &w;
    cout << "w is at " << pw << endl;

    using age=int;
    age a = 35;
    cout << "a is " << a << endl;

    // pstring is a pointer to char
    typedef char *pstring;
    // cstr is a const pointer to char
    const pstring cstr = 0;
    // ps is a const pointer to a pointer to char
    const pstring *ps;

    // auto tells compiler to deduce the type from initializer
    int val1 = 1;
    cout << "size of val1:" << sizeof(val1) << endl;
    double val2 = 0.2;
    cout << "size of val2:" << sizeof(val2) << endl;
    auto val3 = val1 + val2;
    cout << "size of val3:" << sizeof(val3) << endl;

    return 0;
}
