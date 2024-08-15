# include <iostream>
// To use the string type, we must include the <string> header
# include <string>

// string is also defined in the std namespace
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // Ways to initialize a string

    // s1 is an empty string
    string s1;
    // s2 is a copy of s1
    string s2 = s1;
    // s3 is a copy of string literal
    string s3 = "hiya";
    string s3("hiya");
    // s4 is 10 copies of char 'c'
    string s4(10, 'c');
    // s5 is 10 copies of char 'c'
    string s5 = string(10, 'c');
}