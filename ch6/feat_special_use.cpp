#include <iostream>

using namespace std;

// Default Arguments
typedef string::size_type sz;
string screen(sz ht =24, sz wid = 80, char background = ' ') { return "";}; 

    // Default Argument Declarations
        // - each parameter can have its default value declared only once 
string screen2(sz, sz, char background = ' ');
            // error - trying to redefine screen2
        // - defaults can be specified only all paramters to the right already have defaults
// string screen2(sz=24, sz=80, char); 
string screen2(sz, sz=80, char); 
string screen2(sz=24, sz, char); 

    // Default Argument Initializers
        // - local variables may not be used as a default argument
            // - ht(), wd, def must be declared outside a function
sz wd = 80;
char def = ' ';
sz ht() {return 1;};
string screen3(sz = ht(), sz = wd, char = def) {return "";};
            // - equivalent to screen3(ht(), wd, def)
string window = screen3();

void f2()
{
    // Change def, previously defined outside as ' ', to '*'
    def = '*';
    // Defined a local variables wd to hide wd, previously defined outside
        // - but does not change the default, which is resolved at declaration to be wd in outer scope
    sz wd = 100;

    // names of default arguments are evaluated at time of the call
        // - equivalent to screen3(ht(), 80, '*')
    string window = screen3();
}

// Inline Functions
    // - a function call is slower than evaluating the equivalent expression
    // - register saved before call and restored after the return; arguments may be copied; program branches to a new location

    // - use keyword inline before a function's return type to make it an inline function
        // - inline specification is only a request, i.e., compiler may choose to ignore
        // - if not ignored, run-time overhead of making a function is removed
inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

// constexpr Functions
    // - normally defined in header files
    // - normally defined in header files
    // - a function that can be used in a const expr
    // - restriction in definition
        // - return type and the type of each parameter must be literal type
        // - function body must contain exactly only one return statement.
            // - could also contain statements that generate no actions at run time
                // - null statements, type alias, using declaration
        // - constexpr function is implicitly inline
            // - complier replace a call to such function with its resulting value
constexpr int new_sz() { return 42;}
constexpr int foo = new_sz();
        // a constexpr function is permitted to return a value that is not a const
            // - scale will return a const if arg cnt is a const expr
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
int arr[scale(2)]; // ok - scale(2) is a const expr
int i = 2; // i is not a const expr
int a2[scale(i)]; // error - scale(i) is not a const expr


// Aids for debugging

    // assert Preprocessor Macro
        // - defined in cassert header
            // - proprocessor names are managed by preprocessor, not the compiler
                // - we use directly, no need a using declarating or specify namespace, std::assert
                // - better to avoid using assert or other names of preprocessors
        // - assert Preprocessor Macro, i.e., a preprocess variable acts like inline function
        // - assert(expr), evaluate expr
            // - if false, then assert writes a message and terminate the program
            // - if true, then assert does nothing
            // - often used to check for condition that cannot happen
        // - assert behave depending on the status of a preprocessor variable NDEBUG
            // - IF NDEBUG is defined, assert does nothing
            // - by default NDEBUG is not defined, so by default assert performs run-time check 
    
    // NDEBUG Preprocessor Variable
        // - to turn off debugging
            // - use #define to define NDEBUG at the beginning of script file
            // - use command line option to define NDEBUG, and other preprocessor variables.
        // - conditional debugging code using NDEBUG
void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
    // __func__ is a local static defined by compiler that holds the function's name
        // - similarly there are 
            // - __FILE__, string literal containg the name of the file
            // - __LINE__, integer literal containing the current line number
            // - __TIME__, string literal containing the time the file was compiled
            // - __DATE__, string literal containing the date the file was compiled
    cerr << __func__ << ": array size is " << size << endl;
    #endif
}

int main()
{
    string window;
    // equivalent to screen(24, 80, ' ')
    window = screen();
    // equivalent to screen(66, 80, ' ')
    window = screen(66);
    // equivalent to screen(66, 256, ' ')
    window = screen(66, 256);
    // equivalent to screen(66, 256, '#')
    window = screen(66, 256, '#');

    // error - can omit only trailing arguments
    // window = screen(, , '?');
    // equivalent to screen('?', 80, '#')
        // - '?' is char and converted to sz, 
        // - machine dependent, could be 0x3F, 63 in decimal
    window = screen('?');

    return 0;
}