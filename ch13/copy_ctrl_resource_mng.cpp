#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include "valuelike.hpp"
#include "pointerlike.hpp"
// Class That Act Like Values
    // - valuelike.hpp
    // Assignment operators typicall combine the actions of desctructor and copy constructor
        // - in a sequence it 
            // - destroys the left-hand operands' resources, like destructor
            // - copies data from right-hand operand, like copy constructor 
        
        // - but we can define own copy-assignment operator to be in a different manner
            // - must work correctly if an object is assigned to itself
            // - share work with destructor and copy constructor

// Class That Act Like Pointers
    // - pointerlike.hpp
    // 

int main()
{
    HaPtrV hpv1("first hpv");
    print(cout, hpv1);
    HaPtrV hpv2;
    hpv2 = hpv1;
    print(cout, hpv2);

    HaPtrP hpp1("first hpp");
    print(cout, hpp1);
    HaPtrP hpp2;
    hpp2 = hpp1;
    print(cout, hpp2);

    return 0;
}
