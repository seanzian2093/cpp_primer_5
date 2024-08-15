#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Commonly called loops
    // - while and for statements test the condition before executing the body
    // - do while executes the body and then tests its condition

    // while 
    // - condition may not be empty
    // - ordinarily, the condition itself or the loop body must do something to change to value of expression
    // - otherwise, loop might never terminate.
    // - var defined in a while condition or while body are created and destroyed on each iteration

    // for
    // - for (init-statement; condition; expression)
    // - init-statement is executed once and only once at the start of the loop.
    // - init statement must be only a single declaration - if it defines multiple objects, they must be the same base type
    // - visibility of any object defined within the for header is limited to the body of for loop
    // - any part of the header can be omitted by null statement

    // range for
    // - for (declaration: expr)
    // - expr must represent a sequence,i.e., a braced init list, an array or a vector or string 
    // - which has begin() and end() members that return iterators.
    // - declaration defines a variable 
    // - It must be possible to convert each element of the sequence to the variable's type
    // - easist way to ensure that is to use auto tyep specifier

    // do while
    // - do statement while (condition);
    // - var in condition must be defined outside the body of the do statement
}