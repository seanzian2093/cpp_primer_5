#include <initializer_list>
#include <string>

class StrVec {
public:
    template <class... Args> void emplace_back(Args&&...);
    // default constructor
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    // copy constructor
    StrVec(const StrVec&);
    // move constructor
    StrVec(StrVec&&) noexcept;
    // copy-assigment operator
    StrVec &operator=(const StrVec&);
    // move-assigment operator
    StrVec &operator=(StrVec&&) noexcept;
    // destructor
    ~StrVec();
    // assignment operator `=`
    StrVec &operator=(std::initializer_list<std::string>);
    // subscript operator `[]`
    std::string& operator[] (std::size_t n) { return elements[n]; }
        // - const version, i.e., a const pointer to a const object
    const std::string& operator[] (std::size_t n) const { return elements[n]; }

    // add a new element to end
        // - copy the element
    void push_back(const std::string&);
        // - an overloaded version that takes rvalue, i.e., move the element
    void push_back(std::string&&);
    // return number of elements
    size_t size() const { return first_free - elements; }
    // return available memory, i.e. number of free positions
    size_t capacity() const { return cap - elements; }
    // return pointer to first element
    std::string *begin() const { return elements; }
    // return pointer to one-past-end position 
    std::string *end() const { return first_free; }
private:
    std::allocator<std::string> alloc;
    // when no free spaces, call reallocate() to 
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy (const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

void StrVec::push_back(const string &s)
{
    // first ensure that there is room for another element
    chk_n_alloc();
    // construct the new element by copying s at the first free position, i.e.,which first_free points to
        // - then make first_free points to next position, the new first free position
        // - memory that is allocated by allocator is unconstructed
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy (const std::string *b, const std::string *e)
{
    // allocate memory to hold as many elements as in input range [b,e)
        // - data is a pointer to first position of allocated memory
    auto data = alloc.allocate(e - b);
    // return a copy of pair whch is constructed from 
        // - data and
        // - the value returned by uninitialized_copy()
            // - which is a pointer to one-past the last constructed element
            // - copies elements in [b,e) to position that starts at data
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // if elements is not 0 ,there is work to do
    if (elements) {
        // in reverse order
            // - destroy element in elements 
        for (auto p = first_free; p != elements;)
                // - destroy() runs the string destructor
            alloc.destroy(--p);
            // - free the memory
                // - 1st argument must a pointer return by allocate()
                    // - 2nd argument equals to the first argument of call allocate()
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    // calculate new capacity: we allocate memory for twice as many elments as the current size
        // - if current size is 0, allocate memory for 1 elment
    auto newcapacity = size() ? 2 * size() : 1;
    // allocate memory 
        // - newdata is the first position of allocated memory
    auto newdata = alloc.allocate(newcapacity);

    // create an iterator to denote the destination position to move elements to
        // - we need to advance this iterator so make a copy of newdata
    auto dest = newdata;
    // create an iterator to denote the target element, i.e., its position 
        // - we need to advance this iterator when moving elements 
    auto elem = elements;
    // Moving elements from old space to new
    for (size_t i = 0; i != size(); ++i)
        // - calling std::move returns a result that causes `construct` to use the string move constructor, i.e., 
            // - strings are not copied
            // - only ownerships are transfered
        alloc.construct(dest++, std::move(*elem++));
    
    // after moving is done, free old memory space
    free();

    // Update data members to point to new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

// noexcept(?) - signals to compiler that move constructor won't throw any exceptions
    // - otherwise compiler will do extra work to cater to the possibility that move constructor might throw
    // - must specify `noexcept` both in declaration and definition if definition is outside class
// - member initializers take over the resources of s
StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // leave s in a state where it is safe to run the desturctor
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    // direct test if self-assignment
        // - proceed only if not
    if ( this != &rhs) {
        // free existing element and take over from rhs
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        // leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <class... Args> inline void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}