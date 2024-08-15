#include <iostream>

int main()
{
    // List init - four ways to init
    int units_sold = 0;
    // int units_sold = {0};
    // int units_sold{0};
    // int units_sold(0);

    long double ld = 3.1415926;
    // error - compiler does not let us list init variables of built-in type if might lead to loss of information
    // For example - 
    // int a{ld}, b = {ld};
    // ok; but value will be truncated
    int c(ld), d = ld;

}