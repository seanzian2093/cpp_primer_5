#include <iostream>
#include <string>
#include <vector>

using namespace std;

// fact has 
// - one parameter
// - int type

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        // assign ret*val to ret and decrement val
        // - decrement afterhand so the -- after val
        ret *= val--;
    
    return ret;
}

// parameter list
// - can be empty
// - cannot be omitted
void voidf()
{
    cout << "voidf is a function with empty parameter list" << endl;
}
void voidf2(void)
{
    cout << "voidf2 is a function with a void as parameter list" << endl;
}

// Parameter list is a comma-separated list of paramters
// - each looks like a declaration with single declarator
// - even when types are same, the type must be repeated
// error - int int_mul(int v1, v2)
int int_mul(int v1, int v2)
{
    return v1 * v2;
}

// Function return type
// - can be void, which means no return value
// - cannot be a 
    // - array type but can be a pointer
    // - function type
// - but can be a pointer to an array or a function

// Automatic objects
// - local variables are created when function's control path passes through the variable's definition
// - destroyed when control passes through the end of the block inwhich the variable is defined.
// - function parameters are automatic objects.
    // - if no initializer provided, they are default initialized
    // - uninitialized local variables of built-in type have undefined values.

// local static object
// - whose lifetime continues across calls to the function
// - destroyed when program terminates.

size_t count_calls()
{
    // ctr persists across calls
    static size_t ctr = 0;
    return ++ctr;
}

// Function declaration - aka function prototype
// - a function must be declared before use, like any other name
// - may be defined only once but may be declared multiple times.
// - declare a function that is not defined so long as we never use that function.
// - in function declaration
    // - function no body is replaced with a semicolon;
    // - paramters can be omitted.

int main()
{
    // we must 
    // - provide one argument
    // - which can be converted to int
    // - compiler may warn
    int j = fact(5);
    cout << "5! is " << j << endl;

    j = fact(6.14);
    cout << "fact(6.14) is " << j << endl;

    voidf();
    voidf2();

    for (size_t i = 0; i != 10; ++i)
        cout << count_calls() << endl;
    return 0;
}