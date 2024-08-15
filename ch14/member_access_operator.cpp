#include <string>

// Dereference(*) and arrow(->) operators are often used in classes that
    // - represent iterators and 
    // - in smarter classes
        // - arraw(->) must be a member
            // - must be fetching a member
            // - i.e., when we write `p->mem`, p must be a pointer to a class object
                // - or an object of a class with an overloaded `operator->`
        // - dereference operator is not required by usually should be a member
            // - can be defined/overloaded to do whatever but better to be consistent with peer of built-in types

class StrBlobPtr {
public:
    std::string & operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    std::string & operator->() const
    {
        return & this->operator*();
    }
};