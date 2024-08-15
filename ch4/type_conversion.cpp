#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // implicit conversion among arithmetic types are defined to perserve precision
    // - with double and integer, integer is promoted to double
    // - e.g., 3 to 3.0, the result is double 6.541
    // then initialization happens
    // -  initializer, 6.541, is converted to object's type, int
    // - i.e., fractional part is discarded
    int ival = 3.541 + 3;
    cout << "ival is: " << ival << endl;

    // When implicit conversion happens 
    // - in most expr, values of integral types smaller than int are promoted
    // - in condition, non-bool to bool
    // - in initialization,initializer is converted to declared type
    // - in arithmetic and relational expr, mix types are converted to common types. 

    // Explicit conversion
    int i = 7, j=2;
    // we might want use floating-point division in following coe
    // - but it does not work;
    double q = i/j;
    cout << "q is: " << q << endl;

    // we must explicitly covert i and j to double
    // - static_cast
    // - const_cast

    // a static_cast is often
    // - used to assign larger type to smaller
    // - informs both the reader and compiler that potential loss of precision
    double q2 = static_cast<double>(i)/j;
    cout << "q2 is: " << q2 << endl;

    // - used to perform a conversion that is not automatically by compiler
    // ok - address of any non-const object can be stored in a void *
    void *p = &q;
    // ok - convert void* back to double *
    // - if p is not an address of double, the result is undefined.
    double *dp = static_cast<double*>(p);

    // const_cast changes only low-level const in its operand
    // pc is a pointer to const char, i.e., low-level const
    const char *pc;
    // ok -  const_cast pc to a pointer to a char, not a const char anymore
    // - but writing through p is undefined
    char *p = const_cast<char*>(pc);

    // cp is a pointer to const char
    // error - static_cast cannot cast away constness
    char *q2 = static_cast<char*>(cp);

    // ok - cast string literal to string
    static_cast<string>(cp);
    // error - const_cast only changes constness, not type
    // const_cast<string>(cp);

    // reinterpret_cast
    // - performs a low-level reinterpretation of the bit pattern of its operands
    int *ip;
    // - init pc, a pointer to char, with an address of int
    // - no warning or error from compiler
    // - Subsequent use of pc will assume that it points to a int - correct but meaningless or worse
    char *pc = reinterpret_cast<char*>(ip);
    string str(pc);
}