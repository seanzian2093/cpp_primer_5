#include <iostream>

int main()
{
    // A reference defines an alternative name for an object - a reference type refers to another type
    int ival = 1024;
    std::cout << "ival is "<< ival << std::endl;
    // refVal refers to ival, i.e. is another name for ival
    int &refVal = ival;
    std::cout << "refVal is "<< refVal << std::endl;
    // error: a reference must be initialized
    // int &refVal2;

    // A refenrece is not an object so 
    // - all operations on that reference are actually on the object to which reference is bound
    // - we cannot make a reference itself const
    // We can not define a reference to a reference
    refVal = 2;
    std::cout << "refVal is "<< refVal << std::endl;
    int ii = refVal;
    std::cout << "ii is "<< ii << std::endl;

    return 0;
}

