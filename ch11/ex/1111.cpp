#include <map>
using std::map;
using std::multimap;

#include <set>
using std::set;
using std::multiset;

#include <unordered_map>
#include <unordered_set>

#include <iostream>
using std::cout;
using std::endl;
using std::begin;
using std::end;

#include <string>
using std::string;

#include <vector>
using std::vector;

bool compareLength(const string &lhs, const string &rhs)
{
    return lhs.size() < rhs.size();
}

int main()
{

    multiset<string , bool (*)(const string &, const string &)> stringstore(compareLength);
    stringstore = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};

    for (auto &w : stringstore)
        cout << w << ',';

    cout << endl;
    return 0;
}