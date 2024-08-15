#include <iostream>

int main()
{
    int ival = 1024;
    // pi points to an int
    int *pi = &ival;
    // ppi points to a pointer to an int
    // To access the underlying object, we must dereference the original pointer twice
    int **ppi = &pi;

    std::cout << "The value of ival\n"
              << "direct value: " << ival << "\n"
              << "indirect value: " << *pi << "\n"
              << " doubly indirect value: " << **ppi 
              << std::endl;

    return 0;
}
