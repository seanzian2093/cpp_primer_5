#include <iostream>

int main()
{
    // Unlike a reference - 
    // A pointer is an object
    // Pointers can be assigned and copied
    // A pointer can poin to multiple objects over lifetime
    // Need not be initialized at defining time
    // Pointers defined at block scope have undefined value if not initialized, like other buit-in types.

    // A pointer holds the address of another object which is accessible by & operator - not reference
    int ival = 42;
    std::cout << "ival is "<< ival << std::endl;
    // p is a pointer that points to ival
    // p holds address of ival, resulting of &ival operation
    int *p = &ival;
    std::cout << "p is "<< p << std::endl;
    // dereference operation - * operation
    std::cout << "p points to "<< *p << std::endl;

    // Assigning through pointer
    *p = 0;
    std::cout << "p points to "<< *p << std::endl;

    double dval;
    double *pd = &dval;
    double *pd2 = pd;
    // error - pd points to an int
    // int *pi = pd;
    // error - assigning the address of a double to a pointer to int
    // pi = &dval;

    // null pointer - does not point to any object
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    // Illegal to assign int to pointer
    int zero = 0;
    // error
    // int *pi = zero;

    // void* is a special pointer type that can hold address of any object.
    // We cannot use a void* to operate on the object it addresses - we do not know the type
    double obj = 3.14, *pd3 = &obj;
    void *pv = &obj;
    pv = pd3;
}