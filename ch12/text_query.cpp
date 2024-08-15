#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ostream;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "text_query.hpp"

void runQueries(ifstream &infile)
{
    // Store the file and build query map
        // - infile is an ifstream that opens the file we want to query
    TextQuery tq(infile);
    // Interact with user: prompt for a word to find and print results
    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

// Default constructor - initialize file
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    // text to store a line of input file
    string text;
    // Read each file in file
    while(getline(is, text)) {
        // add to file
        file->push_back(text);
        // current line number
        int n = file->size() - 1;
        // separate line to words
        istringstream line(text);
        // word to store a word from a line
        string word;
        // read from stream line to word
        while (line >> word) {
            // wm is a map<string, shared_ptr<set<line_no>>>
            // if word is not in wm
                // - add word as a key
                // - return mapped_type, i.e., set of line_no of shared_ptr<set<line_no>>
                // - when we see first word, set is empty
            auto &lines = wm[word];
                // - for a new word
            if (!lines)
                // - allocate a new set
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // Use find, not subsctipting, to avoid adding words to wm
    auto loc = wm.find(sought);
    if (loc == wm.end())
        // not found
        return QueryResult(sought, nodata, file);
    else
        // found - return loc's second because loc is a value_type, i.e., (key,value) pair
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;

    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}

int main()
{
    ifstream input_file("dymanic_meo_smart_ptr.cpp");
    runQueries(input_file);
    return 0;
}