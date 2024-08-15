#include <map>
using std::map;
using std::unordered_map;

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


// Unordered Associative Containers
    // - use a hash function and key type's == operator to organize elements
    // - use an unordered container if the key type is inherently unordered or has hashing outperforms
    // - output of a program that uses an unordered container will ordinarily differ from that using ordered container

// Managing Buckets
    // - unordered containers are organized as a collection of buckets, each of which has 0 or more elements
    // - use hash function to map elements to buckets
        // - to access an element, container compute its hash code which tells which bucket to search
        // - all elements with a given hash value are put into the same bucket.
        // - performance depends on 
            // - quality of its hash function 
            // - number of buckets
            // - size of buckets
                // - when a bucket holds several elements, those elements are search sequentially
    // - bucket interface
        // - c.bucket_count(), number of buckets in use
        // - c.max_bucket_count, largest number of buckets c can hold
        // - c.bucket_size(n), number of elements in the nth bucket 
        // - c.bucket(k) bucket in which elements with key k would be found(?)
            // - returns whif not?
    // - bucket iteration
        // - local_iterator, const_local_iterator, 
            // - iterator types that can access elements in a bucket
        // - c.begin(n), c.end(n),c.cbegin(n), c.cend(n)
            // - const_iterators/iterators to first/last element in bucket n
    // - hash policy
        // - c.load_factor(), return average number of elements per buckets, float.
        // - c.max_load_factor(), return average bucket size that c tries to maitain, float
            // - to keep load_factor <= max_load_factor
        // - c.rehash(n)
            // - reorganize storage so that
                // - bucket_count >= n and 
                // - bucket_count >= size/max_load_factor
                    // - size?
        // - c.reserve(n)
            // - reorganize so that c can hold n elements without a rehash

// Requirements on Key Type
    // - we can directly define unorder containers whose key is one of 
        // - the built-in types, including pointer types
        // - string
        // - smart pointer, ch12
    // - to define unordered container that uses our own class types for its key type
        // - we must supply our own version of hash template, ch16

int main()
{
    vector<string> words = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
    unordered_map<string, size_t> word_count;

    for (auto &w : words)
        ++word_count[w];

    cout << "Output using an unordered_map is not in alphabetical order: \n";
    for (auto &w : word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << '\n';
    
    cout << endl;

    return 0;
}