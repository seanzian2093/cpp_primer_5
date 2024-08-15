
#include <iostream>
using namespace std;

// A function
bool lengthCompare(const string &, const string &);

// A pointer that can point to this function
    // - from (), then right, then to left
    // - (*pf) means that pf is a pointer
        // - (...) is a parameter list, meaning pf points to a function
            // bool is a return type, meaning such functiion returns bool 
bool (*pf)(const string &, const string &);


    // - pf2 is a function that returns a pointer to bool
bool *pf2(const string &, const string &);

int main()
{
// when use name of a function as a value, the function is automatically converted to a pointer
    // - no need to use the & operator
    pf = lengthCompare;
    // - we can explicitly use the & operator
    pf = &lengthCompare;

// when use a pointer to a function to call the underlying function
    // - no need to dereference the pointer
    bool b1 = pf("hello", "good bye");
    // - we can explicitly dereference the pointer
    bool b2 = (*pf)("hello", "good bye");
    bool b3 = lengthCompare("hello", "good bye");

// There is no conversion between pointers to different function types.
    // - we can use nullptr or zero-valued integer const expr, 0, to a pointer to function, to indicate such pointer points to nothing
    string::size_type sumLength(const string &, const string &);
    bool cstringCompare(const char*, const char*);
    pf = 0; //ok - pf points to no function
    pf = sumLength; // error - pf points to a function that returns bool, while sumLength returns size_type
    pf = cstringCompare;//error - parameter types differ

    // - applied to overloaded functions
    void ff(int*);
    void ff(unsigned int);
    void (*pf)(unsigned int) = ff; // pf points to ff(unsigned int)
    void (*pf2)(int) = ff; // error - no candidate function of ff matches parameter type, i.e. int 
    double (*pf3)(int*) = ff; // error - return types differ

// Function cannot be a parameter type
    // - but we can have a parameter that is a pointer to a function
        // - here the 3rd parameter is a function that returns a bool type, 
        // - which is automatically treated as a pointer to such function
    void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));
        // - function provided to useBigger is automatically converted to a pointer to it
    void useBigger(s1, s2, lengthCompare);
        // - or we can define a pointer to function explicitly 
    void useBigger2(const string &s1, const string &s2, bool (*pf)(const string &, const string &));

    // - Use type alias and decltype to simply above declaration
        // - Func and Func2 are function type, equivalent
    typedef bool Func(const string &, const string &);
    typedef decltype(lengthCompare) Func2; 
        // - FuncP and FuncP2 are pointer to function type, equivalent
    typedef bool (*FuncP)(const string &, const string &);
    typedef decltype(lengthCompare) *FuncP2; 
            // - useBigger can be defined as follow
    void useBigger3(const string &, const string &, Func);
    void useBigger4(const string &, const string &, FuncP);


// Returning a Pointer to Function
    // - we cannot return a function type but can return a pointer to function, as array
    // - we must write a pointer to function type in return statement, i.e., compiler does not do it automatically
    // - use type alias is the easiest way
    using F = int(int*, int);// F is a function type
    using PF = int(*)(int*, int);// PF is a pointer to function type
    PF f1(int);// ok - f1 returns pointer to function
        // equivalent direct definition - 
            // - f1(int) means that f1 is a function
            // - (*f1(int)) means that f1 returns a pointer
            // - from right to left it means that such pointer points to a function that returns int
    int (*f1(int)) (int *, int);

    F f12(int);// error - f12 returns function which is not allowed
    F *f13(int);// ok - f13 return pointer to function, explicitly
    

    // - using trailing return
    auto f1(int) -> int (*) (int *, int);

    // - using decltype for function pointer type
        // - when we know which functions we want to return, 
        // - e.g., we want to a pointer to largerLength or sumLength, of same return type
    string::size_type largerLength(const string &, const string &);
        // - decltype(func) returns a function type, not a pointer to function
            // - we must use * to indicate we are returning a pointer to function, not a function
    decltype (sumLength) *getFcn(const string &);

    return 0;
}
