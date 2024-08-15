
#include <iostream>
#include <vector>
using namespace std;


class Screen {
    // WIndow_mgr members can access private parts of Screen
        // - not transitive, i.e., Window_mgr's friends has no speciall access to Screen
friend class Window_mgr;
        // - or we could only make a member of Window_mrg a friend
            // - need carefully structure 
                // - 1. define Window_mgr class which declare but not define clear
                // - 2. define Screen and declare clear a friend
                // - 3. define clear which now refers to members of Screen
// friend class Window_mgr::clear(ScreenIndex);
        // - declare each function in a set of overloaded functions as a friend
public:
    // pos is a type member
        // - we can equivalently use a type alias, i.e., using pos = string::size_type;
        // - type member usually appear at teh beginning of the class
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
    // implicitly inline
    char get() const { return contents[cursor]; }
    pos get_size() const { return this->size(); }
    // explicitly inline
    // member functions can be overloaded, just as regular functions
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);

    // display() overloaded on whether the obejct is const or not
    Screen &display(ostream &os) { do_display(os); return *this; }
    const Screen &display(ostream &os) const { do_display(os); return *this; }
private:
        // - Actually display work is done by do_display()
    void do_display(ostream &os) const { os << contents; }
    // Mutable data member
        // - never a const, even it is a member of a const object
        // - a const member function may change a mutable member
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    // ex7.33
    pos size() const { return height * width;}
};

// Specify inline on member function defined outside
inline
Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}


inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    // this is a pointer to the underlying object
    // move() returns a ref to such obejct, not a ref to the pointer
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    // get() is a const member function but it can change the mutable access_ctr
    ++access_ctr;
    return contents[row + c];
}

// Initializers for Data Mebers of Class Type
class Window_mgr {
    // Now Window_mgr is a friend of Screen
public:
    using ScreenIndex = vector<Screen>::size_type;
    // - reset the Screen at given position to all blanks.
    void clear(ScreenIndex);
    // - addScreen return ScreenIndex, no need to use Window_mrg:: here since it inside class definition
    ScreenIndex addScreen(const Screen&);
private:
    // screens is a data member of Window_mgr
        // - it is a class type
        // - its initializer should be in form of curly braces
            // - or = form, as Screen's members, cursor, height, width
    vector<Screen> screens{Screen(24, 80, ' ')};
};

    // -  Here is outside of Window_mgr, so must use Window_mgr:: before ScreenIndex
        // - but in parameter list and function body, no need to use Window_mrg::, e.g., before screens
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    // access to Screen's private members: contents, height, and width
    s.contents = string(s.height * s.width, ' ');
}

// Forward declaration of class
    // - declare but not define yet
    // - Screen2 is an incomplete type
class Screen2;
    // - limited use
        // - define ref/pointer to such type
        // - declare functions that use such type as parameter or return type
    // - A class must be defnied, not just declared, before we create objects of such type
        // - e.g., use pointr or ref to access such type
        // - otherwise, compiler will not know how much storage for them
        // - a class cannot have data members of its own type
            // - but can have data members that are pointers or references to its own type
class Link_screen {
    Screen window;
    Link_screen *next;
    Link_screen *prev;
};

// Class types
    // - Every class defines a unique type, even they define the same members.
struct First {
    int memi;
    int getMem();
};

struct Second{
    int memi;
    int getMem();
};

// Friend Declaration and Scope
struct X {
    // - friend function can be defined inside a class body.
    // - declare a friend function does not declare that function in an ordinary sense.
    friend void f() {};
    // X() {f(); } // error - cannot use f() yet, not declared.
    void g();
    void h();
};

// void X::g() { return f(); } //error - f() is not declared
void f(); //declare f()
void X::h() { return f(); } // ok - since f() was declared, i.e., in scope


int main()
{
    Screen myScreen{5, 5, 'X'};
    char ch = myScreen.get();
    ch = myScreen.get(0, 0);

    // Since move() and set() both return a ref to the underlying object
    // when we concatenate a sequence of actions into a single expr, operations are on the underlying object
        // - we can achieve this if one of these operations is from sa const member functoin that returns *this
            // - such fucntion returns a const &Screen, then set() will not be able to change it.
            // - we can use function overloading to work around this
    myScreen.move(4, 1).set('#');
    myScreen.display(cout);
    cout << endl;

    myScreen.move(4, 1).set('Y').display(cout);
    cout << endl;

    const Screen blank(5, 3, 'b');
    blank.display(cout);

    // When delcare a class type, we can add a class keyword
    const class Screen blank2(6, 3, 'c');
    blank2.display(cout);
    cout << endl;

    First obj1;
    // Compiling error - obj1 and obj2 have different types
    // Second obj2 = obj1;

// Class scope
    // - use pos type defined by Screen
    Screen::pos ht = 24, wd = 80;
    Screen scr(ht, wd, ' ');

    Screen *p = &scr;
    char c = scr.get();
    cout << "c is: " << c << '\n';
    c = p->get();
    cout << "c is: " << c << '\n';

    cout << "size is: " << scr.get_size() << '\n';

    return 0;
}