#include <iostream>
using std::ostream;

#include <string>
using std::string;
using std::cout;
using std::endl;

#include "../ch13/strvec.hpp"

/*
A variadic template is a template function or class that can take a varying number of parameter, aka parameter pack.
    // - two kinds of parameter pack: template parameter pack and function template pack
    // - use ellipsis to indicate that a paramter represents a pack
    // - e.g `template <typename T, typename... Args> void foo(const T &t, const Args& ... rest);`
        // - declares that foo is a variadic function that has 
            // - one type parameter, named T and
            // - a template parameter pack, named Args 
        // - foo's parameter list has
            // - a const & to T, named t
            // - a function parameter pack, named rest
        // - use `sizeof...` operator to get number of elements in a pack
            // - return a const expr
            // - does not evaluate its argument
*/
template <typename T, typename... Args> void foo(const T &t, const Args& ... rest) { ; }
template <typename... Args> void bar(const Args& ... args) 
{ 
    cout << sizeof...(Args) << endl; 
    cout << sizeof...(args) << endl; 
}

// Writing a Variadic Function Template
    // - we can use `initializer_list` to define a function that can take a varying number of arguments
        // - however, arguments must have same type or types that are convertible to a common type
    // - Variadic functions are used when we know neither number nor types of arguments
    // - Variadic functions are often recursive
        // - 1st call process first argument in the pac
            // - and call itself on second argument
        // - a non-variadic function to stop the recursion
    // - e.g. print error messages
        // - a non-variadic function to print an object to ostream
template <typename T> ostream &print(ostream &os, const T &t)
{
    return os << t;
};
        // - a variadic function that print 1st element and call itself for rest
            // - the non-variadic function must in scope otherwise print will recurse indefinitely
template <typename T, typename... Args> ostream &print(ostream &os, const T &t, const Args& ... rest) 
{
    os << t << ", "; 
    return print(os, rest...);
};

// - Pack Expansion
    // - when we expand a pack, we also provide a pattern to be applied on each expanded element 
    // - trigger an expasion by putting an ellipsis(...) to right of the pattern
    // - simple expansion, to a comma-separated list of parameter types, each of which have const &
        // - in `print(cout, i, s, 42);`, there ae two parameter in parameter pack that are expanded
            // - instantiated to `print(ostream&, const int&, const string&, const int&)`
            // - within the body, `print(os, rest...)` is instantiated to `print(os, s, 42);`
    // - complicated expansion
        // - `debug_rep(rest)...` is expanded to a comma-separated list of calls to debug_rep
        // - `errorMsg(cerr, fcnName, code.num(), otherData, "other", item);` will be executed as
            // - `print(cerr, debug_rep(fcnName), debug_rep(code.num), debug_rep(otherData), debug_rep("other"), debug_rep(item))
            // - if we wrote `debug_rep(rest...)`, it would be expanded to `debug_rep(fcnName, code.num, othrData, "other", item)`
                // - error because no match for print
template <typename... Args> ostream &errorMsg(ostream &os, const Args&... rest)
{
    return print(os, debug_rep(rest)...);
};

// Forwarding Parameter Pack
    // - we can use variadic templates together with `forward` to write functions that pass their arguments un changed to others
        // - e.g., we define a `emplace_back` to `StrVec` class, ch13 

int main()
{
    int i = 0; double d = 3.14; string s = "how now brown cow";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    // empty pack
    foo("hi");

    bar(i, s, 42, d);
    bar(s, 42, "hi");
    bar(d, s);
    bar("hi");
    
    // variadic function
    print(cout, i, s, 42);

    StrVec svec;
    // - add `cccccccccc` as a new last element
        // - arguments passed to `construct` are `std::forward<int>(int), std::forward<char>('c')
    svec.emplace_back(10, 'c');
    string s1 = "the", s2 = "end";
        // - arguments passed to `construct` are `std::forward<string>(string("the end"))`
    svec.emplace_back(s1 + s2);

    return 0;
}