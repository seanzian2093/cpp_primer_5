#include <iostream>
#include "ch6.h"
#include "fact.cpp"

using namespace std;

int main()
{
    // we must 
    // - provide one argument
    // - which can be converted to int
    // - compiler may warn
    int j = fact(5);
    cout << "5! is " << j << endl;

    j = fact(6.14);
    cout << "fact(6.14) is " << j << endl;

    return 0;
}