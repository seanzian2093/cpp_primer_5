#include <iostream>
// main is in global scope
int main()
{
    // sum is in block scope, i.e. within a {}
    int sum=0;
    // val is valid only in the for statement
    for (int val=1; val <=10; ++val)
        sum += val;
    std::cout << "The sum of 1 to 10 inclusive " << " is " << sum << std::endl;

    return 0;
}
