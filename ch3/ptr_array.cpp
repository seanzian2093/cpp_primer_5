#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string nums[] = {"one", "two", "three"};
    // p is a pointer to nums[0]
    string *p = &nums[0];

    // when we use an array, thecompiler automatically substitutes a pointer to first element
    // - equivalent to string *p2 = &nums[0]
    string *p2 = nums;

    int ia[] = {0,1,2,3};
    // When array as initializer in a auto definition statemtn
    // - the deduced type is a pointer, e.g., not an int
    // - equivalent to auto ia2(&ia[0])
    auto ia2(ia);
    // error; ia2 is a pointer, we cannot assign int to a pointer
    // ia2 = 42;

    // This conversion does not happen in detltype()
    // - ia3 is an array of 3 int
    decltype(ia) ia3 = {0,1,2,3};
    // error - cannpt assign a pointer to an array
    // ia3 = p;
    ia3[3]=4;

    // Pointers are iterator
    int arr[] = {0,1,2,3,4};
    // p is a pointer to an array, i.e., to arr[0] 
    int *p3 = arr;
    // increment p and p then points to arr[1]
    ++p3;
    // we can obtain an off-the-end pointer by taking the address
    // - of nonexistent element one past the last element of an aray
    int *e = &arr[5];
    // arr only has 5 elements - arr[6] and beyond are undefined
    // - warned by compiler
    // int *e2 = &arr[6];

    // Using pointer to loop over elements in an array
    for (int *b = arr; b != e; ++b)
        cout << *b << endl;
    
    // A safer way to get pointer to 1st and one past last element
    int *beg = begin(ia);
    int *last = end(ia);
    cout << *beg << " - " << *last << endl;

    // Find first negative element
    int arr2[] = {0,1,2,3,4,-1,5,-6,7};
    int *pbeg = begin(arr2), *pend=end(arr2);
    while (pbeg != pend && *pbeg >=0)
        ++pbeg;

    cout << "First negative int is- " << *pbeg << endl;

    // substracting two pointers gives the distance between 
    // n is of ptrdiff_t, a machine-specific type 
    // - that is defined in cstddef header
    // - signed integral type
    auto n = end(arr) - begin(arr);
    cout << "arr has a size of " << n << endl;

    // Use relational operator to traverse elements in an array
    // relational operations on pointers to two unrelated objects is 
    // - meaningless and dangerous
    int *b = arr, *e2 = arr+5;
    while (b < e2)
    {
        cout << *b;
        ++b;
    }
    cout << endl;


    // Subsctiption and pointer
    int ia4[] = {0,2,4,6,8};
    // When use a name of an array, we use a pointer to it 1st element
    // - so ia4[2] mean advancing 2 positions from 1st element, i.e., 3rd
    int i4 = ia4[2];
    // Equivalent to below steps
    // - pointer to 1st elements
    int *p4 = ia4;
    // - advances 2 positions and fetches the element
    i4 = *(p4+2);
}