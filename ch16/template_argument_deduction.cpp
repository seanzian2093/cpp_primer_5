#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include<utility>
// using std::forward;


#include <type_traits>
using std::remove_reference;

/*
By default, compiler uses arguments in a call to determine template parameters for a function template. This process is called
template argument deduction

NOTE - declare and define function template in this source file otherwise there will be a compile error - undefined symbol from architecture arm64
*/


// Conversions and Template Type Parameters
    // - arguments we pass in a call to a function template are used to initialized that function's parameters
        // - as with non-template function
    // - only a very limited number of conversions are automatically applied to such arguments
        // - compiler generates a new instantiation, rather than converting the arguments
    // - Conversions
        // - top-level const in either parameter or argument are ignored
        // - const conversion, i.e., a ref/pointer to non-const object can be passed to function parameter which expects a ref/pointer to a const
        // - array- or function-to-pointer conversions, i.e., for a function parameter that is not a ref type
            // - an array argument is converted to a pointer to its first element
            // - a function argument is converted to a pointer to the function's type
        // - other conversions are not performed
            // - arithmetic conversions
            // - derived-to-base conversion
            // - uder-defined conversion
        // - e.g. consider calls to the functions fobj and fref
            // - arguments are copied
template <typename T> int fobj(T, T)
{
    return 0;
}
;
            // - arguments are ref
template <typename T> int fref(const T&, const T&)
{
    return 0;
};

    // - Function Parameters That Use Same Template Parameter Type
        // - One template type parameter can be used as the type of multiple parameters
            // - argument to such parameter must be essentially same type due to limited conversions, i.e., last section
            // - e.g. compare takes 2 arguments of type T
        // - if we want to allow normal conversions on the arguments, we can define the function with two type parameters
            // - those types must compatible regarding to operations in the functio body(?)
template <typename T> int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
};

template <typename A, typename B> int flexibleCompare(const A &v1, const B &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
};

    // - Normal Conversions Apply for Ordinary Arguments
        // - a functon template can have parameters that are defined using ordinary types
            // - i.e., types does not involve template type parameter
            // - normal conversions apply
            // - e.g., `print`, its first parameter is a ostream type, second parameter is a template parameter type
                // - when `print` is called, normal conversion applies to argument that passes to os
template <typename T> ostream &print(ostream &os, const T &obj) 
{
    return os << obj;
};

// Function-Template Explicit Arguments
    // - Specifying an Explicit Template Argument
        // - let user control the return type by defining a template parameter to represent the return type
        // - e.g. `sum`
            // - matching from left to right
                // - only right-most parameters can be omitted and only if they can be deduced
template <typename T1, typename T2, typename T3> T1 sum(T2 a, T3 b)
{
    return a + b;
};

template <typename T1, typename T2, typename T3> T3 poor_sum(T1 a, T2 b)
{
    return a + b;
};

// Trailing Return Types and Type Transformation
    // - a trailing return appears after the parameter list, so it can use function's parameters

template <typename It> auto fcn(It beg, It end) -> decltype(*beg)
{
    // decltype(*beg) deduces a ref to the type of element that beg denotes
        // - decltype returns a ref type for expr that yields lvalue
    return *beg;
};

    // The Type Transformation Library Template Classes
        // - to obtain element type in `fcn` we can use a libary `type transformation` template
            // - defined in `type_traits` header - ch16.5 
            // - decltype(*beg) is a ref to an element
                // - remove_reference<decltype(*beg)> is the type of the element 
