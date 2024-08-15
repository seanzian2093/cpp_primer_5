#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int a[10];
    for (size_t ix = 0; ix < 10; ++ix)
        a[ix] = ix;

    for (auto i: a)
        cout << i <<", ";
    cout << endl;

    vector<int> v;
    for (size_t ix = 0; ix < 10; ++ix)
        // subscripting does not add element
        // v[ix] = ix;
        v.push_back(ix);

    for (auto i: v)
        cout << i <<", ";
    cout << endl;
}
