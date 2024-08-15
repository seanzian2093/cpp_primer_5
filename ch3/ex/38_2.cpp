// Use a traditional for loop to change all characters in a string to X
# include <iostream>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "Hello World";
    
    for (size_t n = 0; n <= s.size(); ++n)
        s[n] = 'X';

    cout << "s is " << s << endl;
    return 0;
}

