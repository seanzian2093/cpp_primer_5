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


// Sequential and asscociative containers differ in 
    // - how they organize elements
    // - which affects how elements are stored, accessed, added, and removed
    // - containers use different strageties for allocating elements and these strategies affect performace
        // - adding elements anywhere but at the end of vector or string, requires elments to be moved
        // - adding elements anywhere but at the begin or end of deque, requires elments to be moved
        // - adding elements to a vecotr or a string may cause the entire object to be reallocated
            // - rellocating an object requires allocating new memory and moving elements from old space to new

// Sequential Container Types
    // - vector
    // - deque
    // - list
    // - forward_list
    // - array
    // - string

// Best Practices
    // - use library containers rather than more primitive structures, 
        // - use library array, rather built-in array.
    // - use `vector` unless there is a good reason to prefer another container


// Using push_back()
    // - list, vector, deque, string support such operation
    // - the value of the newly added element is a copy of argument 

// Using push_front()
    // - list, forward_list, deque support such operation
    // - both vector and deque provide fast random access to its elements
        // - but vector does not support push_front()
        // - deque guarantees constant-time insert and delete of elements at begining and end of container
            // - inserting elements other than front or back of a deque is potentially expensive operation

// Using insert
    // - inset zero or more elements at any point in the container
        // - by copying arguments to the container
    // - vector, deque, list, and string
        // - forward_list provides special versions
    // - insert(iter, element)
        // - 1st argument is an iterator that can denote any position in the container, including one past last element, i.e. end()
            // - element is inserted before the position that iter denotes 
        // - in new standard, return an iterator to the first element that was inserted
    // - insert(p, n, t)
        // - inserting n elements of value t before position p
        // - in new standard, return an iterator to the first element that was inserted
            // - if no elements are inserted, return p
        // - in old standard, return void
    // - insert(p, b, e)
        // - inserting elements from a range given by begin-b, and end-e, before position p
            // - b and e must not from the calling container, i.e., the one that is being changed
        // - in new standard, return an iterator to the first element that was inserted
            // - if no elements are inserted, return p
        // - in old standard, return void
    // - insert(p, il)
        // - inserting a braced list or initializers list before position p
        // - in new standard, return an iterator to the first element that was inserted
            // - if no elements are inserted, return p
        // - in old standard, return void

// Using Emplace Operations
    // - construct rather than copy elements
        // - arguments to a constructor for element type are passed to emplace members
    // - 3 members, i.e., emplace_front, emplace, emplace_back
        // - correponding to push_front, insert, push_back

// Accessing Elements
    // - returns a reference
        // - if calling object is a const, return a ref to const

    // - c.back() return a reference to the last element in c;
        // - undefined if c is empty
        // - forward_list does not have back()
    // - c.front() return a reference to the first element in c;
        // - undefined if c is empty
    // - c[n] return a reference to the element indexed by the unsigned integral value n of c;
        // - undefined if n > c.size()
    // - c.at(n) return a reference to the element indexed by n of c;
        // - if n is out of range, throw an out_of_range exception, i.e., will not compile

// Subscripting and Safe Random Access
    // - container that provide fast random access also provide subscriptor operator
        // - string ,vector, deque, and array
        // - complier will not detect out of range index
            // - will compile but when run-time error occurs

// Erasing Elements
    // - operations that erase elements change size of container so are not supported by array
        // - size of part of array type, cannot be changed
    // - does not check argument(s), programmer must ensure that element(s) exist before removing them
    // - removing elements anywhere invalidates all interators, references, and pointers, (to elements that are removed?)
        // - except beginning or end of a deque
    // - Iterators, references, and pointers to elements after the erasure point in a vector or string are invalided
        // - conflit with the rule above?

    // - c.pop_back()
        // - remove last element in c;
        // - undefined if c is empty;
        // - return void
        // - not supported by forward_list
    // - c.pop_front()
        // - remove first element in c
        // - undefined if c is empty;
        // - return void
        // - not supported by vector and string
    // - c.erase(p)
        // - remove element denoted by iterator p
        // - return an iterator to the element after the one that was deleted
            // - or off-the-end iterator, i.e., end, if p denoted teh last element
        // - undefined if p is the off-the-end iterator, i.e., end 
    // - c.erase(b, e)
        // - remove range of elements denoted by iterator b and e
        // - return an iterator to the element after the last one that was deleted
            // - or off-the-end iterator, i.e., end, if e itself is the off-the-end iterator
            // - essentially, return e
        // - undefined if p is the off-the-end iterator, i.e., end 
    // - c.clear()
        // - remove all elements in c
        // - return void
        // - equivalent to c.erase(c.begin(), c.end())

