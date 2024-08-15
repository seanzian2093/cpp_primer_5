#include <iostream>
using std::cout;
using std::endl;
using std::begin;
using std::end;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <utility>
using std::pair;

#include <functional>
using std::less;

#include "Blob.hpp"
// #include "../GCC_4_7_0/1/Sales_item.h"
#include "../GCC_4_7_0/7/Sales_data.h"

// OOP vs Generic Programming
    // - OOP deals with types that are not known untill run time
    // - in generic programming types become known during compilation
        // - e.g., containers, iterators, and algorithms
        // - template is the foundation of generic programming

// Define a template - function template
    // - starts with keyword `template` followed by template parameter list
        // - a comma-separated list of one or more template parameters in <>
        // - template parameter list cannot be empty
        // - type parameter are determined at compiler time based on how compare is used
        // - type parameters can be used to 
            // - name return type 
            // - function parmeter type
            // - variable declaration inside function body
            // - cast inside function body
        // - each type parameter must be preceded by `typename` or `class`, interchangable
    // - when we call a function template, compiler uses the arguments of th call to deduce template arguments 
        // - e.g., when commpare is called, T will be determined
    // - compiler uses the deduced template parameter(s) to instantiate a specific version of the function
        // - e.g., compare(cojnst int&, const int&) 
    
    // - Nontype Template Parameters
        // - represent value, not a type
        // - use a specific type name, instead of `class` or `typename`
        // - may be
            // - integral type
                // - argument that is bound to a nontype integral parameter must be a const expr
            // - pointer or lvalue ref to an object or a function type
                // - argument must have static life time
                    // - NOT ordinary(non-static) local object or a dynamic object
                // - pointer parameter must be instantiated by `nullptr` or a zero-valued const expr
        // - a template nontype parameter is a constant value inside template definition, so
            // - can be used when const expr is required, e.g., to specify the size of an array
        // - template arguments used for nontype template parameters must be const expr
    
    // inline and constexpr Function Templates
        // - can be defined the same way as nontemplate functions
        // - `inline` or `constexpr` specifier follows the template parameter list and precedes the return type
            // - e.g., `template <typename T> inline T min(const T&, const T&);`

    // Writing Type-Independent Code
        // - function parameter in template are ref to const
            // - to ensure types that do not allow copy can be used with funtion template
            // - to avoid copying large object thus promote performance
        // - minize the number of requirements placed on argument types
            // - in `compare`, use only `<`, not `<` and `>`
    
    // Template Compilation
        // - compiler does not generate code when sees the definition of a template
            // - only when we instantiate a specific instance of the template 
        //- to generate an instantiation, compiler needs to have code that defines a function template or class template member function
            // - headers for templates typically include definitions + declarations
                // - definition of function template and definition of its member functions are put into header file, together with declarations
            // - unlike nontemplate function or class 
                // - when call a function, compiler needs to see only a declaration
                // - when use objects of class type, 
                    // - the class definition must be available, including member funtions' declaration
                    // - but definition of member functions need not to be present
                // - so put class definitions and function declarations in header files
                // - definition of ordinary and class-member functions in source files
    // Three stages of compilation error
        // - when compiler compiles the template itself, compiler might detect syntax error - missing secolon, misspelling a var name, etc
        // - when compiler sees a use of template, check number of arguments, etc
        // - during instantiation, type-related error can be found, or link time


// Class Template
    // - unlike function template, class templates differ in that compiler cannot deduce template parameter types for a class template
        // - we must provide additional information
    // - we can define member functions inside or outside a class template body
        // - a member function is iteself an ordinary function
        // - if inside, members are implicitly inline
        // - if outside, we must specify to which class the member belongs
            // - e.g., `template <typename T> ret-type Blob<T>::mem-name(param-list)`
        
    // - a member function of a class template is instantiated ONLY IF the program uses that member function.
    // - inside the scope of the class template, we can used the name of the template, without arguments
        // - when define members outside body of class template, we must remember we are not in the scope of class until the class name is seen
    
    // - when a class contains a friend declaration, the class and friend can independently be templates or not
        // - a class template that has a nontemplate friend, grants that friend access to all the instantiations of the template
        // - a class template that has a template friend, controls whether friendship inlcudes all instantiations or only specific instantiations
        // - in order to refer to a class template(class or function), we must declaration first(including parameter list)
            // - e.g.
