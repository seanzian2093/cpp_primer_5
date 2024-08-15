#include <string>
// static class member
    // - a member is associated with the class, not a object of that class
        // - similar to class method/propoter in Python
        // - exist outside of any object, i.e., objects do not contain static members
    // - not bound to any object of that type
        // - no this pointer, no implicit or explicit use of this 
        // - can not be declared as const
        // - better definie and initialize outside class
            // - or inside with in-class initializers for static members that 
                // - has const integral type
                // - or are constexpr of literal type
                // - initializers must be const expressions

class Account {
public:
    // - member can use static membe directly
    void calculate() { amount += amount * interestRate; }
    static double rate() {return interestRate; }
    static void rate(double);

private:
    // An object of Account contains only owner and amount
    std::string owner;
    double amount;
    // interestRate is shared by all Account objects
    static double interestRate;
    static double initRate();
    // in-class initializer for constexpr
    static constexpr int period = 30;
    double daily_tbl[period];
};

    // - static member can be defined outside
void Account::rate(double newRate)
{
    // access static member directly
    interestRate = newRate;
}

    // - static member has access to private section
double Account::interestRate = initRate();

// Special use of static member
class Bar {
public:
    // ...
private:
    // ok - static member can have incomplete type, i.e. declared but not defined class type
    static Bar mem1;
    // ok - pointer member can have imcomplete type
    Bar *mem2;
    // error - ordinary data member must have complete type
    Bar mem3;
};

class Screen {
public:
    // ok - a static member can be used as default argument
        // - a nonstatic member can't because its value is part of the underlying object
            // - a nonstatic member exists upon a object
    Screen & clear(char = bkground);
private:
    static const char bkground;
}

int main()
{
    double r;
    // use a scope operate to access static member
    r = Account::rate();
    // access static member from object
    Account ac1;
    Account *ac2 = & ac1;
    r = ac1.rate();
    r = ac2->rate();
    return 0;
}