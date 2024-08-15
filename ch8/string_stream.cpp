
#include <iostream>
using std::cin;
using std::getline;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

// `sstream` types inherit from `iostream` types
    // - `fstream` types inherit from `iostream` types too but has no interrelationship with `sstream` types
        // - `istringstream` 
        // - `ostringstream` is useful when we need to build up our output a little at a time and not print untill later
    // - with `sstream` speciifc operation
        // - sstream sstrm, create an unbound `stringstream` type 
        // - sstream sstrms(s), create an `sstream` type that holds a copy of s
        // - sstrm.str(), returns a copy of the string that sstrm holds
        // - sstrm.str(s), copies the string s into sstrm, return void 

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;

    // read a line at a time untill end of file or other error
    while(getline(cin, line)){
        PersonInfo info;
        // bind an istringstream object, record, to the line just read
        istringstream record(line);
        // read from record, and save into info.name
        record >> info.name;
        // read rest from record
        while (record >> word)
            info.phones.push_back(word);
        
        // add info to people
        people.push_back(info);

    }
    return 0;
}