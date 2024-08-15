#include <iostream>

using namespace std;

// Overloaded Functions are functions that
    // - have same name 
    // - but different parameter lists
    // - defined in the same scope
    // - intentionally designed to do same/similar thing

Record lookup(const Account&); // #1
Record lookup(const Phone&); // #2
Record lookup(const Name&); // #3

Account acct;
Phone phone;
// call #1
Record r1 = lookup(acct);
// call #2
Record r2 = lookup(phone);

    // - compliers use the arguments types to figure out which function to call
        // - only return type different in defining overloaded function is an error
bool lookup(const Account&);
        // - type alias does not count as different types
typedef Phone Telno;
            // - this redefine the lookup #2, not overload it
Record lookup(const Telno&); // #2

        // - top-level const does not count as different types
            // - a ref or pointer to const or non-const count, i.e. low-level const

Record lookup(Account&); // a func that takes a ref to Account
Record lookup(const Account&); // a new func that take a ref to const Account

Record lookup(Account*); // a func that takes a pointer to Account
Record lookup(const Account*); // a new func that take a pointer to const Account
        

// Overloading and scope
    // - Names do not overload across scopes
        // - if we declare a name in inner scope, names declared in an outer scope are hidden by such inner name
    // - Name lookup happens before type checking
    

int main()
{
    return 0;
}