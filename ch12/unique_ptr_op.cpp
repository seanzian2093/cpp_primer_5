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

// Common Operations
    // - to shared_ptr and unique_ptr
    // - shared_ptr<T> sp, unique_ptr<T> up
        // - declare a null smart pointer that CAN point to ojbects of type T.
    // - p, use p as condition, true if p points to an object, i.e. not null
    // - *p, dereference to get the object to which p points to
    // - p->mem, (*p).mem
    // - p.get(), returns the pointer in p. the object to which the returned pointer points will disappear when p deletes it
    // - swap(p, q), p.swap(q), swap the pointers in p and q

// unique_ptr Operation - p587
    // - unique_ptr<T> u1
        // - a null unique_ptr that can point to object of type T.
        // - use delete to free its pointer
    // - unique_ptr<T, D> u2
        // - a null unique_ptr that can point to object of type T.
        // - use a callable object of type D to free its pointer, in place of delete
    // - unique_ptr<T, D> u(d)
        // - a null unique_ptr that can point to object of type T.
        // - use a callable object d of type D to free its pointer, in place of delete
    // - u = nullptr
        // - deletes the object to which u points, makes u null
    // - u.release()
        // - relinquishes control of the pointer u had held;
        // - return the pointer u had held 
        // - makes u null
    // - u.reset(), u.reset(q), u.reset(nullptr)
        // - delete the object to which u points
        // - if built-in pointer q is supplied, makes u point to that object
        // - other wise make u null
    
// Define a unique_ptr
    // - no library function comparable to make_shared that returns a unique_ptr
    // - bind it to a pointer by new
    // - must use direct form of initialization

    // - unique_ptr does not support ordinary copy or assignment
        // - because it owns the object to which it points
        // - but can be returned in a return statemen of a function.

unique_ptr<int> clone(int p) {
    // or return directly
    return unique_ptr<int> (new int(p));
}

unique_ptr<int> clone2(int p) {
    // return a local object
    unique_ptr<int> ret(new int(p));
    return ret;
}
int main()
{
    // - a null one
    unique_ptr<double> p1;
    // - direct init
    unique_ptr<int> p2(new int(42));

    // - 
    unique_ptr<string> ps1(new string("Stegosaurus"));
    // error - can not copy from ps1
    // unique_ptr<string> ps2(ps1);
    unique_ptr<string> ps3;
    // error - can not assign, because copying is involved
    // p3 = p2;


    // transfer ownership from ps1 to ps2
    unique_ptr<string> ps2(ps1.release());
    cout << "After transfer, ps2 points to: " << *ps2 <<'\n';

    unique_ptr<string> ps4(new string("Trex"));
    // delete memory to which ps2 pointed and make ps2 point to ps4's underlying object
    ps2.reset(ps4.release());
    cout << "After reset, ps2 points to: " << *ps2 <<'\n';

    auto p3 = clone(44);
    cout << "After clone, p3 points to: " << *p3 <<'\n';

    auto p4 = clone2(48);
    cout << "After clone2, p4 points to: " << *p4 <<'\n';

    cout << endl;
    return 0;
}