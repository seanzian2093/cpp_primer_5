// Read a sequence of int from cin and store in a vector
# include <iostream>
# include <vector>

using namespace std;

int main()
{
    int i;
    vector<int> ivec;

    while (cin >> i)
        ivec.push_back(i);

    cout << "ivec is of size -  " << ivec.size() << endl;
}