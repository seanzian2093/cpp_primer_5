#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::make_shared;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <list>
using std::list;

#include <vector>
using std::vector;

using std::initializer_list;
using std::out_of_range;

#include<new>
using std::bad_alloc;
using std::nothrow;

// Dynamically allocated object
    // - has an life time independent of where they are created
    // - exist untill are explicitly freed

// Static, Stack, and Heap 
    // - automatically allocated and freed by compiler
    // Static Memory are for
        // - local static object
        // - class static data members
        // - variables that are defined outside any function
        // - static objects are allocated before they are used and destroyed when the program ends

    // Stack Memory
        // - for non-static objects that are defined in functions
        // - stack objects exist only while the block in which they are defined is executing
    
    // Heap, aka, free store
        // - program allocate such memory for objects at runtime
            // - control their lifetime
            // - program must explicitly destroy such objects when not needed

// New library proves two smart pointer types
    // - defined in memory header
    // - that manage dynamic objects
    // - ensure that objects to which they point to are automatically freed when it is appropriate to do so
    // - shared_ptr
        // - allows multiple pointers to refer to same object
    // - unique_ptr
        // - owns the object to which it points
    // - weak_ptr
        // - weak reference to an object managed by a shared_ptr

// Common Operations
    // - to shared_ptr and unique_ptr
    // - shared_ptr<T> sp, unique_ptr<T> up
        // - declare a null smart pointer that CAN point to ojbects of type T.
    // - p, use p as condition, true if p points to an object, i.e. not null
    // - *p, dereference to get the object to which p points to
    // - p->mem, (*p).mem
    // - p.get(), returns the pointer in p. the object to which the returned pointer points will disappear when p deletes it
    // - swap(p, q), p.swap(q), swap the pointers in p and q

// shared_ptr specific operations
    // - make_shared<T>(args)
        // - returns a shared_ptr<T> which points to an object of T. Use args to construct this object
    // - shared_ptr<T>p(q)
        // - p is a copy of shared_ptr q; 
        // - increments the reference count(?) in q
        // - pointer in q must convertable to *T
    // - p=q
        // - p,q are shared_ptr and holding pointers that can be converted to each other
        // - decrement p's reference count and increments q's count
        // - delete p's existing memory if p's count goes to 0
    // - p.unique()
        // - return true if p.use_count() is one; false otherwise
    // - p.use_count()
        // - return the number of objects sharing with p;
        // - slow operations; intended for debugging purposes.

// Copying and Assigning shared_ptr
    // - when we copy or assign shared_ptr, each shared_ptr keeps track of how many OTHER shared_ptrs point to the same object
    // - when the last shared_ptr pointing to an object is destroyed, the shared_ptr class automatically destroys the object
        // - it does so through a special member function, i.e., a destructor
            // - destructor decrements reference count of the underlying object
            // - if reference count goes to 0, the destructor destroys the underlying object and frees the memory

    // Classes with Resources That Have Dynamic Lifetime
class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); };
    void push_back(const string &t) {data->push_back(t);};
    void pop_back();
    string& front();
    string& back();

private:
    // data is a member shared by multiple objects of this class type
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

    // - default constructor allocates an empty vector
StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
    // - Use il to construct 
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }
void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

// Managing Memory Directly
    // - new operator
        // - allocates memory
        // - returns a pointer to the object it allocates
        // - offers no way to name the object because objects allocated on free store are unnamed
            // - by default the object is default initialized
                // - built-in or compound type have undefined value;
                // - class are initialized by their default constructor
    // - delete frees memory allocated by new by two actions
        // - destroys the target object 
        // - frees the memory used by target object
        // - delete expr: delete p; p must be a dynamically allocated object or be null
            // - otherwise the the expr is undefined, i.e., 
            // - compiler cannot tell whether a pointer points to a statically or dynamically allocated object
            // - a const object can be deleted
            // - a dynamic object managed through built-in(ordinary) pointer exists untill it is explicitly deleted
Foo* factory(T arg)
{
    // caller of Factory is responsible for deleting this memory
    return new Foo(arg);
}
Foo* use_factory(T arg)
{
    Foo *p = factory(arg)
    // use p but do not delete it
        // - must delete p explicitly
    // delete p;
        // - or return it for if program needs it outside 
        // - must delete it after use
    // return p
}// p goes out of scope but the memory to which p points is not freed

