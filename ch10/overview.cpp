#include <iostream>
using std::cout;
using std::endl;
using std::begin;
using std::end;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
#include <numeric>
// using std::accumulate;
using std::copy;
using std::replace;
// using std::replace_copy;
// using std::back_inserter;

// Read-only Algorithms
    // - read but never write to the elements in their input range
    // - e.g., find, count, accumulate
    // - use const iterator if we don't need to change its content

    // - algorithms that take a single iterator denoting a second sequence assume that
        // - the second sequence is at least as large as the first
        // - e.g. equal()

// Algorithms that Write Container Elements
    // - algorithms do not check write operations
    // - we must ensure that the sequence into which the algorithm writes must be large enough
        // - >= elements to be written
    // - if no enough space, result is undefined
        // - or run-time error

// Algorithms that Reorder Containers
    // - sort(b,e)
    // - unique(b,e)

// Algorithm library operate on iterators
    // - therefore an algorithm can not directly add or remove elements.
    // - use container operations to remove elements.

int main()
{
    // accumulate uses 3rd argument as starting point for summation
        // - so elements in input range must be convertible to the type of 3rd argument
    vector<int> ivec = {0,1,2,3,4,5};
    // int sum = accumulate(ivec.begin(), ivec.end(), 0); 
    int sum = accumulate(ivec.cbegin(), ivec.cend(), 0); 
    cout << "sum is: " << sum << "\n";

    vector<double> dvec = {0.1, 1.1, 2.1, 3.1, 4.1, 5.1};
    double dsum = accumulate(dvec.cbegin(), dvec.cend(), 0); 
    cout << "dsum is: " << dsum << "\n";
    double dsum2 = accumulate(dvec.cbegin(), dvec.cend(), 0.0); 
    cout << "dsum2 is: " << dsum2 << "\n";

    vector<string> svec = {"a ", "bc ", "def "};
    // - 3rd argument must be a string type, not a string literal
        // - because there is no + operator on string literal, i.e., const *char
    // string str_sum = accumulate(svec.begin(), svec.end(), string("")); 
    string str_sum = accumulate(svec.cbegin(), svec.cend(), string("")); 
    cout << "str_sum is: " << str_sum << "\n";

    // element types of ivec and ivec need not to be same, as long as the == operator works 
    vector<int> ivec2 = {0,1,2,3,4,5,6};
    bool eq = equal(ivec.cbegin(), ivec.cend(), ivec2.cbegin());
    cout << "eq is: " << eq << "\n";

    // fill()
    vector<int> ivec3(5);
    fill(ivec3.begin(), ivec3.end(), 1);
    cout << "\nAfter first fill(), ivec3 is: ";
    for (auto i: ivec3)
        cout << i << ",";
    
    fill(ivec3.begin(), ivec3.begin() + ivec3.size()/2, 2);
    cout << "\nAfter second fill(), ivec3 is: ";
    for (auto i: ivec3)
        cout << i << ",";
    
    // fill_n()
        // - if 2nd argument > svec2.size() ther will be run-time error
    vector<string> svec2 = {"a ", "bc ", "def "};
    fill_n(svec2.begin(), 3, string("z"));
    cout << "\nAfter fill_n(), svec2 is: ";
    for (auto i: svec2)
        cout << i << ",";
    
    // Copy(b,e,dest) - copy input range, denoted by b and e, to dest
        // - dest is an iterator that denotes a poistion
        // return an iterator points to one past the last element copied
    int a1[] = {0,1,2,3,4,5};
    int a2[sizeof(a1)/sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), a2);
    cout << "\nAfter copy(), a2 is: ";
    for (auto i: a2)
        cout << i << ",";
    
    // replace(b,e,orig,new) - replace orig with new in the input range
    replace(begin(a1), end(a1), 0, 99);
    cout << "\nAfter replace(), a1 is: ";
    for (auto i: a1)
        cout << i << ",";
    // replace_copy(b,e,dest, orig,new) - replace orig with new in a copy of input range, then save to dest
    vector<int> a3;
    replace_copy(begin(a1), end(a1), back_inserter(a3), 0, 99);
    cout << "\nAfter replace_copy(), a3 is: ";
    for (auto i: a3)
        cout << i << ",";
    
    // sort(b,e) reorders the input range, return void
    vector<string> svec3 = {"def ", "bc ", "a "};
    sort(svec3.begin(), svec3.end());
    cout << "\nAfter sort(), svec3 is: ";
    for (auto i: svec3)
        cout << i << ",";

    // unique(b,e)
        // - remove adjacent duplicated entries
            // - must sort before unique
        // - return an iterator denoting one past last of unique values
            // - element beyond this point are undefined/unknown
    vector<string> svec4 = {"d", "b", "a", "d", "b", "a", "c", "e"};
    sort(svec4.begin(), svec4.end());
    auto res_unique = unique(svec4.begin(), svec4.end());
    cout << "\nAfter unique(), svec4 is: ";
    for (auto i: svec4)
        cout << i << ",";
    cout << "\nand res_unique points to: " << *res_unique;


    cout << endl;

    return 0;
}