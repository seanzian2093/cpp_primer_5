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

#include <utility>
using std::pair;

// Associative Container Types
    // - elements ordered by key
        // - the key type must define a way to compare elements
            // - by default, < operator is used
            // - we can customize by defing a strict weak ordering over the key type, i.e.,
                // - two keys cannot both be less than each other, i.e., if k1 less than k2, then k2 must never be lt k1
                // - if k1 less than k2, and k2 is less than k3, then k1 must be less than k3
                // - if there are two keys, neither is less thant each other, then we say they are equivalent
                    // if k1 is equivalent to k2, and k2 is equivalent to k3, k1 must equivalent to k3 

        // - map, associative array of key-value pairs
        // - multimap, map in which a key can appear multile times
        // - set, key is the value
        // - multiset, set in which a key can appear multile times
    // - unordered collections
        // - unordered_map, map organized by a hash function
        // - unordered_multimap, hashed map; keys can appear multiple time
        // - unordered_set, set organized by a hash function
        // - unordered_multiset, hashed set; keys can appear multiple time

// Using set
    // - s.find(key) returns an iterator
        // - denoting key if it is found in s
        // - off-the-end iterator, i.e., s.end(), if key is not found

// pair type
    // - a pair holds two data members, of which types could be different
        // - public members
    // - elements in map are pairs
    // - use p.first and p.second to access first and second member of pair p
    // - pair operations

int main()
{
    // Using map to store counts of words
    vector<string> words = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
    // Using a set to store words with no duplicate
    set<string> exclude = {"the", "a", "The"};
    map<string, size_t> word_count;
    for (auto &w : words)
        // find(w) == end() means no matching
        if (exclude.find(w) == exclude.end())
            ++word_count[w];
    
    for (auto &w : word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << '\n';

    // Explicitly initialize a map
    map<string, string> authors = { {"Peppa", "Pig"},{"Emily", "Elephant"},{"Sussie", "Sheep"}};

        // - using a vector to initialize
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
            // - ivec has duplicates of numbers
        ivec.push_back(i);
        ivec.push_back(i);
    }

            // - iset will have unique elements from input range 
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << "ivec has a size of: " << ivec.size() << '\n';
    cout << "iset has a size of: " << iset.size() << '\n';
    cout << "miset has a size of: " << miset.size() << '\n';

    // Using a Comparison Function for the Key type
        // - we cannot define a multiset of Sales_data becuase Sales_data does not have a less than(<) operator
        // - we define a customized comparision function - less than
    bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
    {
        return lhs.isbn() < rhs.isbn();
    }
        // - when defining a multiset with our own operation, 
            // - we must provide the comparison type as 2nd argument
                // - comparison is a function pointer type
                    // - make sure use a * to indicate it is a function pointer type when using detltype()
            // - use bookstore(compareIsbn) to initialize bookstore from compareIsbn, i.e., 
                // - elements be ordered by compareIsbn when being added 
                // - or use bookstore(&compareIsbn) same effect because a function will be converted to a pointer if needed
    multiset<Sales_data, decltype(compareIsbn)* > bookstore(compareIsbn);

    // Using pair
    pair<string, string> author {"James", "Joyce"};
    cout << endl;
    return 0;
}