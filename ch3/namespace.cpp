// header should not use using declaration.
// if so, every program that includes the header gets that same using declaration
// may cause unexpected conflicts.
# include <iostream>

using std::cin;
// A separate using declaration is required for each name
using std::cout; using std::endl;

int main()
{
    int i;
    cin >> i;
    //error: cout is not declared by using; must use full name
    // cout << i;
    std::cout << i;

    return 0;
}

