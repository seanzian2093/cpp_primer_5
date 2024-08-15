
#include <iostream>
#include <initializer_list>

using namespace std;

// Two special properties that affect how we define and use functions that operate on arrays
// - we cannot copy an aary, 
    // - so we cannot pass by value
// - when we use an array, it is converted to a pointer, usually
    // - when we pass an array to a function, we are actually passing a pointer to its first element

// we can write parameter that looks like array
    // - below three function declarations are same

// print take a pointer to const int
void print(const int*) 
{
    ;
}
// shows that print takes an array of int 
void print2(const int[]) 
{
    ;
}
// more information about the array - dimension
void print3(const int[10]) 
{
    ;
}

// 3 techniques to manager array parameter - because they are passed as pointers
    // Explicitly pass size as a parameter

    // Using a marker to specify the extent of an array
    // - C-style string is a sequence of char in which last char is followed by a null char
    // - Functions stop process the array when see a null char
void print_string(const char *cp)
{
    // if cp is not a null pointer
    if (cp)
        // which cp points to a non-null char
        while (*cp)
            cout << *cp++;
    
    cout << endl;
}

    // Using Standard Library Conventions
    // - providing pointer to first element and pointer to one past the last element of the array
void print4(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

// Array ref parameter
// - a parameter that is a ref to an array
// - error : int &arr[10] would mean an array of ref, which is not allowed
    // - element of an array must be ojbect
void print_arr(int (&arr)[10])
{
    for (auto elem: arr)
        cout << elem << endl;
}

// Passing a multi-dimensional array
    // - mult-demesional array is essentially an array of arrys
    // - so we are essentially pass a pointer to an array, the first element of the multi-dim array

    // - 1st parameter shoud be intepret from right to left, but () frist most
    // - a pointer, that points to an array of 10 int
    // - int *matrix[10] would be: an array of 10 pointers to int
void print_matrix(int (*matrix)[10], int rowSize)
{
    ;
}

    // same to declaration
        // - when intepret multi-dim array, read dim from left to right
        // - 1st paratemer is an array of unknown number of elements, i.e., arrays
            // - each element is of 10 int
void print_matrix2(int matrix[][10], int rowSize)
{
    ;
}

// Main handles command line options by
    // - two optional parameter
    // - 1st is an int, i.e., number of options
    // - 2nd ,read from right to left, is an array of pointers that point to C-style char strings 
        // - essentially passing an array is passing a pointer to its first element
        // - 2nd parameter could be declared as a poniter to a pointer to a char 
            // - int main(int argc, char **argv) 
    // - 1st element of argv points to either the name of the program or the empty string
    // - Element just past the last pointer is guaranteed to be null char, ie. 0
        // - cautious with null char, cout it could yield `segmentation fault`


// Function with varying parameters
    // - if all the arguments have the same type, we can pass a library type `initializer_list`
        // - we could also use ellipsis, only when to interface with C functions
    // - otherwise, we write a variadic template, a special kind function, covered in ch16 

void print_vary_str(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    int i = 1, j[2] = {0, 1};  
    int k[10] = {0,1,2,3,4,5,6,7,8,9};
    print(&i);
    print2(j);
    print3(j);
    print4(begin(j), end(j));

    print_string("abcde");


    // we can only provide an array of ten int
    // error - &i is an address
    // print_arr(&i);
    // error- j is an array of 2 int
    // print_arr(j);
    print_arr(k);

    for (int i = 0; i < argc; i++)
        // cout << argv[i] << endl;
        cout << argv[i] << endl;

    // elements of initializer{} are copied to il, and become const 
    // copying or assign an initializer_list does not copy its element, but share them
    initializer_list<string> il {"1", "23", "456"}, il2(il), il3;
    // now il, il2, and il3 share elements
    il3 = il;

    print_vary_str(il);
    print_vary_str(il2);
    print_vary_str(il3);

    // il, il2 and il3 are storing the same address
    cout << "il starts at " << il.begin() << endl;
    cout << "il2 starts at " << il2.begin() << endl;
    cout << "il3 starts at " << il3.begin() << endl;
    return 0;
}