template <typename T> class Pal;
class C {
    // Only Pal<C>, i.e., instantiated with class C is a friend to C
    friend class Pal<C>;
    // all instantiations of Pal2 are friends to C
    template <typename T> friend class Pal2;
};

template <typename T> class C2 {
    // Only Pal<T>, i.e., instantiated with same typename with C2, is friend to C2
    friend class Pal<T>;
    // all instantiations of Pal2 are friends to C2
        // - must use template parameters that differ from C2's
            // - X or T has no intrinsic meanings - all we need here is a different name
    template <typename X> friend class Pal2;
    // Pal3 is a friend to every instantiation of C2
        // - prior declaration for Pal3 not needed
    friend class Pal3;
};

        // - we can make a template type parameter a friend
template <typename Type> class Bar {
    friend Type;
};

    // Template Type Alias 
        // - we can define a type alias for a class template
template<typename T> using twin = pair<T, T>;
template<typename T> using partNo = pair<T, unsigned>;

    // `static` Members of Class Templates
        // - class template Foo has a `public static count()` and `private ctr`
        // - each instantiation of Foo has its own instance of `static` members
            // - i.e., for a given type X, there is one Foo<X>::ctr and one Foo<X>::count
                // - all objects of Foo<X> share the same ctr and count because they are `static`
template <typename T> class Foo {
public:
    static std::size_t count() { return ctr; }
private:
    static std::size_t ctr;
};

    // Template Parameters and Scope
        // - name of template parameter can be used after being declared until end of template declaration or definition
        // - a template parameter hids any declaration of that name in an outer space
        // - a name used as a template parameter may not be reused within the template
            // - e.g.,  `template <typename V, typename V>` is illegal
typedef double A;
template <typename A, typename B> void f(A a, B b)
{
    // tmp has same type as template parameter A, not doulbe, i.e., A defined outside is hidden
    A tmp = a;
    // error: redeclaration of template parameter B
    // double B;
};

    // Using Class Members That are Types
        // - by default, compiler assumes that a name accessed through the scope operator is not a type
        // - so if we want to use a type member of a template parameter list, we mut EXPLICITLY tell compilter that the name is a type 
            // - by using the keyword `typename`
            // - e.g., using T as return type, accessing member of T 
    
template <typename T> typename T::value_type top(const T& c)
{
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
};

    // Default Template Arguments
        // - we can supply default arguments for both function templates and class templates
            // - only if all the parameters to its right also have default arguments, like normal function with default arguments
            // - if a class template provides default arguments for all of its template parameters and we want to use those defaults
                // - we must not omit the <>, i.e., we must put <> following template name
            // - before c++11, only for class templates
            // - e.g. compare3

template <typename T, typename F = less<T>>
int compare3(const T &v1, const T &v2, F f = F())
{
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
};

template <class T = int> class Numbers {
public:
    Numbers(T v = 0): val(v) { }
private:
    T val;
};

