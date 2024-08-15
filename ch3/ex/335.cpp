// Using pointers, set elements of an array to zero
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {0,1,2,3,4};

    auto b = begin(arr), e = end(arr);

    while (b < e)
    {
        *b = 0;
        cout << *b;
        ++b;
    }
    cout << endl;

    return 0;
}