template <typename It> auto fcn(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
{
        // - return a copy of an element that is denoted by beg
    return *beg;
};

// Function Pointers and Argument Deduction
    // - when we initialize or assign a function pointer from a function template, compiler uses type of pointer to deduce template types
    // - e.g. pf1 is a pointer to a function which
        // - return int
        // - takes 2 arguments, const int& and const int&
        // - pf1 1 points to an instantiation of compare
            // - compile deduce, from pf1 type info, that compare be instantiated as compare(const int&, const int&)
int (*pf1) (const int&, const int&) = compare;
    // - error if compiler cannot do such
        // - e.g., overloaded versions of func which takes one argu, i.e., a pointer to function which return int and takes 2 arguments
void func(int (*) (const string&, const string&));
void func(int (*) (const int&, const int&));
            // - `func(compare);` in main() body will cause an error - compiler cannot determine which version to instantiate compare
            // - we must explicitly specify which version to instantiate, e.g., `func(compare<int>);` 

// Template Argument Deduction and References
    // - type deduction from lvalue ref function parameters
        // - we can only pass an lvalue, e.g., a var or an expr that return a ref type
            // - might or might not have a const type. if argument is const, T will be deduced as a const type
        // - e.g., 
            // - f1's argument must be an lvalue;
            // - f2's argument must be an rvalue;
            // - f3's argument takes rvalue
                // - when lvalue is passed, compiler deduces T as argument's lvalue ref type
                    // - e.g., f3(i), compiler deduces T as int&, not int, so it is f3(T&&)
                // - when we indirectly create a ref to a ref(ordinarily we cannot directly)
                    // - thoese references collapse
                        // - X& &, X& &&, and X&& & to X& 
                        // - X&& && to X&&
template <typename T> void f1(T &p) { ; };
template <typename T> void f2(const T &p) { ; };
template <typename T> void f3(T &&p) { ; };

// How std::move() works

// Forwarding
    // - Some functions need to forward one or more of their arguments with their types unchanged to another, forwarded-to, function.
        // - in such case we need to preserve everything about the forwarded arguments, const-ness, lvalue or rvalue, etc
        // - e.g., in flip1(), t1 is a plaintype, i.e., int, argument will be copied
template <typename F, typename T1, typename T2> void flip1(F f, T1 t1, T2 t2) { f(t2, t1); };
void f(int v1, int &v2) { cout << v1 << " " << ++v2 << endl; }
    // - we can preserve all type information in an argument by defining its corresponding function parameter as an rvalue ref to a template type parameter 
        // - e.g., in flip2, &&t1 is a rvalue ref to T1, etc
            // - but flip2 works only with function that takes lvalue ref, e.g., f
                // - not g, i.e., flip2(g, j, 42) passes &&t2 to g'j which is lvalue parameter, error arises
template <typename F, typename T1, typename T2> void flip2(F f, T1 &&t1, T2 &&t2) { f(t2, t1); };
void g(int &&i, int &j) { cout << i << " " << j << endl; }
    // - use std::forward to prevserve type information in a call
        // - forward is defined in `utility` header
        // - return rvalue ref, i.e., type of forward<T> is T&&
        // - ordinarily use `forward` to pass a function parameter that is defined as an rvalue ref to a template type parameter
            // - e.g., `template <typename Type> intermediary(Type &&arg) { finalFcn(std::forward<Type>(arg)); };`
            // - rewrite flip
template <typename F, typename T1, typename T2> void flip(F f, T1 &&t1, T2 &&t2) 
{
    f(std::forward<T2>(t2), std::forward<T1>(t1)); 
};

int main()
{
    string s1("a value");
    const string s2("another value");

    // call fobj(string, string); const on s2 is ignored
    fobj(s1, s2);
    // call fref(const string&, const string&)
        // s1 is converted to const, as if `const s1 ("a value");`
    fref(s1, s2);
    int a[10], b[42];

    // call fobj(int*, int*)
        // array is converted to pointer to its first element
    fobj(a, b);
    // error - can not convert to ref
    // fref(a, b);

    long lng;
    // error - cannot instantiate compare(long, int)
    // compare(lng, 1024);
    // ok - instantiate flexibleCompare(long, int)
    flexibleCompare(lng, 1024);

    // ok - instantiate print(ostream&, int)
    print(cout, 42);
    cout << endl;
    ofstream fstrm("output.txt");
    // ok - instantiate print(ostream&, int); convert f to ostream&
    print(fstrm, 42);

    // explicitly specify that return type is long long,
        // - T2 and T3 are omitted
        // - T2 and T3 are deduced from arguments
    auto val1 = sum<long long>(42, lng);
    cout << val1 << endl;

        // - third tempalate parameter is return type, we must specify all three parameters - poor design
    auto val2 = poor_sum<long long, int, long>(42, lng);
    cout << val2 << endl;

        // ok - instantiate compare(long, long)
            // - 1024, int leteral, is converted to long
    compare<long>(lng, 1024);
        // ok - instantiate compare(int, int)
            // - lng is converted to int
    compare<int>(lng, 1024);

    int i = 9;
    int *pi = &i;
    decltype(&pi) x;
    cout << x << endl;

    // type deduction from lvalue
    const int ci = 42;
        // ok - T is deducec as int
    f1(i);
        // ok - T is deducec as const int
    f1(ci);
        // error- int literal is not a lvalue
    // f1(5);

        // ok - T is deducec as int, i.e., f2(const int&)
    f2(i);
        // ok - T is deducec as int, i.e., f2(const int&)
            // - const on ci is irrelavent
    f2(ci);
        // ok - int literal can be bound to const &, i.e., f2(const int&)
    f2(5);

        // - i is lvalue, so T is deduced to int&, so f3(int& &&), collapses to f3(int&)
    f3(i);
        // - ci is lvalue, so T is deduced to const int &, collapses to f3(const int&)
    f3(ci);
        // ok - int literal can be bound to const &, i.e., f3(int&&)
    f3(5);

    // forwarding
    int j = 55;
    f(42, i);
    cout << "after f(42, i), i is now: " << i << endl;
    flip1(f, j, 42);
    cout << "after flip1(f, j, 42), j is now: " << j << endl;

    flip2(f, j, 42);
    cout << "after flip2(f, j, 42), j is now: " << j << endl;

    // error - g take lvalue as second parameter, but j is passed as rvalue ref
    // flip2(g, j, 42);
    // ok - 
    flip(g, j, 42);
    cout << "after flip(g, j, 42), j is now: " << j << endl;

    return 0;
}