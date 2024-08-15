#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <stdexcept>
using std::runtime_error;

const string & transform(const string &s, const map<string, string> &m)
{
    // find a key from a map
    auto map_it = m.find(s);
    if (map_it != m.cend())
        // if found, return the value
        return map_it->second;
    else
        // if not found, return the key
        return s;
}

map<string, string> buildMap(ifstream &map_file)
{
    // trans_map holds transformation, i.e., key-value pairs 
    map<string, string> trans_map;
    string key, value;
    // read first word of map_file to key, and read remaining of the line to value
    while(map_file >> key && getline(map_file, value))
        // check the value is longer than a space
        if (value.size() > 1)
        // skip leading space
            trans_map[key] = value.substr(1);
        else
        // if value is only a spce or blank, throw runtime error
            throw runtime_error("no rule for " + key);
    
    // return the map
    return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    // get the dictionary in a map
    auto trans_map = buildMap(map_file);
    // text to hold each line from input
    string text;
    // read a line of input to text
    while (getline(input, text)) {
        istringstream stream(text);
        string word;

        bool firstword = true;
        // check if a word is first word
        while (stream >> word) {
            if (firstword)
                // if it is the first word, negate firstword after reading it for next iteration
                firstword = false;
            else
                // if not print out a space as a delimiter bwteen words
                cout << " ";
            // first word or not, tranform it
            cout << transform(word, trans_map);
        }
        cout << endl;
    }

}


int main()
{
    ifstream map_file("map_file");
    ifstream input_file("input_file");
    word_transform(map_file, input_file);

    return 0;
}