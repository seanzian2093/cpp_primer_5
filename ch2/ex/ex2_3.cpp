#include <iostream>
using std::cout;
using std::endl;

int main()
{
    unsigned u = 10, u2 =42;
    // 32
    cout << u2 - u << endl;
    // - strang number
    cout << u - u2 << endl;

    int i = 10, i2 = 42;
    // 32
    cout << i2 - i << endl;
    // -32
    cout << i - i2 << endl;

    cout << i - u << endl;
    cout << u - i << endl;
    return 0;
}
