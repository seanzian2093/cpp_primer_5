#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // comma operator tekas two operands
    // - it evaluates from left to right
    // - in a guaranteed order

    // result of a comma expr
    // - is value of the right-hand expr
    // - left-hand expr is evaluated and its result is discarded 
    vector<int> ivec(5);
    vector<int>::size_type cnt = ivec.size();

    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;

    for (auto ix: ivec)
        cout << ix;
    cout << endl;

    return 0;
}