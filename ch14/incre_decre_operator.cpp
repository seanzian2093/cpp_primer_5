
// Increment(++) and Decrement(--) Operator
    // - prefer to define them as members because they change the stete of the object on which they operator
    // - prefer to define both prefix and postfix versions

    // - prefix operators should return a ref to the incremented or decremented object
    // - postfix operators should return the unincremented or undecremented value, not a ref
class StrBlobPtr {
public:
    // prefix
    StrBlobPtr & operator++();
    StrBlobPtr & operator--();
    // postfix
        // - parameter of int is not used thus no need to give a name
    StrBlobPtr & operator++(int);
    StrBlobPtr & operator--(int);
};
StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBolbPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    // if curr is the begin of the object, 
    --curr;
    check(-1, "decrement past begin of StrBolbPtr");
    return *this;
}

StrBlobPtr& StrBlobPtr::operator++(int)
{
    // retrieve a copy of old value
    StrBlobPtr ret = *this;
    // increment using prefix increment operator
    ++*this;   
    // return the copy of old value
    return ret;
}

StrBlobPtr& StrBlobPtr::operator--(int)
{
    // retrieve a copy of old value
    StrBlobPtr ret = *this;
    // decrement using prefix increment operator
    --*this;   
    // return the copy of old value
    return ret;
}

int main()
{
    StrBlobPtr p(a1);
    // Explicitly call postfix operator++
    p.operator++(0);
    // Explicitly call prefix operator++
    p.operator++();
    return 0;
}