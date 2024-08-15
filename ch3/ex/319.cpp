// List three ways to define a vector and give it ten elements each is 42
# include <iostream>
# include <vector>
# include <string>

using namespace std;

int main()
{
    // #1
    vector<int> ivec(10, 42);

    // #2
    vector<int> ivec2(10);
    for (auto &i: ivec)
        i = 42;

    // #3
    vector<int> ivec3{42, 42,42, 42,42, 42,42, 42,42, 42};

}