// Specialized forward_list Operations
    // - forward_list is singly linked list
    // - when adding or removing en element, the element before the one that is added or removed has different successor
        // - we need access to such element, i.e., predecessor, to update its link
        // - access to predecessor is not easy
    // - for forward_list, operations to add or remove elements operate by changing the elements AFTER the given element
        // - so we alway have access to the elements that are affected by the change

    // - lst.before_begin() and lst.cbefore_ begin()
        // - return an iterator denoting the non-existent element just before the first of lst
        // - may be not dereference becasuse we dont know its underlying value
        // - cbefore_begin() return a const interator

    // - lst.insert_after(p,t)
    // - lst.insert_after(p,n,t)
    // - lst.insert_after(p,b,e)
    // - lst.insert_after(p,il)
        // - insert element(s) AFTER one denoted by iterator p.
        // - t is an object
        // - n is a count
        // - b and e are iterators denoting a range
            // - b and e must not ref to lst
        // - il is a braced list

    // - lst.emplace_after(p, args)
        // - use args to construct an element AFTER the one denoted by p
        // - return a iterator to the new element
            // - undefined if p is off-the-end iterator
    
    // - lst.erase_after(p)
    // - lst.erase_after(b,e)
        // - remove element AFTER the one denoted by p or
            // - undefined if p denotes the last element or is off-the-end iterator
        // - remove the range of elements (b, e), i.e., AFTER b, up to e but not including e
        // - return an iterator to the element after the one deleted 
            // - or off-the-end iterator if there is no such element

// Resizing a Container
    // - except array which has fixed size    
    // - if new size is greater, elements are added to back of the container, value initizlied
    // - if new size is smaller, trailing elements are deleted

    // - c.resize(n) 
    // - c.resize(n,t) 
        // - resize c to size n.
        // - any elements added have value t 

// Avoid storing the Iterator returned from end()
    // - Iterator returned by end is invalidated 
        // - when adding or removing elements from a vector and string
        // - when adding element or removing any but first element from a deque
    // - call end() always, instead of using a stored copy
    // - calling end() is fast
int main()
{
    list<int> ilist;
    for (size_t ix = 0; ix != 4; ++ix)
        ilist.push_front(ix);

    for (auto i : ilist)
        cout << i << ',';
    cout << endl;
    
    list<int> ilist2;
    for (size_t ix = 0; ix != 4; ++ix)
        ilist2.push_back(ix);

    for (auto i : ilist2)
        cout << i << ',';
    cout << endl;

    vector<string> svec;
    list<string> slist;
    // equivalent to slist.push_front("Hello! ")
    slist.insert(slist.begin(), "Hello! ");
    for (auto i : slist)
        cout << i << ',';
    cout << endl;

    // no push_front() on vector but we can insert before begin()
        // - inserting anywhere but at the end of a vector might be slow
    svec.insert(svec.begin(), "Hello ");
    for (auto i : svec)
        cout << i << ',';
    cout << endl;

    svec.insert(svec.end(), 2, "World!");
    for (auto i : svec)
        cout << i << ',';
    cout << endl;

    vector<string> v = {"quasi", "simba", "frollo", "scar"};
    auto res = slist.insert(slist.begin(), v.end() - 2, v.end());
    cout << *res << '\n';
    auto res2 = slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});
    cout << *res2 << '\n';
    auto res3 = slist.insert(slist.begin(), {});
    cout << *res3 << '\n';
    for (auto i : slist)
        cout << i << ',';
    cout << endl;

    // assume c is a container of Sales_data
        // - Sales_data has a constructor that takes a string as isbn, a int as count, and a double as price;
            // - a Sales_data object is directly created in the space managed by c
    // c.emplace_back("this is ISBN", 25, 15.99);
        // - equivalent to
            // - but a local temporary Sales_data object was created and pushed onto c 
    // c.push_back(Sales_data("this is ISBN", 25, 15.99));

    vector<string> svec2;
    // cout << svec2[0]; // error - run-time error
    // cout << svec2.at(0);// error - compiling error, out_of_range error

    // erase single element with list - odd values
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    auto it = lst.begin();
    while(it != lst.end())
        if (*it % 2)
            // remove current element and return an iterator to next
            it = lst.erase(it);
        else
            // manually change it to next
            ++it;
    
    for (auto i: lst)
        cout << i << ',';
    cout << endl;

    // erase single element with forward_list - odd values
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();// forward_list has a regular begin too
    while (curr != flst.end()) {
        if (*curr % 2)
            // if current element is oadd, remove it
                // return iterator to next, become curr for next iteration by assigning it to curr
            curr = flst.erase_after(prev);
            // else manualy move forward to next, both prev and curr
        else {
            prev = curr;
            ++curr;
        }
    }

    for (auto i: flst)
        cout << i << ',';
    cout << endl;

    // resize list
    list<int> ilist3(3, 42);// ilist is of 3 int of 42
    ilist3.resize(5);// now ilist is of 5 int, three 42 + two 0
    for (auto i: ilist3)
        cout << i << ',';
    cout << endl;

    ilist3.resize(7, -1);// now ilist is of 7 int, three 42 + two 0 + two -1
    for (auto i: ilist3)
        cout << i << ',';
    cout << endl;

    ilist3.resize(2, -2);// now ilist is of 2 int, two 42; -2 matters not here
    for (auto i: ilist3)
        cout << i << ',';
    cout << endl;


    return 0;
}