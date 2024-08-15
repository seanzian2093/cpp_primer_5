#include <iostream>

int main()
{
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl;
    // if 32-bits int, prints 4294967264
    std::cout << u + i << std::endl;

    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl;
    std::cout << u2 - u1 << std::endl;

    return 0;
}

