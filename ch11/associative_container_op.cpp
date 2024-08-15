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
using std::make_pair;


// Associative Container Type Aliases
    // - key_type, type of the key for this container type
    // - mapped_type, type associated with each key; applicable to map types only
        // - map unordered_map, multimap, unordered_multimap 
    // - value_type
        // - for set, same as key_type
        // - for map, pair<const key_type, mapped_type>
    // - when dereference an iterator, we get a reference to a value of the container's value_type

// Iterating across an Associate Container
    // - map and set types provide begin() an end() operations
        // - cbegin() and cend()
    // - when using an iterator to traverse an associative container , the iterators yield elements in ascending key order
        // - map/multi_map, set/multi_set

// Associative Container and Algorithms
    // - in general, we do not use generic algorithms with associative container
        // - keys are const so writing or reordering is not possible
    // - can be used with generic algorithms that read
        // - but such algorithms search the sequence which is a bad idea because
            // - but elments in associative container can be found quickly by key

// Adding Elements
    // - inserting an element that is already present has no effect due to the uniqueness of key
    // - c.insert(v), c.emplace(args)
        // - v is value_type object; args are used to construct an element
        // - for map and set, element is inserted/constructed only if the key is not present already in c
        // - return a pair<iterator, bool> where
            // - the interator denotes the elemtn with the key and 
            // - the bool indicates whether the element was inserted 
        // - for multimap and multiset, inserts/constructs the given element and 
            // - returns an iterator denoting the new element
    // - c.insert(b, e) and c.insert(il)
        // - b,e and iterators that denote c::value_type values; il is a braced list of such value
        // - return void
        // - insert only elments with key that is not present for map and set
        // - insert each elments for multimap and multiset
    // - c.insert(p,v) and c.emplace(p, args)
        // - similar to insert(v) and emplace(args) but use iterator p as a hint(?)
            // - for where to search for position where new element should be stored
            // - return an iterator to the element with the give key

// Removing Elements
    // - c.erase(k)
        // - removes every element with key k from c
        // - returns size_type indicating the number of elements removed 
    // - c.erase(p)
        // - removes element denoted by the iterator p from c.
        // - c must be an actual element
        // - e cannot equal to c.end()
        // - return an iterator denoting the element after p or c.end() if p denotes the last element in c
    // - c.erase(b,e)
        // - removes the elements from input range [b.e)
        // - return e
    // - c.erase(v)
        // - v is a key_value type
        // - removes all elements if any with key 
        // - returns a count of how many elements were removed

// Subscripting a map
    // - subscript operator and at function for map and unordered_map that are not const
        // - not for set, multimap, unorder_multimap
    // - c[k]
        // - returns the element with key k; if k is not in c, adds a new element with k, and value-initialized
            // - return a mapped_type, not a value_type
    // - c.at(k)
        // - check access to the element with key k; 
        // - return value with k if k is in c
        // - throw a run-time error out_of_range exception if k is not in c

// Accessing Elements
    // - c.find(k)
        // - returns an iterator to the first element with key k, or the off-the-end iterator if k is not in c
    // - c.count(k)
        // - returns the number of elements with key k. For c with unique keys, the result is always 1 or 0.
    // - c.lower_bound(k)
        // - returns an iterator to the first element with key not less than k. 
        // - not valid for unordered containers
    // - c.upper_bound(k)
        // - returns an iterator to the first element with key greater than k. 
        // - not valid for unordered containers
    // - c.equal_range(k)
        // - returns a pair of iterators denoting range ([b,e)]) of elements with key k. if k is not present, both itrators are c.end()


