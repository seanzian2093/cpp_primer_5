// Use a range for to change all characters in a string to X
# include <iostream>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "Hello World";

    for (auto &c: s)
        c = 'X';

    cout << "s is " << s << endl;
    return 0;
}