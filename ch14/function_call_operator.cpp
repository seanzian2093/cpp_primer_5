#include <iostream>
#include <functional>
using namespace std;

// Classes that overload the call operator( () ) allow objects of its type to be used as if they were a function
    // - they are more flexible than ordinary function because they can also store state
        // - are refered as function object
    // - function-object classes often contain data members that are used to customize operations in call operator

// - lambdas are function objects
    // - compiler translate lambda expr into an unnamed object of unnamed functon-object class
    // - function-call operator in a such class is a const member
        // - if the lambda is declared as mutable, the call operator is not a const member
    // - when a lambda capture a var by ref, compiler can use the ref directly without stroing the ref as a member
    // - when a lambda capture a var by value, the generated function-object class has a member correspondingly

// Library Function Objects
    // - defined in `functional` header
    // - arithmetic
        // - plus<Type>
        // - minus<Type>
        // - multiplies<Type>
        // - divides<Type>
        // - modules<Type>
        // - negate<Type>
    // - relational
        // - equal_to<Type>
        // - not_equal_to<Type>
        // - greater<Type>
        // - greater_equal<Type>
        // - less<Type>
        // - less_equal<Type>
    // - logical
        // - logical_and<Type>
        // - logical_or<Type>
        // - logical_not<Type>

// Callable Objects and `function`
    // - callable objects
        // - functions, pointers to functions
        // - lambdas
        // - objects created by `bind`
        // - function-object classes
    // - call signature
        // - call signature specifies the return type and argument type(s) 
            // - e.g. int(int, int) is a call signature corresponding to a function type that
                // - takes two int, return a int 
    // - `function` type
        // - defined in `functional` header
        // - function<T> f
            // - f is null function object that can store callable objects with a call signature of T
        // - function<T> f(nullptr)
            // - explicitly construct f as null function
        // - function<T> f(obj)
            // - store a copy of callable object obj in f
        // - f
            // - use f as a condition; true if f holds a callable oject, false otherwise
        // - f(args)
            // - call the object in f passing args to it
    // - Type defined as members of function<T>
        // - result_type
            // - the type returned by thsi function type's callable object
        // - argument_type
            // - types defined  when T has exactly one or two arguments.
        // - first_argument_type
        // - second_argument_type


struct absInt {
    // `operator()` takes a int, return a const
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

    // - a class to print string to specified ostream with specified separator
class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '): os(o), sep(c) {}
    void operator() (const string &s) const { os << s << sep; }
private:
    ostream &os;
    char sep;
};

    // ordinary function
int add(int i, int j) { return i + j; }
    // lambda, which generates a unnamed function-object class
auto mod = [](int i, int j) { return i % j; };
    // function-object class
        // - there is also a div in std, must use a different name
struct myDiv {
    int operator() (int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
    // function-object
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    cout << "ui is: " << ui << endl;

    // function-object with members
    string s("hello world.");
    PrintString printer;
    printer(s);
    PrintString errors(cerr, '\n');
    errors(s);

    // funtion<T>
    function<int(int, int)> f1 = add;
    myDiv d;
    function<int(int, int)> f2(d);
    function<int(int, int)> f3 = [] (int i, int j)  { return i * j; }; 
    cout << f1(4,2) << endl;
    cout << f2(4,2) << endl;
    cout << f3(4,2) << endl;
    return 0;
}