#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // expression statement
    // - it causes expression to be evaluated and result discarded
    // - most commonly, the expression has a side effect
    int ival = 1;
    // valid but useless - result is discarded; compiler may warn.
    ival + 5;
    // side effect - print to std out
    cout << ival << endl;


    // null statement, i.e., empty statement
    ;

    // Compound statement, i.e., blocks
    // - language requires a single statement
    // - but logic of our program needs more than one
    // - a block is not terminated by semicolon;
    // - could be empty, i.e., empty block {}

}