#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <utility>

#include "strvec.hpp"

// Move Operations
    // - library containers, string, and shared_ptr classes support move and copy
    // - IO and unique_ptr classes can be moved but not copied
    // - to support move operations, rvalue reference is introduced in new standard c++11
        // - regular reference is called lvalue references
    // - compiler synthesizes mmove constructor and move-assignment operator if 
        // - a class does not define any of its own copy constructor, copy-assignment operator, destructor
    // - when a class does not have move operations, the corresponding copy operation is used in place of move
        // - through normal function matching
    // - we a class has both move constructor and copy constructor, compiler uses ordinary function matching to determine which to use
        // - similarly for assignment
        // - rvalues are copied if there is no move constructor

// expressions that return lvalue
    // - functions that return lvalue reference
    // - assignment
    // - subscript
    // - dereference
    // - prefix increment/decrement operators 

    // - lvalue are persistant

    // - we can bind an lvalue reference to the result of any of these expressions 
        // - variables are lvalue, i.e. operand without operator
        // - so we cannot bind an rvalue reference to a variable defined as an rvalue


// expressions that return rvalue
    // - functions that return non-reference type
    // - arithmetic operators
    // - relational operators
    // - bitwise operators
    // - postfix increment/decrement operators

    // - rvalue are ephemeral 

    // - we cannot bind an lvalue reference to such expression
    // - we can bind an lvalue reference to const version of the result of any of these expressions 
    // - we can bind an rvalue reference to such expression

// Library move function
    // - defined in `utility` header, ch16
    // - return an rvalue reference to its given object
    // - after move, we cannot use the value of the moved-from object
        // - the value is undefined(?)
        // - must lease the moved-from object in a destructible state
    // - 

int main()
{
    int i = 42;
    int &r = i;
    // error - i is lvalue
    // int &&r = i;

    // error - i * 42 is rvalue
    // int &r2 = i * 42;
    // ok - const version of rvalue can be bound to lvalue reference
    const int &r3 = i * 42;
    // ok - i * 42 is rvalue, can be bound to rvalue reference
    int &&rr2 = i * 42;

    // after move, we cannot
    int  &&rr3 = std::move(rr2);

    StrVec vec;
    string s = "some string or another";
    vec.push_back(s);// call the copy version of push_back 
    vec.push_back("done"); // call the move version of push_back
}