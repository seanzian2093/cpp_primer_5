#include <string>
using namespace std;

// Name lookup - general principle
    // - #1 look for declaration of the name in the blcok in wich name was used;
        // - ony names declared before use are considered
    // - #2 if not found, look in the enclosing scope(s), i.e., outer space
    // - #3 if no declaration is found, the program is in error.


// Class definition are process in two phases
    // - the way names are resolved inside member functions defined inside the class seems differring from above rule
    // - NOT True, because
    // - #1 member declarations are compiled
        // - names that are used in return type and parameter list must be seen before
    // - #2 function bodies are compiled only after entire class has been seen.
        // - if function definition and member declaration are processed at same time, order matters.

typedef double Money;
string bal;

class Account{
public:
    // Compiler seeks a declaration of Money in Account class
        // - no matching inside Account
            // - proceed to outside and found a declaration in line 17
                // - this declaraion will be used in return type of balance(), and data member bal;
    // Function body of balance() is processed only after entire class is seen
        // - so balance() returns the data member bal, not the string bal defined outside
    Money balance() { return bal; }
private:
    // Type Names are Special
        // - ordinarily, an inner scope can redefine a name from outer scope, even which has been used in inner scope
            // - but not apply to a name that is type
            // - error- balance() already used Money type, cannot redefine Money. 
                // - even definition is same
                // - compiler may not diagnose such error
                // - best practice to define type names at beginning of a class
    typedef double Money; 
    Money bal;
};

// Normal Block-scope Name lookup inside Member functions
    // - a name used in the body of a member function is resolved as follows
        // - #1 look for a declaration inside the member funtion - only preceding ones are considered
        // - #2 if not found, look for a declaration inside the class - all members considered
        // - #3 if not found, look for a declaration that is in scope before the member function definition
            // - e.g., outer scope, global var

int height;
class Screen{
public:
    typedef string::size_type pos;
    // bad practice: parameter name = member name
    void dummy_fcn(pos height) {
        // - this is actually the parameter height
            // - not the member height, which is hidden
        cursor = width * height;
        // - access hidden member height explicitly
        cursor2 = width * this->height;
        cursor3 = width * Screen::height;
        // - access the height defined in outer scope, - global one
        cursor3 = width * ::height;
    }
    void setHeight(pos);
private:
    pos cursor = 0, cursor2 = 0, cursor3 = 0, cursor4 = 0;
    pos height = 0, width = 0;
};

Screen::pos verify(Screen::pos);
void Screen::setHeight(pos var){
    // - height is the member because there is a match in class definition, i.e., a member
    // - verify is the outer scope, the global in line 71
    height = verify(var);
}

int main()
{
    return 0;
}