// Use iterators to indirect access elements of a vector, like subscripts
// All of library containers have iterators but only a few support subscript operator
// - string is not a container type but supports many container operations.

// A valid iterator either denotes
// - an element or
// - a position one past the last element in a container
// - all other iterator values are invalid
# include <iostream>
# include <vector>
# include <string>

using namespace std;

int main()
{
    string str = "hello world";
    // Use members that return iterators
    // - begin() for first element
    // - end() for position past last element, off-the-end-iterator
    // - when the container is empty, begin returns the same as returned by end
    auto b = str.begin(), e = str.end();

    // Use * operator to access the denoted object
    cout << "b is " << *b << endl;
    cout << "e is " << *e << endl;

    string s("some string");
    if (s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << "s is " << s << endl;

    // Use increment operator, ++, to move one element to the next
    // all of the library containers have iterators that define == and != operator
    // - most of them do not have < operator
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);

    cout << "s is " << s << endl;

    // const iterator - may read but not write the element it denotes.
    vector<int>::iterator it;
    string::iterator it2;
    vector<int>::const_iterator it3;
    string::const_iterator it4;

    vector<int> v;
    const vector<int> cv;
    // it1 has type vector<int>::iterator
    auto it5 = v.begin();
    // it2 has type vector<int>::const_iterator
    auto it6 = cv.begin();

    // it3 and it4 has type vector<int>::const_iterator
    auto it7 = v.cbegin();
    auto it8 = v.cend();
    
    // Combining dereference and member access
    // - (*it).mem can be simplified as it->mem, i.e., arrow operator
    vector<string> text = {"some", "string", "hellow", "", "world"};
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
        cout << *it << endl;

    // Loops on iterators should not add elements to the container referred
}