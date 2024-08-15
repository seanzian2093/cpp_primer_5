#include <iostream>
#include <string>
// C-style Character String Functions
// - not a type but a character arrys and null terminated
// - different from string type
// - strlen(), strcmp(), strcat(), strcpy()
// - pointers passed to these routines must point to null-terminated arrays
#include <cstring>
using namespace std;

int main()
{
    // ca is not null terminated
    char ca[] = {'C', '+', '+'};
    // Result is undefined
    // - Most like strlen() keeps looking through memory that follows ca
    // - untill it encounters a null character
    cout << strlen(ca) << endl;

    // Comparing strings
    // - string type
    string s1 = "A string example";
    string s2 = "A different string";
    if (s1 < s2)
        cout << "s1 < s2" << endl;
    else
        cout << "s1 > s2" << endl;
    
    // - c-style string
    // - Using such operators on similarly defined C-style strings compares the pointer values
    // - not the strings themselves
    const char ca1[] = "A string example";
    const char ca2[] = "A different string";
    // - ca1 < ca2 is undefine - compares two unrelated address
    // if (ca1 < ca2)
    //     cout << "ca1 < ca2" << endl;
    // else
    //     cout << "ca1 > ca2" << endl;

    // Use strcmp()  to compare C-style strings rather than pointers
    // - to achieve s1 < s2
    if (strcmp(ca1, ca2) < 0)
        cout << "ca1 < ca2" << endl;
    else
        cout << "ca1 > ca2" << endl;

    // Copying or concatenating C-style strings
    // - string arithmetic operation is illegal and meaningless on C-style strings
    // - because it is on pointers, not string
    string largeStr = s1 + " " + s2;
    cout << "largeStr is: " << largeStr << endl;
    // - use strcpy()/strcat()
    // - largeCa should be large enough otherwise disastrous
    char largeCa[100];
    strcpy(largeCa, ca1);
    strcat(largeCa, " ");
    strcat(largeCa, ca2);
    cout << "largeCa is: " << largeCa<< endl;

    // It is safer and more efficient to use string rather than C-style strings

    return 0;
}