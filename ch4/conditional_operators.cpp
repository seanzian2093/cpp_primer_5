#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
int main()
{
    // condition operator is a nested if-else logic
    // - cond ? expr1 : expr2
    int grade = 50;
    string finalgrade = (grade < 60) ? "fail" : "pass";
    cout << "finalgrade is " << finalgrade << endl;

    // Nesting conditional operator
    string finalgrade2 = (grade < 60) ? "high pass"
                                      :(grade < 60) ? "fail" : "pass";
    cout << "finalgrade is " << finalgrade << endl;


    return 0;
}