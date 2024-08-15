// Use a while loop to change all characters in a string to X
# include <iostream>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "Hello World";
    size_t n = 0;

    while (n <= s.size())
        {
            s[n] = 'X';
            ++n;
        }

    cout << "s is " << s << endl;
    return 0;
}
