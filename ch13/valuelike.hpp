#include <string>

class HaPtrV {
friend ostream &print(ostream &, const HaPtrV &);
friend void swap(HaPtrV&, HaPtrV&);
public:
    // constructor
    HaPtrV(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    // copy constructor
        // - copy the string to which ps of argument p points to, use it to init ps
    HaPtrV(const HaPtrV &p): ps(new std::string(*p.ps)), i(p.i) {}
    // copy-assignment operator
    HaPtrV& operator=(const HaPtrV &);
    // destructor
    ~HaPtrV() { delete ps; }

    // workload
    // print()
private:
    std::string *ps;
    int i;
};

HaPtrV& HaPtrV::operator=(const HaPtrV &rhs)
{
    // copy string from argument and save it to a temp var
    auto newp = new string(*rhs.ps);
    // free the old memory
    delete ps;
    // copy from temp var to ps
    ps = newp;
    i = rhs.i;
    return *this;
}

ostream & print(ostream &os, const HaPtrV &hpv)
{
    cout << "This HaPtV object's ps holds: \"" << *(hpv.ps) << "\" at " << hpv.ps << endl;
    return os;
}
