# include <iostream>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // Comparin strings
    // Rule #1
    // - if two strings have different lengths
    // - and every character in the shorter string is equal to the corresponding character of teh longer one
    // - then the shorter is less than the longer
    cout << "Rule #1: " << endl;
    string str = "Hello";
    string phrase = "Hello world";
    cout << "\"" << str << "\"" << " is less than "<< "\"" << phrase << "\" - " << (str < phrase) << endl;
    // RUle #2
    // - if any character at corresponding positions in two string differ
    // - then the first differing character determine comparing result
    // - e.g slang vs phrase, 1st differing character is i and e, i > e
    cout << "Rule #2: " << endl;
    string slang = "Hiya";
    cout << "\"" << slang << "\"" << " is great than "<< "\"" << phrase << "\" - " << (slang > phrase) << endl;
    cout << "\"" << slang << "\"" << " is great than "<< "\"" << str << "\" - " << (slang > str) << endl;
    cout << "\"i\"" << " is great than "<< "\"e\" - " << ('i' > 'e') << endl;


    // Adding two strings
    string s1 = "hello ", s2 = "world\n";
    string s3 = s1 + s2;
    cout << s1 << " + " << s2 << " = " << s3 << endl;
    s1 +=s2;
    cout << "Now s1 = " << s1  << endl;

    // Adding string literal adn string
    // At least one operand must be of string type
    string s3_2 = s1 + ", " + s2;
    cout << s1 << " + " << s2 << " = " << s3_2 << endl;
}