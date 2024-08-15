// Read a sequence of string from cin and store in a vector
# include <iostream>
# include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> istr;

    while (cin >> str)
        istr.push_back(str);

    cout << "istr is of size -  " << istr.size() << endl;
}
