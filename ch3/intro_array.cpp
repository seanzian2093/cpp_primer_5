#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Arrays have fixed size - cannot add element to an array
    // By default, elements in an array are default initialized.
    // - default values are given
    // - default-initialized array of built-in type that is defined inside
    // - a function will have undefined values, like variables of built-in type
    // As with vector, arrays hold objects so there are no arrays of references.

    unsigned cnt = 42;
    constexpr unsigned sz = 42;

    // array of ten int
    int arr[10];
    // array of 42 pointers to int
    int *parr[sz];
    // error: cnt is not a constexpr
    string bad[cnt];
    // ok if get_size is constexpr, error otherwise
    // string strs[get_size()];

    // Explicitly init array elements
    const unsigned sz2 =3;
    int ia1[sz] = {0, 1, 2};
    // works - an array of dimension 3
    int a2[] = {0, 1, 2};
    // equivalent to a3[] = {1, 2, 3, 0, 0}
    int a3[5] = {1, 2, 3};
    // same as a4[] = {"hi", "bye", ""}
    string a4[3] = {"hi", "bye"};
    //error: too many initializers
    // int a5[2] = {0, 1, 2};

    // Character array are special
    // - when init from string literal which ends with a null character
    // - which is also copied into an array
    char ca1[] = {'C', '+', '+'};
    char ca2[] = {'C', '+', '+', '\0'};
    // null added automatically
    char ca3[] = "C++";
    // error - no space for null
    // const char cca4[6] = "Daniel";

    // No copy or assignment
    int a5[] = {0, 1, 2};
    // error - cannot init an array with another
    // int a6[] = a5;
    // error - cannot assign an array to another
    // - some compliers may allow
    // a6 = a5;

    // pointer or reference to an array
    // an array of 10 pointers that point to int
    int *ptrs[10];
    // error: array of references is not allowed
    // int &refs[10];
    // Read from inside to ouside, right to left
    // - Parray is a pointer to array of ten int
    // - init to &arr which is an array of 10 int
    int (*Parray)[10] = &arr;
    // arry is a ref to an array of 10 pointers to int
    int *(&arry)[10] = ptrs;
}