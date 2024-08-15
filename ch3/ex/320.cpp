// Read a set of int into a vector. 
// Print sum of each pair of adjacent elements.
# include <iostream>
# include <vector>
# include <string>

using namespace std;

int main()
{
    int i;
    vector<int> ivec;

    while (cin >> i)
        ivec.push_back(i);
    
    for (decltype(ivec.size()) ix = 0; ix < ivec.size() - 1; ++ix)
        // cout << ivec[ix] + ivec[ix + 1] <<endl;
        cout << ivec[ix] + ivec[ix + 1] << " ";
    cout << endl;
}

