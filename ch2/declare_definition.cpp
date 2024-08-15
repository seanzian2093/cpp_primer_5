#include <iostream>

extern double pi = 3.1416;
int main()
{
    // Declaration - makes a name known to the program
    // Definition - declares and creates the associated entity

    // Declares but does not define i
    extern int i;
    // Declares and define j
    int j;

    // A declaration that includes an explicit initializer is a definition - overwrites
    // It is an error to provide an initializer on an extern inside a function
    // Below does not compile but it works outside of main(), as in line 3 but with a warning
    // extern double pi = 3.1416;
    std::cout << "pi = " << pi << std::endl;
}
