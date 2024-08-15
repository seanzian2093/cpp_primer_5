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
    string infile = "3.txt";
    ifstream ifstrm(infile);

    // output 
    vector<string> vec_str;

    // process
    string word;
    // while (getline(ifstrm, line))
    while (ifstrm >> word)
    {
        vec_str.push_back(word);
    }

    // check
    for (auto str: vec_str)
        cout << str << '\n';
    cout << endl;

    return 0;
}
