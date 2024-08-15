#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::make_shared;
using std::allocator;
using std::allocator_traits;


// new and arrays
    // - allocate an array of objects and returns a pointer to the first one assuming allocation succeeds
        // - not an array type, so we cannot use begin, end, etc
    // - initialization using braced list
        // - if there are fewer initializers than elements, remaining elements are value initialized
        // - if there are more, the new expr fails and no memory is allocated
            // - throw an exception of bad_array_new_length, defined in new header, like bad_alloc
    // - value init using ()
        // - cannot supply element initializer inside the ()
        // - thus cannot use auto to allocate an array
    // - new int[n] works if n =0 even we cannot create an array variable of size 0

// Free Dynamic Arrays
    // - delete p
        // - p must point to a dynamically allocated object 
        // - or be null
        // - behavior is undefined is a [] is added 
            // - no compiler complaint
    // - delete [] pa
        // - pa must point to a dynamically allocated array 
        // - or be null
        // - elements in the array are destroyed in reverse order
        // - behavior is undefined is the [] is omitted
            // - no compiler complaint

// Smart Pointers and Dynamic Arrays
    // - cannot use -> operator
    // - can use subscriptor operator to access elements

    // - unique_ptr<T[]> u
        // - u can point to a dynamically allocated array of type T
    // - unique_ptr<T[]> u(p)
        // - u points to the dynamically allocated array to which built-in pointer p points
        // - p must be convertible to T*
    // - u[i]
        // - returns the object at position i in the array the u owns
        // - u must point to an array
        // - shared_ptr does not support this

    // - shared_ptr provide no direct support for managing a dynamic array
        // - if we want to use shared_ptr to manage a dynamic array, we must provide our own deleter
            // - if deleter is not provide, behavior is undefined
                // - similar to delete pa without [] where p is a dynamically allocated array
        // - shared_ptr does not support subscription
            // - or pointer arithmetic 

// allocator class
    // - new combinnes allocating memory with constructing objects in that memory
        // - similarly, delete combines destruction with deallocation

    // - allocator class separate allocation from construction
        // - defined in memory header
    // - allocator<T> a
        // - defines an allocator object named a that can allocate memory for objects of type T.
    // - a.allocate(n)
        // - allocates raw, unconstructed memory to hold n objects of type T.
        // - return ?
    // - a.deallocate(p, n)
        // - deallocates memory that held n objects of type T starting at address in the p of T* type.
        // - p must be a pointer previously returned by allocate()
        // - n must be the requested size when p was created.
        // - user must run destroy on any objects that were constructed in this memory before calling deallocate
            // - or what?
    // - a.construct(p, args)
        // - p must be a pointer to type T that points to raw memory;
        // - args are passed to a constructor for type T, which is used to construct an object in the above memory 
    // - a.destroy(p)
        // - run the destructor on the object pointed to by p of T* type

// allocator algorithms
    // - these functions construct elements in the destination, 
        // - rather than assigning to them
    // - uninitialized_copy(b, e, b2)
        // - copies elements from input range [b,e), into unconstructed,raw memory denoted by iterator b2
        // - be must be large enough to hold a copy of the elements in the input range
    // - uninitialized_copy(b, n, b2)
        // - copies n elements starting from b, into unconstructed,raw memory denoted by iterator b2
    // - uninitialized_fill(b, e, t)
        // - constructs objects in the range [b,e) as a copy of t
    // - uninitialized_fill(b, n, t)
        // - constructs n objects starting at b.
        // - b must denote unconstructed, raw memory large enough to hold the given number of objects.

int main()
{
    // - size inside the brackets must have integral type
        // - need not to be a constant
    int *pia = new int[3];
        // - use type alias
    typedef int arrT[42];
    int *p = new arrT;

    // - init
        // - by default, default initialized, i.e. undefined for built-in types
    int *pia1 = new int[3];
    cout << "pia1 points to " << *pia1 << '\n';
    string *psa1 = new string[3];
    cout << "psa1 points to " << *psa1 << '\n';
        // - value init by using ()
    int *pia2 = new int[3]();
    cout << "pia2 points to " << *pia2 << '\n';
    string *psa2 = new string[3]();
    cout << "psa2 points to " << *psa2 << '\n';
        // - init using init list
    int *pia3 = new int[3]{1,2,3};
    cout << "pia3 points to " << *pia3 << '\n';
    string *psa3 = new string[3]{"a", "an", "the"};
    cout << "psa3 points to " << *psa3 << '\n';

    // - smart pointer to dynamic array
        // - up points to an array of 3 uninitialized inits
    unique_ptr<int []> up(new int[3]);
        // - automatically uses delete [] to destroy its pointer
    for (size_t i = 0; i !=3; ++i)
        up[i] = i * 2;
    cout << "up[1] is " << up[1] << '\n';
    up.release();

        // - pass a lambda function as deleter to shared_ptr
    shared_ptr<int> sp(new int[3], [](int *p) {delete [] p;});
    for (size_t i = 0; i != 3; ++i)
        *(sp.get() + i) = i;
    cout << "sp.get() points to " << *(sp.get()) << '\n';
    cout << "sp.get()+1 points to " << *(sp.get()+1) << '\n';

    // allocate class
        // - alloc can allocate memory for string
    allocator<string> alloc;
        // - allocate memory for 3 unconstructed string
    auto const pa = alloc.allocate(3);
    cout << "ps points to " << *pa << '\n';

        // - q point to one past the last constructed element
            // - a.construct() is depreciated in c++17
    auto q = pa;
    cout << "q points to " << *(q - 1) << '\n';
    alloc.construct(q++);
    cout << "q points to " << *(q - 1) << '\n';
    alloc.construct(q++, 10, 'x');
    cout << "q points to " << *(q - 1) << '\n';
    alloc.construct(q++, "hi");
    cout << "q points to " << *(q - 1) << '\n';

    // - free the strings we allocated
        // - destroy() is depreciated
    while (q != pa)
        alloc.destroy(--q);

    cout << "q points to " << *q << '\n';

    cout << endl;
    return 0;
}