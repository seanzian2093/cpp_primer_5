#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::cout;
using std::endl;

// vector elements are stored contiguously in memory
    // - string too
    // - when there is no room for adding a new element, container must 
        // - allocate new memory for existing elements and new one
        // - move element from old memory location into new space
        // - add the new element
        // - deallocate the old memory
    // - above operations are expensive
    // - library implementation strategies
        // - when getting new memory, implementators typicall allocate capacity beyond what is immediately needed
            // - vector and string
        // - container hod this storage in reserver and uses it to allocation new elements when needed
        // - so vector grows usually more efficiently than a list or deque
    
    // - c.shrink_to_fit()
        // - valid for vector, string, and deque
        // - request to reduce capacity() to equal size()
        // - only request; no guarantee that memory is returned
            // - because implementation is free to ignore this request
    // - c.capacity()
        // - valid for vector and string
        // - return number of elements c can have before reallocation is necessary
        // - call to resize() does not change capacity, only size of container
    // - c.reserve(n) 
        // - valid for vector and string
        // - allocate memory space for AT LEAST n elements
        // - does not change number of elements in c
        // - change capacity only when requested space is greater than current capacity
            // - does nothing when less


int main()
{
    // uninitilized
    vector<int> ivec;
        // size is zero since 
    cout << "Uninitialized: "  << '\n';
    cout << "ivec: size: " << ivec.size() << '\n';
        // capacity not sure - defined by implementation
    cout << "ivec: capacity: " << ivec.capacity() << '\n';

    // give ivec 24 elements
    cout << "With 24 elements: "  << '\n';
    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
        ivec.push_back(ix);
        // size is 24
    cout << "ivec: size: " << ivec.size() << '\n';
        // capacity is defined by implementation, >= 24, which is 32
    cout << "ivec: capacity: " << ivec.capacity() << '\n';
    
    // reserve more memory
        // reserve 50 so capacity will be AT LEAST 50. 
        // Implementation determines
    cout << "Reserve for at least elements: "  << '\n';
    ivec.reserve(50);
    cout << "ivec: size: " << ivec.size() << '\n';
    cout << "ivec: capacity: " << ivec.capacity() << '\n';

    // Use up capacity
        // - up to now, no need to reallocation
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    cout << "Use all capacity: "  << '\n';
    cout << "ivec: size: " << ivec.size() << '\n';
    cout << "ivec: capacity: " << ivec.capacity() << '\n';

    // Add element further
    ivec.push_back(42);
        // - size is 51
    cout << "Add one more element: "  << '\n';
    cout << "ivec: size: " << ivec.size() << '\n';
        // - reallocation happened and capacity is set to 100
    cout << "ivec: capacity: " << ivec.capacity() << '\n';

    // Return memory
    ivec.shrink_to_fit();
    cout << "Return memory: "  << '\n';
    cout << "ivec: size: " << ivec.size() << '\n';
    cout << "ivec: capacity: " << ivec.capacity() << '\n';

    cout << endl;


    return 0;
}