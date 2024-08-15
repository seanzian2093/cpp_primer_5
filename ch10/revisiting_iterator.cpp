#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
#include <numeric>
// using std::accumulate;

// Inserter
    // - takes a container and yields an iterator that adds elements to the container
    // - operations
        // - it = t, insert the value t at the position denoted by it
        // - *it, ++it, it++ , do nothing but return it

// 3 kinds of inserters
    // - back_inserter, creates an interator that uses push_back
    // - front_inserter, creates an interator that uses push_front
        // - elements are always inserted infront of 1st elements in the target container
    // - inserter, creates an interator that uses insert, 
        // - takes 2nd argument which is an iterator to a given container
        // - elements are inserted ahead of the element denoed by such interator 

// iostream Iterators
    // - iterators that can be used with objects of IO types
    // - using a stream iterator, we can use the generic algorithms to read from and write to these objects
        // - istream_iterator is not guaranteed to read the stream immediately, i.e., lazy evaluation is permitted
    // - ostream_iterator can be defined on any type that supports output operator, i.e., <<
        // - an optional second argument of C-style string to print following each element, i.e., a separator char
        // - must bind an ostream_iterator to a specific stream,i.e., no empty or off-the-end ostream_iterator

// Reverse Iterators
    // - traverses a container backword, from last toward first element
    // - meaning of increment and decrement operators are inverted
        // - ++ moves the iterator to previous element, -- moves the iterator to next element
    // - c.rbegin(), c.rend(), c.crbegin(), c.crend() 
        // - forward_list does not support these
            // - becaue it does not support -- operator
        // - stream does not support these
            // - becaue it does not support -- operator
        // - rbegin and crbegin are actually the last element
        // - rend and crend are actually the one before first element
    // - reverse_iterator has a base() member which returns its corresponding ordinary iterator
        // - base() denote a adjacent position, i.e., one after reverse_iterator

int main()
{
    list<int> lst = {1,2,3,4};
    list<int> lst2, lst3;
    list<int> lst22, lst33;

    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    cout <<"After copy() with front_inserter(), lst2 is : ";
    for (auto i: lst2)
        cout << i << ",";
    cout << '\n';

    // - lst3 is empty, so lst3.begin() is one-past-end iterator
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    cout <<"After copy() with inserter(), lst3 is : ";
    for (auto i: lst3)
        cout << i << ",";
    cout << '\n';

    // - lst33 is empty, so lst33.end() is one-past-end iterator
    copy(lst.cbegin(), lst.cend(), inserter(lst33, lst33.end()));
    cout <<"After copy() with inserter(), lst33 is : ";
    for (auto i: lst33)
        cout << i << ",";
    cout << '\n';

    copy(lst.cbegin(), lst.cend(), back_inserter(lst22));
    cout <<"After copy() with back_inserter(), lst22 is : ";
    for (auto i: lst22)
        cout << i << ",";
    cout << '\n';

    // int_in istream_iterator based on cin
    istream_iterator<int> int_it(cin);
        // - an empty stream_iterator can be used as end iterator
    istream_iterator<int> int_eof;
    /// str_in is an istream_iterator based on in
        // - in is an ifstream on file afile
    ifstream in("afile");
    istream_iterator<string> str_it(in);

    vector<int> ivec;
    while (int_it != int_eof)
        // - *int_it++ works as follwoing
            // - int_it++ advanes the iterator to next position but return the older position, thus the postfix
            // - * dereference operator to get the underlying value
        ivec.push_back(*int_it++);
    cout <<"After input fron cin, ivec is: ";
    for (auto i: ivec)
        cout << i << ",";
    cout << '\n';

    vector<int> ivec2(int_it, int_eof);
    cout <<"After input fron cin, ivec2 is: ";
    for (auto i: ivec2)
        cout << i << ",";
    cout << '\n';

    // use stream iterator with algorithm
    cout << accumulate(int_it, int_eof, 0) << '\n';

    // use ostream_iterator
    ostream_iterator<int> out_iter(cout, " ");
    cout <<"By assigning element of lst2 to an ostream_iterator: ";
    for (auto e: lst2)
        *out_iter++ = e;
        // equivalent to (?) because * and ++ do nothing on an ostream_iterator
        // out_iter = e;
    
    cout << '\n';

    // copy to ostream_iterator
    cout <<"By copying element of lst2 to an ostream_iterator: ";
    copy(lst2.begin(), lst2.end(), out_iter);
    cout << '\n';

    // print elements in reverse order
    vector<int> vec = {0,1,2,3,4};
    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
        cout << *r_iter << ',';
    cout << '\n';

    // sort in reverse order
    sort(vec.rbegin(), vec.rend());
    cout <<"After sort with reverse iterator, vec is: ";
    copy(vec.begin(), vec.end(), out_iter);
    cout << '\n';

    // find with ordinary iterator
    string line = "1st, 2nd, 3rd, last";
        // - find returns an ordinary iterator denoting first encounter of ,
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << "First word is: " << string(line.cbegin(), comma) << '\n';
    // find with reverse iterator
    auto rcomma = find(line.crbegin(), line.crend(), ',');
        // string(line.crbegin(), rcomma) will retrive in reverse order, i.e. tsal, not last
    cout << "Last word is: " << string(line.crbegin(), rcomma) << '\n';
        // - use an ordinary iterator to retrieve the word but from comma to end, not begin to comma
            // - rcomma.base() denotes the one after comma, not the comma
    cout << "Last word is: " << string(rcomma.base(), line.cend()) << '\n';

    cout << endl;
    return 0;
}