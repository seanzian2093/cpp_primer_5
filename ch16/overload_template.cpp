#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::ostringstream;

#include <string>
using std::string;

/*
Function templates can be overloaed by other templates, or by ordinry,non-template functions. 
As usual, functions with same name must differ erither as to number or types of their parameter.
Function matching is affected by the presence of function templates in following ways
    // - candidate functions for a call include any function-template instantiation for which template argument deduction succeeds.
    // - candidate function templates are always viable, because template argument deduction will have eliminated any templates that are not viable
    // - viable functions, tempalte or not, are ranked by conversions.
    // - as usual, if exactly one function provides better match than any of other, that function is selected. If multiple equally good match
        // - if there is only ONE NON-TEMPLATE function in the set of equally good matches, this NON-TEMPLATE function is called
        // - if there is NO NON-TEMPLATE functions in the set, 
            // - but there are multiple function templates, 
            // - and ONE of these templates is more specialized than any of other, 
            // - the more specialized function template is called.
    // - otherwise, the call is ambiguous

*/


// Writing Overloaded Templates
    // - e.g. debug_rep
    // - general version, i.e., print any type we don't otherwise handle
template <typename T> string debug_rep(const T &t)
{
    ostringstream ret;
        // - print t to an ostringstream
    ret << t;
        // - return a copy of the string to which ret is bound
    return ret.str();
};
    // - pointer version
template <typename T> string debug_rep(T *p)
{
    ostringstream ret;
        // - print pointer p's own value to an ostringstream
    ret << "pointer: " << p;
        // - if p is not nullptr, print its underlying value
    if (p)
        ret << " " << debug_rep(*p);
        // - otherwise indicate that p is nullptr
    else
        ret << " null pointer";
        // - return a copy of the string to which ret is bound
    return ret.str();
};

    // - nontemplate and template overloads
        // - an ordinary nontemplate version 
string debug_rep(const string &s)
{
    return '"' + s +'"';
}
        // - two more ordinary nontemplate version that handler char pointer, i.e., C-stype char
            // - debug_rep(const string &s) must be in scope
                // - otherwise, debug_rep(T*) will instantiate a template version that takes const T&, silently
            // - best practice to declare every function in an overload set before define any of the functions
                // - so no need to worry whether compiler will instantiate a call before it sees the function to call
string debug_rep(char *p)
{
    return debug_rep(string(p));
}

string debug_rep(const char *p)
{
    return debug_rep(string(p));
}


int main()
{
    string s("hi");
    // - the nontemplate function will be selected
    cout << debug_rep(s) << endl;

    cout << debug_rep(&s) << endl;

    // sp is a pointer to const string
    const string *sp = &s;
    // - instantiaion of first version with T deduced to const string*
    // - instantiaion of second version with T deduced to const string
    // - normal function matching cannot distinguish between above two calls
        // - special rule of overloaded function templates: 1st version is more general 
            // - thus selected; without this special rule the call is ambiguous
    cout << debug_rep(sp) << endl;

    // ok - calls debug_rep(T*)
        // - first version, instantiated with T bound to char[10]
        // - debug_rep(T*) requires a permissible conversion from array to pointer, and considered as exact match
        // - nontemplate version requires a user-defined conversion, thus less good match
    cout << debug_rep("hi world!") << endl;
    return 0;
}