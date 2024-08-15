#include <iostream>

int main()
{
    int i = 42;
    // A pointer
    int *p;
    // from right to left &, a ref, and *,a pointer - so r is a ref to a pointer
    int *&r = p;
    // Assign - now r refers to a pointer to i
    r = &i;
    // Assign 0 to the derefence of r, i.e., i
    *r = 0;

    return 0;
}
