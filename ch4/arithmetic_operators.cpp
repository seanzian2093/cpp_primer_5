#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int i = 1024;
    int k = -i;
    cout << "i is " << i << endl;
    cout << "k is " << k << endl;
    bool b = true;
    if (b)
        cout << "b is true " << endl;
    else
        cout << "b is false " << endl;

    // b2 is true - should not use bool values in computation
    bool b2 = -b;
    if (b2)
        cout << "b2 is true " << endl;
    else
        cout << "b2 is false " << endl;

    // Division between integers returns an integer
    // - possible fractional part in quotient is discarded
    int ival1 = 21/6;
    cout << "ival 1 is " << ival1 << endl;
    int ival2 = 21/7;
    cout << "ival 2 is " << ival2 << endl;

    // Reminder or modulus operator % - operands must be integer
    int ival3 = 42;
    double dval1 = 3.14;
    cout << "ival3 % 12 is: " << ival3 % 12 << endl;
    // error - double cannot be operands of %
    // ival3 % dval1;

    // int val4 = 1;
    double val4 = 1.1;
    // bool val4 = true;
    // if val4 is not bool, then the bool literal true will be converted
    // - to the type of val4 before the == operator is applied
    // - true to 1 and false to 0
    if (val4 == true)
        cout << "val4==true is true " << endl;
    else
        cout << "val4==true is false " << endl;

}