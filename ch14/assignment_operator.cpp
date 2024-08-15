#include <initializer_list>
#include <string>

#include "../ch13/strvec.hpp"

using namespace std;

// Assignment Operators
    // - copy-assignment, move-assignment - ch13
        // - assign one object of the class type to another object of the same type, 
        // - i.e., right -hand operand is of the same class type 
    // - additional assignment operators that
        // - allow other types as the right-hand operand
        // - e.g., braced list of elements
        // - return a ref to its left-hand operand to be consistent with built-in types
            // - with copy-assignment, move-assignment that we defined in ch13, section 5,6
        // - we prefer to define all assignments, including compound-assigments, in the class as members

StrVec &StrVec::operator=(initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
};

int main()
{
    return 0;
}