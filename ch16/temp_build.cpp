#include "Blob.hpp"
#include <string>
using std::string;

// Instantiates all members of the class template
    // - after compilation, the temp_build.o will contain definitions for 
        // - compare<int> 
        // - Blob<string>
template class Blob<string>;
template int compare(const int&, const int&);