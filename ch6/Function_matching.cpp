#include <iostream>
using namespace std;

void f() {;};
void f(int) {;};
void f(int, int){;};
void f(double, double = 3.14){;};
// Three steps of function matching
    // - Identify candidate function
        // - when call f(5.6) there are 4 functions named f, i.e., 4 candidate functions
    // - Identify viable functions
// f(5.6);
        // - to be viable, a function must have same number of parameter as there are argument in the call
                // - this rules out f() and f(int, int)
        // - type of each argument must mach the type of its corresponding parameter
            // - so f(double, double=3.14) is viable
        // - or be convertible to
            // - so f(int) is viable
        // - compiler complains if there is no viable function
    // - Determine which viable function provides best match for the call
        // - This is an overall best match if there is one and only one function for which
            // - #1 The match for each argumentis no worse than the match required by any other viable function, i.e. all not-worse
            // - #2 at least one argument for which the match is better than the match provided by any other viable functions, i.e., one more better
        // - an exact match is better than a conversion
            
            // - regarding 1st argument, f(int, int) is better than f(double, double=3.14)
            // - regarding 2nd argument, f(double, double=3.14) is better than f(int, int)
                // - so #1 is not satisfied
                // - compiler reject this call because it is ambigous 
// f(42, 2.56);

// casts should not be needed to call an overloaded function.
        // - the need for a cast suggests the parameter sets are designed poorly.

// Ranking of Argument Type Conversions
    // - #1. An exact match
        // - arguments and parameter types are identical
        // - argument is converted from array/function type to corresponding pointer type
        // - top-level const is added to/discarded from the argument.
    // - #2 Match through a const conversion
    // - #3 Match through a promotion
        // - small integral types are always promoted to int or larger integral type
        void ff(int);
        void ff(short);
        ff('a')// char 'a' is promoted to int and passed to ff(), so ff(int) is called
    // - #4 Match through an arithmetic or pointer conversion
        // - All arithmetic conversions are treated as equivalent to eqch other
        void manip(long);
        void manip(float);
        manip(3.14);// 3.14 is a double, could be converted to long or float; neither is better so ambigous

    // - #5 Match through a clss-type conversion


// Function matching and const Arguments
    // - when calling overloaded functions that differ on whether a pointer/ref parameter refers to or points to const
    // - compiler use constness of argument to decide
    Record lookup(Account&);
    Record lookup(const Account&);
    const Account a;
    Account b;
    // call lookup(const Account&)
        // - cannot call lookup(Account&) because we cannot bind a plain ref to a const, a
        // - moreover, it is an exact match
    lookup(a);
    // call lookup(Account&)
        // - we can use b to initializer a ref to either Account or const Account, so both lookup() are viable
        // - but initialize a ref to const from a nonconst, b, requires conversion so lookup(Account&) is exact match
            // - better than lookup(Account&) which requires a conversion
    lookup(b);

int main()
{
    f(5.6);
    f(42, 2.56);
    return 0;
}