// Other Ways to Define and Change shared_ptr
    // - shared_ptr<T> p(q)
        // - p manages the object to which the built-in pointer q points
        // - q must point to memory allocated by new
            // - must use direct form of intialization, cannot use implicit convert
        // - q must be convertible to T*
    // - shared_ptr<T> p(u)
        // - p assumes ownership from the unique_ptr u,
        // - makes u null
    // - shared_ptr<T> p(q, d)
        // - p manages the object to which the built-in pointer q points
        // - q must be convertible to T*
        // - q will use the callable object d, in place of delete, to free q.
    // - shared_ptr<T> p(p2, d)
        // - p is a copy of shared_ptr p2
        // - but p use callable d in place of delete
    // - p.reset(), p.reset(q), p.reset(q, d)
        // - if p is the only shared_ptr pointing at its object, reset frees p's existing object.
        // - makes p null
            // - or if optional built-in pointer q is passed, makes p point to q
        // - use delete to free q 
            // - or if d is supplied, use callable d to free q,
shared_ptr<int> clone(int p) {
    // error - must use direct intialization
    return new int(p);
    // ok - direct initialization
    return shared_ptr<int> (new int(p));
}

int main()
{
    // both p1 and p2 is null
    shared_ptr<string> p1;
        // error when trying to deference it
    // cout << "p1 points to: " << *p1 << '\n';
    shared_ptr<list<int>> p2;
    // use smart pointer in a condition is to test its null-ness
        // - a non-null pointer can point to a i.e., empty string
    if (p1 && p1->empty())
        *p1 = "hi";
    
    // Use make_shared to define and initialize 
    shared_ptr<int> p3 = make_shared<int>(42);
    cout << "p3 points to: " << *p3<< '\n';

    shared_ptr<string> p4 = make_shared<string>(10, '9');
    cout << "p4 points to: " << *p4<< '\n';

        // - value initialized
    shared_ptr<int> p5 = make_shared<int>();
    cout << "p5 points to: " << *p5<< '\n';

    auto p6 = make_shared<vector<string>>();
 
    // Copy and assign shared_ptr
        // - object to which p points has 1 user, i.e. reference count = 1
    auto p = make_shared<int>(42);
        // - now p and q point to the same object
        // - the object now have 2 users , i.e. reference count = 2
        // - when reference count = 0, shared_ptr automatically frees the object that it manages
    auto q(p);

        // - object to which r points has 1 user, i.e. reference count = 1
    auto r = make_shared<int>(42);
        // - upon assigning q to r
            // - reference count of the object that q points to increase by 1
            // - reference count of the object that r previously pointed to decreas by 1, to 0, automatically freed
    r = q;

    // Classes with Resources That Have Dynamic Lifetime
    vector<string> v1;
    {
        // A new scope
        vector<string> v2 = {"a", "an", "the"};
        v1 = v2;
    }
        // - upon leaving this scope, v2 is destroyed, its elements too 
        // - but v1 still has 3 elements which are a copy of elements in v2

    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }
    cout << "Ater the block b1: ";
    cout << "b1 front is: " << b1.front() <<'\n';
    cout << "b1 back is: " << b1.back() <<'\n';
    cout << "b1 size is: " << b1.size() <<'\n';

    // Managing memory directly
        // - pi points to a dynamically allocated, unnamed, undefined int
    int *pi = new int;
    cout << "pi points to " << *pi << '\n';

        // - direct initialization
    int *pi2 = new int(1024);
    cout << "pi2 points to " << *pi2 << '\n';

    string *ps = new string(10, '9');
    cout << "ps points to " << *ps << '\n';

    vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
    cout << "pv points to: ";
    for (auto &i: *pv)
        cout << i << ',';
        
    cout << '\n';
        // - value initialize with ()
    string *ps1 = new string;// default init to empty string
    cout << "ps1 is default initiallized and points to " << *ps1 << '\n';

    string *ps2 = new string();// value init to empty string
    cout << "ps2 is value initiallized and points to " << *ps2 << '\n';

    int *pi3 = new int();
    cout << "pi3 is value initialized to " << *pi3 << '\n';
        // - use auto to deduce type
            // - must use parentheses for intializer
    auto pa = new auto(42);
    cout << "pa points to " << *pa << '\n';

    auto pa2 = new auto("42");
    cout << "pa2 points to " << *pa2 << '\n';
        // - dynamically allocated const object must be initialized
    const int *pci = new const int(1023); // initializd explicitly
    const string *pcs = new const string; // initialized implicitly with default constructor


        // - use placement new with nothrow to surpess bad_alloc if unable to allocate the requested memory
    int *pi4 = new(nothrow) int;
        // - pi4 and pi5 point to same memory
    auto pi5 = pi4;
        // - delete pi4 invalidates both p and q
    delete pi4;
        // - assign nullptr to pi4 to indicate that pi4 is not bound to an object 
        // - q, on many machine, may still hold the address of the already-deleted memory, but is invalid, ie. dangling pointer
    pi4 = nullptr;

    // error - must use direct intialization
    shared_ptr<int> p1 = new int(1023);
    // ok - direct initialization
    shared_ptr<int> p2(new int(1023));

    cout << endl;
    return 0;
}