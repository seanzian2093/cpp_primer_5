#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // We can define var inside control structure
    // - if, switch, while, and for
    // - such var are visible only within that statement
    // - must be initialized

    // i is created and initialized at each iteration
    while (int i = get_num())
        cout << i << endl;
    
    // i is not accessible outside the while loop
    i = 0;

    vector<int> v = {1,2,3,-4,5,6,7};
    // define beg out of while statemtn
    auto beg = v.begin();
    while (beg !=v.end() && *beg >=0)
        ++beg;
    
    // beg is still accessible after while statement ends;
    if (beg == v.end())
        ;
}