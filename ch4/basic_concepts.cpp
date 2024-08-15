#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Operand conversions
    // as part of evaluating an expression, operands are often converted
    // from one type to another.

    // Overloaded operators
    // We can define what most operators mean when applied to class types
    // giving alternative meaning to an existing operator symbol
    // we refer to them as overloaded operator

    // lvalue and rvalue
    // - lvalues could stand on the left-hand side of an assignment
    // - whereas rvalues could not
    // When using an object as rvalue, we use its value,i.e. contents
    // when using as lvalue, we use its identity, i.e., location in mem
    
    // decltype - when use decltype to an expression(not a varialbe), result is
    // - a reference type if the expression yields an lvalue
    // -- e.g. assume p is a pointer to int
    // -- decltype(*p) is a ref to int

    // - a pointer type if rvalue
    // -- decltype(&p) is a pointer to pointer to int

    // Precedence and Associativity
    int ia[] = {0,2,4,6,8};
    // ia is a pointer
    // -- advance 4 positions and fetch the value
    int last = *(ia + 4);
    cout << "last is: " << last << endl;
    // -- fetch the value and add 4
    int last2 = *ia +4;
    cout << "last2 is: " << last2 << endl;

    // Order of evaluation
    // Precedence specifies how the operands are grouped
    // - nothing about order in which operands are evaluated.

    // We have no way of knowing which of f1 and f2 is evaluated first
    // int i = f1() + f2();

    // FOr operators that do not specify evaluation order
    // it is an error for an expression to refer to and change the same object
    int i = 0;
    // undefined - compiler may evaluate ++1 first or i first
    cout << i << " " << ++i << endl;

    // Operators that guarantee order
    // - logical AND(&&) - left-hand operand is evaluted first
    // - right-hand operand is evaluated if and only if the left-hand is true

    // - logical OR(||)
    // - right-hand operand is evaluated if and only if the left-hand is false
    // - conditional (? :) operator
    // - comma operator
}