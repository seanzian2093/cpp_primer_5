#include <iostream>

using namespace std;

// fcn can read i but not write to it
void fcn(const int i)
{
    ;
}
// error - redefiing fcn is allowed only when their parameter lists are sufficiently different
// - in prevously defined fcn, const is ignored
// - so these two fcn's parameter lists are not sufficiently different
void fcn(int i)
{
    ;
}

int main() 
{
    // const
    // ci is const, ie. we can not change it
    const int ci = 42;
    // but we can copy its value, its top-level const is ignored 
    int i = ci;
    // p is a const pointer to int
    int * const p = &i;
    // error - we cannot change p
    // p = & ci;
    // - changes through p is allowed; i is now 0
    *p = 0;

    // cp is a pointer to a const int
    // cp now points to i but cannot change i
    const int *cp = &i;

    // r is a ref to a const int
    // r now ref to i but cannot change i
    const int &r = i;

    // r2 is a ref to a const int
    // - ok
    const int &r2 = 42;

    // p is a pointer to int; while cp is a pointer to a const int
    // - error
    int *p = cp;

    // r3 is a plain ref to int while r is ref to const int
    // - error; type no match
    int &r3 = r;

    // r4 is a plain ref to int
    // error: cannot init a plain ref from a literal
    int &r4 = 42;


    cout << "i = " << i << endl;
}