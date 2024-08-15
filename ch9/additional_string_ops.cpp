#include<string>
using std::string;

#include<iostream>
using std::cout;
using std::endl;

// Special Constructors
    // - n, len2, and pos2 are all unsigned values
    // - string s(cp, n)
        // - construct s by copying FIRST n chracters in the array to which cp points
            // - such array must have at least n characters
    // - string s(s2, pos2)
        // - construct s by copying characters from another string s2
        // - copying from index pos2
        // - undefined if pos2 > s2.size() 
    // - string s(s2, pos2, len2)
        // - construct s by copying len2 characters from another string s2
        // - copying from index pos2
        // - undefined if pos2 > s2.size() 
        // - copying at most s2.size() - pos2 characters even if len2 is greater

// The substr Operation
    // - returns a string that is a copy of part or all of the original string
    // - s.substr(pos, count)
        // - pos is optional starting position
        // - pos default at 0
        // - count defaults to a value that causes the library to copy all char in s starting from pos

// Special insert and erase
    // - aside from versions that take iterators
    // - special ones take an index which
        // - indicates the starting element to erase
        // - the position before which to insert the given values

int main()
{
    const char *cp = "Hello World!!!"; // 15 characters including null-terminator

    char noNull[] = {'H', 'i'};// built-in array of characters, without null-terminator

    // Init s1 by copying from string literal, cp
        // - copying up to the null-terminator but not including it
    string s1(cp);
    cout << "s1 is: '" << s1 << "' and size: " << s1.size() << "\n\n";

    // copy n characters from array of char
        //  - in this case, such array needs not to be null-terminated
    string s2(noNull, 2);
    cout << "s2 is: '" << s2 << "' and size: " << s2.size() << "\n\n";
        // - but if the count provided is greater than size of such array, result is undefined, i.e., gibberish
    string s2_2(noNull, 3);
    cout << "s2_2 is: '" << s2_2 << "' and size: " << s2_2.size() << "\n\n";
        // - or if the count is not provided, result is undefined, i.e, gibberish
    string s3(noNull);
    cout << "s3 is: '" << s3 << "' and size: " << s3.size() << "\n\n";

    // Copying from a string literal, starting from a pos
    string s4(cp+6, 5);
    cout << "s4 is: '" << s4 << "' and size: " << s4.size() << "\n\n";

    // Copying n characters from a string , starting from a pos
    string s5(s1, 6, 5);
    cout << "s5 is: '" << s5 << "' and size: " << s5.size() << "\n\n";

    // Copying from a string , starting from a pos
    string s6(s1, 6);
    cout << "s6 is: '" << s6 << "' and size: " << s6.size() << "\n\n";

    // Copying n characters from a string , starting from a pos, n >= remaining size
    string s7(s1, 6, 20);
    cout << "s7 is: '" << s7 << "' and size: " << s7.size() << "\n\n";

    // Copying from a string , starting from a illegal pos
        // - run-time error
    // string s8(s1, 16);
    // cout << "s8 is: '" << s8 << "' and size: " << s8.size() << "\n\n";

    // Substr operation
    string s("hello world");
        // from 0, copy 5
    cout << "s.substr(0, 5): " << s.substr(0,5) << "\n\n";
        // from 6, copy all remaining
    cout << "s.substr(6): " << s.substr(6) << "\n\n";
        // from 6, copy 11
    cout << "s.substr(6, 11): " << s.substr(6,11) << "\n\n";
        // from 6, copy 2
    cout << "s.substr(6, 2): " << s.substr(6,2) << "\n\n";
        // from 12, copy all remaining - out of range error
    // cout << "s.substr(12): " << s.substr(12) << "\n\n";

    // string is index from 0
    cout << "s.size() is " << s.size() << "\n\n";
    s.insert(s.size(), 5, '!');
    cout << "After insert(), s is '" << s << "' \n\n";

    s.erase(s.size() -5, 5);
    cout << "After erase(), s is '" << s << "' \n\n";
    // take C-style char argument
    const char *cp2 = "Stately, plump Buck";
        // copy 7 characters from cp2 and assign to s 
    s.assign(cp2, 7);
    cout << "s is now: '" << s << "' and size: " << s.size() << "\n\n";
        // copy characters starting from index 7 of cp2, and insert before index s.size() of s
    s.insert(s.size(), cp2 + 7);
    cout << "s is now: '" << s << "' and size: " << s.size() << "\n\n";

    // insert character from other string or substring thereof
    string ss = "some string", ss2 = "some other string";
    cout << "ss is now: '" << ss << "' and size: " << ss.size() << "\n\n";
        // insert a copy of ss2,before position 0 in ss
    ss.insert(0, ss2);
    cout << "ss is now: '" << ss << "' and size: " << ss.size() << "\n\n";

    ss = "|some string";
    // 4 parameter - the position to insert before, the string to copy from, starting position of copying, count of char to copy 
    ss.insert(0, ss2, 0, ss2.size());
    cout << "ss is now: '" << ss << "' and size: " << ss.size() << "\n\n";

    ss = "|some string";
    ss.insert(1, ss2, 0, ss2.size());
    cout << "ss is now: '" << ss << "' and size: " << ss.size() << "\n\n";

    ss = "|some string";
    ss.insert(1, ss2, 1, ss2.size()-1);
    cout << "ss is now: '" << ss << "' and size: " << ss.size() << "\n\n";

    return 0;
}