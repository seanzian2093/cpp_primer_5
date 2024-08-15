#include <iostream>

using namespace std;

void swap(int *ip, int *jp)
{
    int tmp;
    tmp = *ip;
    *ip = *jp;
    *jp = tmp;
}
int main()
{
    int i = 1, j = 3;
    swap(&i, &j);
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    return 0;
}