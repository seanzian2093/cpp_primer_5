# include <iostream>
// cctype is C++ versiion of C library header - ctype.h
// .h is removed and a prefix c is added to indicate it is part of C
# include <cctype>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // Process all char in a string
    string str("some string");
    // range for statement - 
    // - for (declaration: expression)
    // -    statement
    // when the expression is object is a sequence
    // declaration is a var that we will use to access the underlying element

    // here str is a string, a sequence of char
    // so c is a char of each element of str
    for (auto c : str)
        cout << c << endl;

    // Process only some char in a string

    if (!str.empty())
        // 0-based index
        cout << str[0] << endl;

    if (!str.empty())
        str[0] = toupper(str[0]);
    cout << str << endl;

    // Use subscription for iteration
    for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
        str[index] = toupper(str[index]);
    cout << str << endl;

    // Use string for random access

    const string hexdigits = "0123456789ABCDEF";
    cout <<"Enter a series of numbers between 0 and 15"
         <<" separated by spaces. Hit ENTER when finished: "
         << endl;
    string result;
    string::size_type n;
    while(cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];
    cout << "You hex number is: " << result << endl;

    return 0;
}