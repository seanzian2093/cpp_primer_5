#include <iostream>
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::ostream;

#include <algorithm>
using std::transform;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <functional>
using std::bind;
using std::ref;
using std::cref;

using namespace std::placeholders;

// Passing a Function to an Algorithm
    // - to order a vector by length, we use an overloaded sor
        // - takes a third argument that is a predicate

// A predicate is an expression that can be called 
    // - and that returns a value that can be used as a condition
    // - algorithm library use unary or binary predicates
        // - algorithms that take predicates call the given predicate on elements in the input range
            // - element type must be convertable to parameter type of predicate 

// Lambda 
    // - an object or expr is callable if we can apply the operator() to it
    // - lambda expression is a callable
        // - among function, function pointer, class that overload the function-call operator
    // - [capture list] (parameter list) -> return type { function body }
        // - parameter list and return type can be omitted
    // - a lambda may use a variable local to its surrounding function only if the var is in the capture list
        // - can use local static or var declared outside surrounding function directly

// lambda captures and returns
    // - when we define a lambda, the compiler generates a new/unnamed class type accordingly
        // - this class contains a data member corresponding to the variables in capture list
            // - the data members are initialized when a lambda object is created 
                // - not when called
    // - use auto to define a var initialized by a lambda, we are defining an object of type generated from lambda
    // - when capture by ref, we must ensure that underlying object exists when lambda is executed
        // - if a function returns a lambda, the lambda must not contain reference captures

// implicit capture
    // - use & to direct compiler to infer the capture list by ref
    // - use = to direct compiler to infer the capture list by value
    // - or mix, & or = must be the first in the capture list
        // - [&, c]
        // - [=, &f]

// Mutable lambda
    // - by default a lambda may not change the value of a var that it copies by value
    // - use `mutable` following parameter list to allow changes
        // - in such case, parameter list must not be omitted
    // - for capture by ref, we do not need mutable
        // - we need the ref refers to a non-const type

// Specifying Lambda Return type
    // - by default, if a lambda body contains any statements other a return, it is infered to return void
        // - if the body actually return other type, it will not compile


// Binding Arguments
    // - It is not easy to write function to replace a lambda that captures local variables
    // - e.g. find_if() takes a unary predicate as its third argument, so callable passed to it must take single argument.
        // - also need to use local varialbe size_t sz
    // - below function will not work with find_if because it takes two arguments
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
    // - use library function `bind`, defined in `functional` header
        // - it takes a callable and generates a new callable that adapts the parameter list of the original object
            // - parameters are copied
        // - general form auto newCallable = bind(callalble, arg_list);
            // - arg_list may contain names of the form _n, n is int, position of parameter in the newCallable
                // - starting at _1

    // - check6 is is new callalbe like check_size(const string &s, sz=6);
        // - _1 is 1st in arg_list, so it corresponds to &s
        // - 6 is 2nd in arg_list, so it corresponds to sz
auto check6 = bind(check_size, _1, 6);
    // - more generally assume f is a callable that takes (a,b,c,d,e)
        // - then g takes(e,c), effective f(a,b,c,d,e)
// auto g = bind(f, a, b, _2, d, _1); 
    // - use bind to reorder parameter
        // - e.g. auto isLonger = bind(isShorter, _2, _1);
    // - use ref(obj) to pass a object to bind without copying it
        // - by creating a ref
        // - use cref to create a ref to const
        // - e.g., assume a is a ref or we do not want to copy a,  auto h = bing(y, ref(a));

void fcn1()
{
    size_t v1 = 42;
    // v1 is copied
    auto f = [v1] { return v1;};
    v1 = 0;
    // so j is 42
    auto j = f();
    cout << "In fcn1() j is " << j << endl;
}

void fcn2()
{
    size_t v1 = 42;
    // v1 is not copied - passing by ref
    auto f = [&v1] { return v1;};
    v1 = 0;
    // so j is 0
    auto j = f();
    cout << "In fcn2() j is " << j << endl;
}

void fcn3()
{
    size_t v1 = 42;
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();
    cout << "In fcn3() j is " << j << endl;
}

void fcn4()
{
    size_t v1 = 42;
    auto f = [&v1] () { return ++v1; };
    v1 = 0;
    auto j = f();
    cout << "In fcn4() j is " << j << endl;
}
void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    // c explicitly capture by value, other implicitly by ref
    for_each(words.begin(), words.end(), [&, c](const string &s) { os << s << c;});
    os << '\n';
    // os explicitly capture by ref, other implicitly by value 
    for_each(words.begin(), words.end(), [=, &os](const string &s) { os << s << c;});
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

auto isLonger = bind(isShorter, _2, _1);

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    // - unique() returns an iterator denoting one past last of unique values
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());

}


int main()
{
    // sort by length
    vector<string> words = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
    sort(words.begin(), words.end(), isShorter);
    for (auto &s: words)
        cout << s << ' ';
    cout<< endl;

    // sort by length and keep alphabetical order among elements of same length
        // - stable_sort()
    // vector<string> words = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
    vector<string> words2 = words;
    elimDups(words2);
    stable_sort(words.begin(), words.end(), isShorter);
    for (auto &s: words2)
        cout << s << ' ';
    cout<< endl;

    // sort by length using lambda
    vector<string> words3 = words;
    sort(words3.begin(), words3.end(), 
         [](const string &a, const string &b) { return a.size() < b.size(); });
    for (auto &s: words3)
        cout << s << ' ';
    cout<< endl;

    // Find first elements whose size is greater than a parameter
        // - find_if() returns an iterator denoting the 1st element a that a.size() >= sz 
            // - a copy of end() if no such element exists.
    size_t sz=5;
    auto wc = find_if(words3.begin(), words3.end(), [sz](const string &a) { return a.size() >= sz; });
    auto count = words3.end() - wc;
    cout << count << " " << " words of length " << sz << " or longer " << "\n";

    // The for_each algorithm to process each element of input range
        // - count is declared outside of this main(), so can be used by lambda directly
    for_each(wc, words3.end(),
             [](const string &s) { cout << s << " ";});

    cout<< '\n';

    // implicity capture
    auto wc2 = find_if(words3.begin(), words3.end(), [=](const string &a) { return a.size() >= sz; });
    cout << "wc2 refers to " << *wc2 << '\n';
    for_each(wc, words3.end(),
             [=](const string &s) { cout << s << " ";});

    cout << '\n';

    fcn1();
    fcn2();
    biggies(words3, 5);
    cout << '\n';

    fcn3();
    fcn4();

    cout << endl;

    // Specify return type
    vector<int> vi = {0,1,2,3,4,5, -6,7,8,-9};
        // - transform(b,e, dest, trans) - tranform element in input range and writes new value from position of dest
    transform(vi.begin(), vi.end(),vi.begin(), [] (int i) { return i < 0 ? -i : i; });
    for (auto i: vi)
        cout << i << ',';
    cout<< endl;

        // - below will not compile
            // - compiler infers that return type is void but actually is int(?)
    transform(vi.begin(), vi.end(),vi.begin(), [] (int i) { if (i < 0) return -i; else return i; });
    for (auto i: vi)
        cout << i << ',';
    cout<< endl;

            // - use trailing return type
    transform(vi.begin(), vi.end(),vi.begin(), [] (int i) ->int { if (i < 0) return -i; else return i; });

    for (auto i: vi)
        cout << i << ',';
    cout<< endl;

    return 0;
}