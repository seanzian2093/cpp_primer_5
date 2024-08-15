#include <iostream>
// reused is in global scope
int reused = 42;
int main()
{
    // unique is in block scope, i.e. within a {}
    int unique = 0;
    std::cout << reused << " "  << unique << std::endl;

    // New, local object named reused, masks global resued - bad practice though
    int reused = 0;
    std::cout << reused << " "  << unique << std::endl;
    // Explicitly request the global reused
    std::cout << ::reused << " "  << unique << std::endl;

    return 0;
}

