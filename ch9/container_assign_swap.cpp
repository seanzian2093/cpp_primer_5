#include<string>
using std::string;

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<deque>
using std::deque;

#include<forward_list>
using std::forward_list;

#include<array>
using std::array;

#include<iostream>
using std::cout;
using std::endl;

int main()
{
// Container Assignment Operations - on entire container
    // - c1 = c2, replace elements in c1 with copy of element in c2.
        // - c1 and c2 must be same type
            // - for array, same type mean both element type and size
        // - after assignment, c1 will have same size as c2, if they were of unequal size
            // - except for array, this is not allowed
    // array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
    array<int, 4> a1 = {1};
    array<int, 4> a2 = {2};
    array<int, 3> a3 = {3};
    array<int, 2> a4 = {4};

    list<string> l1(5, "a");
    list<string> l2(4, "b");

    a1 = a2;
    for (auto i: a1)
        cout << i << ',';
    cout << endl;

    l1 = l2;
    for (auto i: l1)
        cout << i << ",";
    cout << endl;

        
    // a1 = a3;// error - sizes do not match 
    // a1 = a4;// error - sizes do not match 

    // - c1 = {a, b,c}, replace content of a1 with a copy of elements in the braced list
        // - after assignment, c1 size is 3, the size of the braced list
        // - except for array, a1 size is unchange
            // - works only when braced list is of smaller size
    a1 = {1 ,2, 3};
    for (auto i: a1)
        cout << i << ',';
    cout << endl;

    // a1 = {1 ,2,3,4,5};// error - braced list is of bigger size

    l1 = {"c", "d", "e"};
    for (auto i: l1)
        cout << i << ",";
    cout << endl;

    l1 = {"c", "d", "e", "f", "g", "h"};
    for (auto i: l1)
        cout << i << ",";
    cout << endl;

    // - seq.assign(), valid for sequential containers only
        // - assign from a diffeent but compatible type 
        // - assign from a subsequence of a container
        // - replace all element of the calling/left-hand container with copy of elements of arguments
    list<string> names = {"Sean", "Lucia", "Emma"};
    vector<const char*> oldstype = {"sean", "lucia", "emma", "meowmeow", "chiuchiu"};
    // names = oldstype; // error - container types do not match  
        // - call to assign(b,e) replaces elements in names with copies of elments in the range denoted by iterators
            // - so the iterators must not refer to names because names is calling assign()
            // - the iterators determine how many elements names will have after the assignment
    names.assign(oldstype.cbegin(), oldstype.cend());// or - const char* can convert to string
    for (auto i: names)
        cout << i << ",";
    cout << endl;

        // - call to assgin(il) replace with a copy of elements of il
    names.assign({"sean", "lucia", "emma", "meowmeow", "chiuchiu"});
    for (auto i: names)
        cout << i << ",";
    cout << endl;
        // - call to assgin(n, t) replace with n copy of t 
    names.assign(2, "meow");
    for (auto i: names)
        cout << i << ",";
    cout << endl;

    // - swap(c1, c2) or c1.swap(c2) 
        // - exchange elements in c1 and c2
        // - c1 and c2 must have same type
        // - usually must faster than copying elements from c2 to c1
            // - except for array in which time proportional to size of array becase elements are swapped
        // - the element themselves are not swapped, internal data structures are swapped
            // - except for array in which elements are swapped
            // - interators, references, and pointers into containers are not invalidated,
                // - they refer to the same elements which, after swap(), are in different container
                    // - except array, they refer to different values but same element in container
                // - except string, a swap() may invalidate iterators, references, and pointers
    vector<string> svec1(2, "a");
    vector<string> svec2(4, "b");
    
    auto ptr = svec1.begin();// ptr points to svec1's first element
    cout << "Before swap(), svec1.begin() is " << *svec1.begin() << '\n';
    cout << "Before swap(), ptr is " << *ptr << '\n';

    swap(svec1, svec2);
    cout << "After swap(), svec1.begin() is " << *svec1.begin() << '\n';
    cout << "After swap(), ptr is " << *ptr << '\n';// after swap() ptr's underlying value is unchanged, but it is in svec2

    for (auto i: svec1)
        cout << i << ",";
    cout << endl;

    for (auto i: svec2)
        cout << i << ",";
    cout << endl;

    auto ptr2 = a1.begin();// ptr2 points to a1's first element
    cout << "a1.begin() is " << *a1.begin() << '\n';
    cout << "Before swap(), ptr2 is " << *ptr2 << '\n';
    swap(a1, a2);
    for (auto i: a1)
        cout << i << ',';
    cout << endl;
    cout << "a1.begin() is " << *a1.begin() << '\n';
    cout << "After swap(), ptr2 is " << *ptr2 << '\n';// after swap() ptr's underlying value is changed but still points to a1's first element






    return 0;
}