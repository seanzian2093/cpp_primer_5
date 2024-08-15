
#include <iostream>
#include <vector>
using namespace std;

// 6.54 
typedef int (*intFuncP)(int, int);
vector<intFuncP> intFuncPArr;

int intAdd(int i1, int i2)
{
    return i1 + i2;
}

int intSubtract(int i1, int i2)
{
    return i1 - i2;
}

int intMultiply(int i1, int i2)
{
    return i1 * i2;
}

int intDivide(int i1, int i2)
{
    return i1 / i2;
}


int main()
{
    intFuncPArr.push_back(&intAdd);
    intFuncPArr.push_back(&intSubtract);
    intFuncPArr.push_back(&intMultiply);
    intFuncPArr.push_back(&intDivide);

    for (auto el : intFuncPArr)
        cout << "el is " << *el << '\n';
    cout << endl;
    return 0;
}