#include <iostream>
#include <cstdlib>
using namespace std;

// Failing to provide a return after a loop that contains a return is an error
    // - compiler may not detect such errors
bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
        // ok - return a bool
        return str1 == str2;
    
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    for (decltype(size) i = 0; i != size; ++i){
        if (str1[i] != str2[i])
            // return void; compiler should detect this error
            // return ;
            return false;
    }
    // error - control might flow to here and there is no return -i.e., return void implicitly
    // compiler may not detect this error.

}

// The return value is used to initialize a temporary var at the call site
    // - the temporary var is teh result of the function call.

    // make_plural returns a string
        // - so either word or word+ending is copied to a temp var which is returned as the result of calling make_plural
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

    // shorterString return a ref to const string
        // - so s1 or s2 are not copied when the function is called or result is returned
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

// Never return a pointer or ref to a local object

// Functions return class 
    // - call operator has same precedence as teh dot and arrow operator
    // - call operator is left associative
        // - if a funtion returns a pointer, ref or object of class type, 
        // - we can use the result of a call to call a member directly, i.e., without a temp var

// Reference returns are lvalues
    // - calls to functions that return ref are lvalues;
        // - we can assign a value to the result of such function, if it returns ref to a non-const
    // - others are rvalues

char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}


// Recursion
    // - a function, directly or indirectly call itself, is a recursive function
    // - there must be a path through such function that does not involve a recursive call; otherwise it recurse forever.
    // - main() may not call itself.
int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;
    
    return 1;
}


// Return a pointer to an array
    // - because we cannot copy an array
    // - a function cannot return an array
    // - a function CAN return a pointer/ref to an array
    // - 3 ways
        // - type alias
        // - trailing return type
        // - decltype


    // - use type alias 
        // arrT is a synonym for this type - an array of 10 int
typedef int arrT[10];
        // arrt2 is also a such synonym
using arrT2=int[10];

        // func is a function that returns a pointer to arrT
arrT* func(int i)
{
    ;
}
        // - equivalent to a declaration without alias
            // - intepret from righ to left, with () of high precedence
            // - func2(int i) is a function takes an int as parameter
            // - (*func2(int i)) is a pointer to result of such function
            // - (*func2(int i))[10] says dereferencing the pointer yileds an array of 10
            // - int (*func2(int i))[10] says further that such array's elements have int type. 
                // - similar declaration: int (*p2)[10] is a pointer to an array of 10 ints
int (*func2(int i))[10]
{
    ;
}

    // Using a Trailing return type - under new standard
        // - func3 takes an int argument and returns a pointer to an array of 10 ints
auto func3(int i) -> int(*)[10]
{
    ;
}
    // Using decltype
        // - if we know array to which our function can return a pointer

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
        // - decltype(odd) yield the type of odd,i.e., array of 5 int
        // - we must add * to arrPtr to convert to a pointer
decltype(odd) *arrPtr(int i)
{
    // return a pointer to an array
    return (i % 2) ? &odd : &even;
}



// main() without a return statement, returns 0 implicitly
int main()
{
    // 2 forms of return statements
    // - `return;`
        // - return void or
        // - return result of calling another function that returns void
    // - `return expr;`


    string str1 = "abce", str2 = "abcef";

    // bool res = str_subrange(str1, str2);
    // cout <<"res is " << res << endl;

    const string &s1 = str1, &s2 = str2;
    // shorterString returns a reft to str1
    // - so s1 and res2 should be at same address
    const string &res2 = shorterString(s1, s2);
    cout << "s1 is at " << &s1 << endl;
    cout << "s2 is at " << &s2 << endl;
    cout << "res2 is at " << &res2 << endl;

    // shortString return a ref to string; call a string member directly
    auto sz = shorterString(s1, s2).size();
    cout << "sz is " << sz << endl;

    string s("a value");
    cout << "Originally s is " << s << endl;
    // get_val returns a ref to char; we can assign to it
    get_val(s, 0) = 'A';
    cout << "After s is " << s << endl;

    // return 0;
    // value returned from main is treated as a status indicator
    // - we can use `cstdlib` to return machine independent 
    return EXIT_SUCCESS;
    // return EXIT_FAILURE;

}
