// Read a sequence of words from cin and store in a vector
// And then change each to uppercase
// Print transformed elements, eight words to a line
# include <iostream>
# include <vector>
# include <string>

using namespace std;

int main()
{
    int i = 0;
    string str;
    vector<string> istr;

    while (cin >> str)
        istr.push_back(str);

    for (auto &s: istr)
    {
        for (auto &c: s)
            c = toupper(c);
        cout << s;
        ++i;

        if (i >= 8)
        {
            cout << endl;
            i = 0;

        }
    }
    return 0;
}

