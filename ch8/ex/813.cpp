
#include <iostream>
using std::cout;
using std::getline;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    // input
    string infile = "contact.txt";
    ifstream ifstrm(infile);

    // output
    string line, word;
    vector<PersonInfo> people;

    while(getline(ifstrm, line)){
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        cout<< "Handling: " << info.name << "\n";

        while (record >> word){
            info.phones.push_back(word);
            cout<< "    Handling phone number: " << word << "\n";
        }
        
        people.push_back(info);

    }
    return 0;
}