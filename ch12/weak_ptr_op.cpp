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

// weak_ptr is a smart pointer
    // - does not control the lifetime of the object to which it points to
    // - points to an object that is managed by shared_ptr
    // - binding a weak_ptr to a shared_ptr does not change the reference count of that shared_ptr.
    // - once reference cout reduces to 0, the underlying object will be deleted even a weak_ptr still points to it
        // - we cannot access the underlying object direcly, i.e., dereference
        // - must call lock()
// weak_ptr operations
    // - weak_ptr<T> w
        // - a null weak_ptr that can point at object of type T
    // - weak_ptr<T> w(sp)
        // - a weak_ptr that points to the same object as the shared_ptr sp
        // - T must be convertible to the type to which sp points
    // w = p
        // - p can be shared_ptr or a weak_ptr.
        // - After the assignment, w shares ownership with p
    // - w.reset()
        // - makes w null.
    // - w.use_count()
        // - number of shared_ptr that share ownership with w
    // - w.expired()
        // - return true if w.use_count() is 0, false otherwise
    // - w.lock()
        // - if expired is true, returns a null shared_ptr
        // - otherwise return a shared_ptr to the object to which w points


int main()
{
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);
    // error - no direct access to wp
    // cout << "wp points to: " << *wp << '\n';
    // - use lock to access wp with check
        // - true if np is not null
    if (auto np = wp.lock()) {
        cout << "np points to: " << *np << '\n';
    }
    cout << endl;
    return 0;
}