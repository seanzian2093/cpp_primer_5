#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "Sales_item.h"

using namespace std;
int main()
{
    // two forms
    // - sizeof (type)
    // - sizeof expr

    Sales_data data, *p;
    // size required to hold an object of type Sales_data
    sizeof(Sales_data);
    // size of data's type;
    sizeof data;
    // size of data's revenue memeber;
    sizeof data.revenue;
    // size of revenue;
    sizeof Sales_data.revenue;
    // size of a pointer
    sizeof p;
    // size of the type which p points to
    // safe - does not matter if p is invalid pointer
    sizeof *p;
    // sizeof char or an expr of type char is guaranteed to be 1

    // sizeof an array is the sie of entire array
    // - size of element * number of elements
    // - sizeof does not convert the array to a pointer

    // sizeof a string or a vector returns only
    // - size of fixed part of these types;
    // - does not return the size used by the object's elements.

    // sizeof returns a const expr
    int ia[] = {0,1,2,3,4};
    constexpr size_t sz = sizeof(ia) / sizeof(*ia);
    int arr2[sz];

}