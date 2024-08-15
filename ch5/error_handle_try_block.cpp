#include <iostream>
#include <string>
#include <vector>
#include "Sales_item.h"

using namespace std;

int main()
{
    // throw expression
    // - raise an exception

    // try block
    // - deal with an exception
    // - start with a try 
    // - end with one or more catch clauses.

    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() != item2.isbn())
        throw runtime_error("Data must refer to the same ISBN.");

    // if we reach here, the ISBNs are the same
    cout << item1 + item2 << endl;

}