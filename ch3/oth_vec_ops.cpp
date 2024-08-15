#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto &i: v)
        i *=i;
    
    for (auto i: v)
        cout << i << " ";
    cout << endl; 

    // Subscripting does not add elements
    // ivec is a empty vector
    vector<int> ivec;
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        // Not adding element
        ivec[ix] = ix;
        // error - memory error: segmentation fault
    cout << "ivec is of " << ivec.size() << endl; 
    return 0;
}