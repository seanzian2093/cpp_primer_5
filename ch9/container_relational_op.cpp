#include<vector>
using std::vector;

#include<iostream>
using std::cout;
using std::endl;

    // Relational Operators
        // - only if the element type support
        // - every container type supports equality operator(== and !=)
        // - all but unordered associative containers support relational operator(>, >=, <, <=)
        // - right-hand and left-hand must have same type
            // - container type and element type
        // - container comparison is similar to string relational 
            // - #1 euqal when both containers are same size and all elements are equal; otherwise unequal;
            // - #2 if containers have diffrent size
                // - if every element of smaller container == corresponding element of the larger one
                    // - then smaller container < the bigger container
                // - else comparison depends on comparing the first unequal elements 
int main()
{
    vector<int> v1 = { 1,3,5,7,9,12 };
    vector<int> v2 = { 1,3,9};
    vector<int> v3 = { 1,3,5,7};
    vector<int> v4 = { 1,3,5,7,9,12 };

    // v1 and v2 differ at [2], v1[2] < v2[2]
    cout << "v1 < v2: " << (v1 < v2) << '\n';
    // v3 is smaller and all elements equal to peers in v1
    cout << "v1 < v3: " << (v1 < v3) << '\n';
    cout << "v3 < v1: " << (v3 < v1) << '\n';
    cout << "v1 == v4: " << (v1 == v4) << '\n';
    cout << "v1 == v2: " << (v1 == v2) << '\n';

    return 0;
}