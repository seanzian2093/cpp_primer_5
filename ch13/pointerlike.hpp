#include <string>

class HaPtrP {
friend ostream &print(ostream &, const HaPtrP &);
public:
    // constructor
    HaPtrP(const std::string &s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    // copy constructor
        // - copy the string to which ps of argument p points to, use it to init ps
        // - incredement to *use
    HaPtrP(const HaPtrP &p): ps(new std::string(*p.ps)), i(p.i), use(p.use) { ++*use; }
    // copy-assignment operator
    HaPtrP& operator=(const HaPtrP &);
    // destructor
    ~HaPtrP();

private:
    std::string *ps;
    int i;
    // use is a member to keep track of how many objects share *ps
    std::size_t *use;
};

HaPtrP::~HaPtrP()
{
    // upon destroying this object, reduce reference count, i.e, *use by 1
    if (--*use == 0) {
        // - if ref count reduces to 0, delete shared resources
            // - delete ps the string and
            // - delete use the reference counter
        delete ps;
        delete use;
    }
}

HaPtrP& HaPtrP::operator=(const HaPtrP &rhs)
{
    // Upon copy-assignment, increment refeence count of rhs
    ++*rhs.use;
        // - decrement original reference count of this object
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    // copy pointer from argument to ps, just the pointer, not the underlying object
    ps = rhs.ps;
    i = rhs.i;
    // now ps points to new resouces, update the reference count by copying the reference count
    use = rhs.use;
    return *this;
}

ostream & print(ostream &os, const HaPtrP &hpp)
{
    cout << "This HaPtP object's ps holds: \"" << *(hpp.ps) 
         << "\" at " << hpp.ps << " with ref count="<< *(hpp.use) << endl;
    return os;
}