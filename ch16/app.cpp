#include "Blob.hpp"
#include <string>
using std::string;

// these template types must be instantiated elsewhere in the program, some other file, i.e., temp_build.cpp
extern template class Blob<string>;
extern template int compare(const int&, const int&);

// after compilation, the app.o file will contain instantiations for
    // - Blob<int>
        // - along with intializer_list and copy constructors for Blob<int> 
    // - Blob<string> and compare<int> will not be instantiated here
int main()
{
    Blob<string> sa1, sa2;
    Blob<int> a1 = {0,1,2,3,4};
    Blob<int> a2(a1);
    int i = compare(a1[0], a2[0]);
}