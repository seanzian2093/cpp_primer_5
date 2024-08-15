#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
int main()
{
    int i = 0, j;
    // prefix increment operator
    // - yield the incremented value
    j = ++i;
    cout << "j is: " << j << endl;
    cout << "i is: " << i << endl;
    // postfix increment operator
    // - yield the unincremented value
    j = i++;
    cout << "j is: " << j << endl;
    cout << "i is: " << i << endl;

    vector<int> v = {0,1,2,3,4,-5,7,-8};
    auto pbeg = v.begin();
    while (pbeg != v.end() && *pbeg >= 0)
        // fetch the value that pbeg points to and advance one position
        cout << *pbeg++ << endl;

    // vector<string> s = {"hello", "world", "good"};
    string s = "hello world, how are you doing?";
    auto beg = s.begin();
    while (beg != s.end() && !isspace(*beg))
        // left-hand may be evaluated first
        // Or right-hand
        // thus undefined - compiler dependent
        *beg = toupper(*beg++);

    cout << "s is now: " << s << endl;
    return 0;
}