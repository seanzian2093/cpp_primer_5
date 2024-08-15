#include <iostream>

int main()
{
    // Character literal - in single quote
    char c = 'a';
    // string literal - in double quote
    std::string s = "Hello world!";

    // Multiline string literal
    std::cout << "a really, really long string literal "
                 "that spans two lines" << std::endl;

    // Escape sequence
    std::cout << '\n';
    std::cout << "\tHi!\n";

    // Generalized escape sequence - numerical value of character
    // \x followed by one or more hex digits or
    // \ followed by one, two, or three octal digits.
    std::cout << "Hi \x4dO\115!\n";
    std::cout << '\115' << '\n';
    // Only \123 is used to present a char; 4 for another
    std::cout << '\1234' << '\n';
    std::cout << '\123' << '\n';
    std::cout << '4' << '\n';
    // std::cout << '\x123' << '\n';
}
