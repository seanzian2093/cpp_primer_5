#include <iostream>

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

using std::getline;
using std::cout;
using std::endl;

int main()
{
    // input
    string infile = "requirements.txt";
    ifstream ifstrm(infile);

    // output 
    vector<string> vec_str;

    // process
    string line;
    while (getline(ifstrm, line))
    {
        vec_str.push_back(line);
    }

    // check
    for (auto str: vec_str)
        cout << str << '\n';
    cout << endl;

    return 0;
}