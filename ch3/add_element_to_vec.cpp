#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Define an empty vector and add elements is efficient;
    // better than defining a vector of a specific size;
    // Only exception is when all elements nned the save value.
    vector<int> v2;
    // vector size can change during traditional for loop
    // the body of range for loop must not change the size of the seq overwhich it is iterating
    for (int i=0; i!=100; ++i)
        // add argument to vector as last element;
        v2.push_back(i);
    
    cout << "v2 is: " << v2.size() << endl;
}