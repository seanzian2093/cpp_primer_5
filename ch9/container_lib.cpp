#include<string>
using std::string;

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<deque>
using std::deque;

#include<forward_list>
using std::forward_list;

#include<array>
using std::array;

// Each container is defined in a header file with the same name as the type
    // - deque in deque, list in list, etc


int main()
{
// Almost any type can be used as element type of a sequential container
    // - including container type, i.e., container of containers
    vector<vector<string>> lines;

// We can define a container for a type that does not support an operation-specific requirement
    // - but we can use that operation only if element type meets that operation's requirement
    // - e.g. assume 
        // - noDefault is a type without a default constructor
        // - init is initializer
    vector<noDefault> v1(10, init);
    // error - because noDefault has no default contructor, we must supply element initializer
    vector<noDefault> v2(10);

// Iterators have common interface
    // - i.e., if one iterator provides an operation, then such operation is supported in the same way 
        // - for each iterator that supplies that operation. i.e., support the same or support not
        // - one exception: `forward_list` does not support decrement operator, i.e., --
        // - iterator arithmetic operation apply only to string, vector, deque, and array
            // - i.e., +, -, +=, -=, >, >=, <, <=

// Iterator Range
    // - i.e., begin and end, or first and last, mark a range of elements from the container
    // - element range is left-inclusive interval, i.e., mathematically [begin, end)
    // - programming implication
        // - if begin == end, the range is empty
        // - if begin != end, there is at least one element in the range, begin refers to the first one
        // - we can increment begin untill begin == end

// Container Type Members
    // - iterator type
        // - e.g., iter is a iterator type defined by list<string>
    list<string>::iterator iter;
    // - difference_type
        // - e.e., count is a difference type defined by vector<int>
    vector<int>::difference_type count;

// - begin and end 
    // - yiled iterators that refer to the first and one past the last element in the container
        // - those do not begin with c, are over loaded, i.e., begin, rbegin, end, rend
            // - when call those members from a non-const object, we get the version that return iterator
            // - when call those members from a const object, we get only the version that return const_iterator
    list<string> a = {"Milton", "Shakespeare", "Austen"};
    auto it1 = a.begin();//list<string>::iterator
    auto it2 = a.rbegin();//list<string>::reverse_iterator
    auto it3 = a.cbegin();//list<string>::const_iterator
    auto it4 = a.crbegin();//list<string>::const_reverse_iterator

    // explicitly request const-ness or not
    list<string>::iterator it5 = a.begin();
        // - a.begin() returns a non-const but assigned to a const_iterator
    list<string>::const_iterator it6 = a.begin();
    // implicitly
        // - i7 is a const_iterator only if a is a const
    auto i7 = a.begin();
        // - explicitly request const_iterator
    auto i8 = a.cbegin();

// Defining and Initializing a Container
    // - Every container type defines a default constructor
    // - Such default constructor creates an empty container of the specified type
        // - expcept array in which case default constructor creates a non-empty container but one of the size,
            // - each element is default initialized
    // - such default constructors take arguments that specify the size of the container and initial values for elements.
        // - expcept array

    // - Initializing by copying
        // - two ways
            // - directly copy
                // - both container type and element type must be identical
            // - copy a range of elements denoted by a pair of iterators
                // - except array
                // - container type can be different 
                // - element type can be different as long as convertable from origin to destination
    // - Initializing by initializers list
        // - the initializer list implicitly specifies the size of container
            // - except for array
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char*> articels = {"a", "an", "the"};

    list<string> author2(authors); //ok - match
    deque<string> authList(authors); //error - container types don't match
    vector<string> words(articels); //error - element types do not match
    forward_list<string> words(articels.begin(), articels.end()); //ok - container type can differ; element type is convertable
    deque<string> authList(authors.begin(), it); // copy a subsequence, from begin to it, exclusive of it

    // - Sequential Container Size-related Constructors
        // - initialize from a size and an optional element initializer
            // - except array
            // - constructors that takes a size argument does not work for asscociative container
        // - if we do not supply an element initializer, the library creates a value-initialized one for us
            // - if the element is a built-in type or a class type that has a default constructor
            // - otherwise, we must provide an explicit element initializer along with the size
    vector<int> ivec(10, -1);// 10 int elments; each initialized to -1
    list<string> svec(10, "hi");// 10 strings; each is hi
    forward_list<int> ivec(10);// 10 int elments; each initialized to 0
    deque<string> svec(10);// 10 strings; each is an empty string

        // - array has fixed size
            // - size is part of array type, built-in array or library array(?)
                // - built-in array: those defined by int arr[10]
                // - library array: define in #include<arra>, std::array, array<int, 42>
    array<int, 42>;// an array that holds 42 int
    array<string, 10>; // an array that holds 10 string
    array<int , 10>::size_type i; // ok - to use array type, we must provide size and element
    array<int>::size_type j; // error - to use array type, we must provide size and element

            // - array default constructor creates a non-empty container but one of the size, each element is default initialized
            // - when list initializing the array, number of initializers must be no more than the size of the array
                // - if fewer, trailing elements are value-initialized
                // - element type must be built-in or class with default constructor 
                // - element type and initializer type must match
    array<int, 10> ia1;// 10 default-initialized ints
    array<int, 10> ia2 = {0,1,2,3,4,5,6,7,8,9};// list initialized
    array<int, 10> ia3 = {42};// list initialized, ia3[0] is 42, remaining elements are 0

            // - we can copy or assign objects of library array
                // - we cannot do so on built-in array

    int digs[10] = {0,1,2,3,4,5,6,7,8,9};// an built-in array of 10 int 
    int cpy[10] = digs;//error - cannot copy or assign for built-in array
    array<int, 10> digits = {0,1,2,3,4,5,6,7,8,9};// an library array of 10 int
    array<int, 10> copy = digits;//ok - we can copy or assign for library array
    copy = {1,2,3};

    return 0;
}