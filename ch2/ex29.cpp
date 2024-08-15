
#include <iostream>

int main()
{
    // Init input_valu before use
    int input_value;
    std::cin >> input_value;

    // List init not allowed due to loss of information
    // int i = {3.14};
    int i = 3.14;

    // init first
    double salary = 9999.99;
    double wage = salary;
    // works but i2=3 is truncated
    int i2 = 3.14;


    return 0;
}