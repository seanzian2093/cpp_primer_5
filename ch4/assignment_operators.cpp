#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    // left-hand operand of an assignment operator must be a modifiable lvalue

    // initialization, not assignment
    int i = 0, j = 0, k = 0;
    const int ci = i;

    // error - literal are rvalues
    // 1024 = k;
    // error - arithmetic expressions are rvalues
    // i + j = k;
    // error - const is lvalue but nonmodifiable
    // ci = k;

    // Result of an assignment is its left-hand operand - a lvalue

    // - result is type of left-hand operand
    // - if left and right-hand types differ, right-hand operand is converted to the type of left
    // result k is int  0
    k = 0;
    // result k is int 3
    k = 3.14;
    // use list init
    // ok
    k = {4};
    // error - narrowing conversion is not allow in list init
    // k = {4.1};

    // Assignment is right associative
    int ival, jval, *pval;
    // rightmost assignment jval=0, result is jval
    // jval becomes left-hand operand of ival = jval
    ival = jval = 0;
    // error - cannot assign a pointer pval, to a int, ival
    // ival = pval = 0;

    // Assignment has low precedence than other, e.g., relational ops
}
