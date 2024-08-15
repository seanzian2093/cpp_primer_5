#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
int main()
{
    string s1 = "a string", *p = &s1;
    auto n = s1.size();
    cout << "n is: " << n << endl;
    // dereference has lower precendence than dot
    n = (*p).size();
    cout << "n is: " << n << endl;
    // ptr->mem is synonym for (*ptr).mem
    n = p->size();
    cout << "n is: " << n << endl;

}