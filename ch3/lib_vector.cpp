#include <iostream>
#include <string>
#include <vector>

using namespace std;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
// using std::vector;

int main()
{
    // A vector is a collection of objects of same type
    // vector is a template, not a type
    // References are not object so we cannot have a vector of references.
    // We can have a vector of vectors

    // Ways of initialization

    // default init - no elements
    // vector<string> svec;
    vector<int> ivec;
    // Copying ivec to ivec2
    vector<int> ivec2(ivec);
    // Copying ivec to ivec3
    vector<int> ivec3 = ivec;
    // error: sevc holds strings not ints
    // vector<string> svec(ivec2);

    // List init
    vector<string> articles = {"a", "an", "the"};
    vector<string> v1{"a", "an", "the"};
    // error: cannot supply a list of init using parentheses
    // vector<string> v1("a", "an", "the");

    // Creating a specified number of elements
    // 10 elements, each init to -1
    vector<int> ivec4(10, -1);
    // 10 elements, each init to 0
    vector<int> ivec5(10);
    // 10 elemnts, each is "abc"
    vector<string> svec2(10, "abc");
    // 10 elemnts, each is empty string
    vector<string> svec3(10);


    // List init or element count

    // when use (), we supply values to be used to construct the object
    // when use {}, if possible, we do so to list init the obj
    // 10 elment of 0
    vector<int> vv1(10);
    // 1 element of 10
    vector<int> vv2{10};
    // 10 elements of 1
    vector<int> vv3(10, 1);
    // 2 elements of 10 and 1
    vector<int> vv4{10, 1};

    // when use {}, if not possible, we do so to construct the object
    // list init - 1 elment of "hi"
    vector<string> vv5{"hi"};
    // error: cannot construct string from string literal
    // vector<string> vv6("hi");
    // construct - 10 elment of default-init elements
    vector<string> vv7{10};
    // construct - 10 elment of "hi"
    vector<string> vv8{10, "hi"};

}