// Member Templates
    // - a class, ordinary class or class template, may have a member function that is itself a template
        // - such members are referred to as member templates
        // - may not be virtual
        // - to instantiate a member template of a class template we must supply arguments for template parameters for
            // - both class and the member templates
        // - e.g., class DebugDelete
        // - e.g., Blob constructor that takes two iterators denoting input range
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr): os(s) { }
    template <typename T> void operator() (T *p) const 
    {
        os << "deleting unique_ptr"<<std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

// Controlling Instantiations
    // - use explicit instantiation to avoid multiple instantiation in multiple source files with same template arguments
    // - e.g., `extern template declaration; template declaration;` where declaration is a class or function declaration in which
        // - all template parameters are replaced by arguments
    // - when compiler sees an `extern` template declaration, it will not generate code for that instantiation in that source file
        // - such instantiation is a promise that there will be a non-extern use of that instantiation elsewhere in the program, i.e., some other file
        // - such instantiation must appear before any code that uses that instantiation
    // - there may be multiple `extern` declarations for a given instantiation but must be exactly one definition for that instantiation 
        // - compiler instantiates ALL its members when see the defintions, unlike ordinary class template which
            // - instantiates a member function when it is used
    
    // - e.g. app.cpp and temp_build.cpp
        // after compilation, the app.o file will contain instantiations for
            // - Blob<int>
                // - along with intializer_list and copy constructors for Blob<int> 
            // - Blob<string> and compare<int> will not be instantiated in app.o 
        // Instantiates all members of the class template
            // - after compilation, the temp_build.o will contain definitions for 
                // - compare<int> 
                // - Blob<string>

// Efficiency and Flexibility
    // obvious difference between `shared_ptr` and `unique_ptr`
        // - `shared_ptr` share ownership
        // - `unique_ptr` onws the pointer that it holds
    // - how they let users overfide their default deleter
        // - we can easily override the deleter of a `shared_ptr` by passing a callalbe object
            // - when create or reset the pointer
            // - deleter is stored as a pointer or as a class that encapsulates a pointer
                // - does not hold it as a direct member because the type of deleter is not known until run time
        // - the type of deleter is part of the type of a unique_ptr object
            // - user must supply that type as an explicit template argument when define a unique_ptr, more complicated

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
};

template <unsigned N, unsigned M>
int compare2(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
};



int main()
{
    // T is int
        // - instantiate a `compare(cojnst int&, const int&)`
    cout << compare(1, 0) << endl;

    // T is vector<int>
        // - instantiate a `compare(cojnst vector<int>&, const vector<int>&)`
    vector<int> vec1{1,2,3}, vec2{4,5,6};
    cout << compare(vec1, vec2) << endl;

    cout << compare2("hi", "world") << endl;

    // class template
        // - when instantiating ia and ia2, we must provide information of T, e.g., int
        // - a class of Blob<int> was generated
    Blob<int> ia;
    Blob<int> ia2 = {0,1,2,3,4};
        // - instantiates Blob<int> and the constructor with argument of initializer_list<int>
    Blob<int> squares = {0,1,2,3,4};
        // - instantiates Blob<int>::operator[](size_t), Blob<int>::size() const
    for (size_t i = 0; i != squares.size(); ++i)
        squares[i] = i * i;

        // - a class of Blob<string> was generated
    Blob<string> names;
    Blob<string> articles = {"a", "an", "the"};
        // - a class of Blob<double> was generated
    Blob<double> prices;

    // friends
        // - BlobPtr<char> and operator==<char> are friends of Blob<char>
    Blob<char> ca;
        // - BlobPtr<int> and operator==<int> are friends of Blob<int>
    Blob<int> ia3;

    // template type alias
        // - win_loss is a pair<int, int>
    twin<int> win_loss;
        // - area is a pair<double, double>
    twin<double> area;
        // - books is a pair<string, unsigned>
    partNo<string> books;

    // default template arguments
        // - use default less to compare
    bool i = compare3(0, 42);
    cout << i << endl;
    Sales_data item1("a", 10, 19.99), item2("b", 15, 29.88);
    bool j = compare3(item1, item2, compareIsbn);
    cout << j << endl;

    // use default type
    Numbers<> avg_precision;


    // member template
    double *p = new double;
    DebugDelete d;
    d(p);

    int* ip = new int;
        // a temporary DebugDelete object
    DebugDelete()(ip);

        // instantiation of member template
    int iarr[] = {0,1,2,3,4,5};
    vector<long> vi = {6,7,8,9};
    list<const char*> w = {"now", "is", "the", "time"};

        // Blob's constructor is instantiated as Blob(int*, int*)
    Blob<int> a1(begin(iarr), end(iarr));
        // Blob's constructor is instantiated as Blob(vector<long>::iterator, vector<long>::iterator)
    Blob<int> a2(vi.begin(), vi.end());

    return 0;
}