// Use a range for to change all characters in a string to X
// define the loop control variable as type char
# include <iostream>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "Hello World";

    // for (char &c: s)
    // define c as char would copy character from s to c
    // changing c has no effect on s
    for (char c: s)
        c = 'X';

    cout << "s is " << s << endl;
    return 0;
}