int main()
{
    // v1 is string
    set<string>::value_type v1;
    // v2 is string
    set<string>::key_type v2;
    // v3 is a pair of <const string, int>
    map<string, int>::value_type v3;
    // v4 is string
    map<string, int>::key_type v4;
    // v5 is int
    map<string, int>::mapped_type v5;

    vector<string> words = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
    map<string, size_t> word_count;
    for (auto &w : words)
        ++word_count[w];
    
    // map_it is an iterator
    auto map_it = word_count.begin();
    // *map_it is a reference to a pair<const string, size_t> object.
    cout << "map_it->first returns: " << map_it->first << '\n';
    cout << "map_it->second returns: " << " " << map_it->second << '\n';

    // error - key is const 
    // map_it->first = "new key";
    ++map_it->second;
    cout << "After ++ operation, map_it->second returns: " << " " << map_it->second << '\n';

    set<int> iset = {0,1,2,3,4};
    // set type defines both iterator and const_iterator types
        // - both give us read-only access to the elements in set
    set<int>::iterator set_it = iset.begin();
    set<int>::const_iterator set_cit = iset.begin();
    if (set_it != iset.end()){
        // error - cannot assign to const
        // *set_it = 42;
        cout << *set_it << '\n';
    }

    while (map_it != word_count.end()) {
        cout << map_it->first << " occurs " << map_it->second << " times" << '\n';
        ++map_it;
    }

    // Adding elements
        // - to set
    vector<int> ivec = {2,4,6,8,2,4,6,8};
    set<int> iset2;
    iset2.insert(ivec.cbegin(), ivec.cend());
    iset2.insert({1,3,5,7,1,3,5,7});
    cout << "\nAfter insert() iset2 is: ";
    for (auto i : iset2)
        cout << i << ',';

    word_count.insert({"pig", 1});
    word_count.insert(make_pair("pig", 1));
    word_count.insert(pair<string, size_t>("pig", 1));
    word_count.insert(map<string, size_t>::value_type("pig", 1));
    
    cout << "\nAfter insert() word_count is: ";
    for (auto i : word_count)
        cout << i.first << " : " << i.second << '\n';

    multimap<string, string> authors;
    auto ret = authors.insert({"Barth, John", "Sot-Weed Factor"});
    cout << "\ninsert(v) returns: ";
    cout << (*ret).second << '\n';

    ret = authors.insert({"Barth, John", "Lost in the Funhouse"});
    cout << "\ninsert(v) returns: ";
    cout << (*ret).second << '\n';

    // remove elements
    if (word_count.erase("pig"))
        cout << "ok: pig removed\n";
    else
        cout << "oops: pig not found\n"; 
    
    // Subscripting a map
        // - insert a value-initialized element with key Anna and assign 1 to its value.Four steps take place
            // - word_count is searched for element whose key is Anna which is not found 
            // - a new key-value pair<const string="Anna", int=0> is inserted into word_count
            // - the newly inserted element is fetched and is given the value 1
    word_count["Anna"] = 1;
        // - subscripting return 1, not make_pair{"Anna", 1}
    cout << word_count["Anna"] << '\n';
    ++word_count["Anna"];
    cout << word_count["Anna"] << '\n';

    auto ret_at = word_count.at("Anna");
    cout << "at(\"Anna\") returns: " << ret_at << '\n';

    // run-time error
    // ret_at = word_count.at("anna");

    // Using find() instead of Subscript for maps
        // - no changing to the map
    if (word_count.find("anna") == word_count.end())
        cout << "Anna is not in the map" << '\n';

    // Finding Elements in a multimap or multiset
        // - when a multimap/multiset has multiple elements of a given key, those elements will be adjacent within the container
            // - we are guaranteed that iterating across a multimap/multiset returns all element with a given key in sequence
    authors.insert({"Alain de Botton", "I know none of his works"});
    string search_item("Barth, John");
        // - number of elements 
    auto entries = authors.count(search_item);
        // - position of first entry
    auto iter = authors.find(search_item);
    cout << "\nFind element by count() and find(): \n";
    while (entries) {
        cout << iter->second << '\n';
        // - elements of a given key are adjacent
        ++iter;
        --entries;
    }
        // - using lower_bound() and upper_bound toget to get the range of all elements with key k
            // - if lower_bound() and upper_bound() return same iterator, then the element is not in c
    cout << "\nFind element by lower_bound() and upper_bound(): \n";
    for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg)
        cout << beg->second << '\n';

        // - using equal_range()
    cout << "\nFind element by equal_range(): \n";
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
        cout << pos.first->second << '\n';

    cout << endl;
    return 0;
}