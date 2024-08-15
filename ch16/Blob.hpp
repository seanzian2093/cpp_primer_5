#ifndef BLOB_H
#define BLOB_H

#include <vector>

// Forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

// Blob class template
template <typename T> class Blob{
    // ONLY BlobPtr<T> and operator==<T> are friends when T is same with Blob<T>
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    // to use T from template parameter list we need to explicitly tell compiler by using `typename`
    typedef typename std::vector<T>::size_type size_type;
    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It> Blob(It b, It e);
    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    // element access
        // - back(), overloaded on const
    T& back();
    const T& back() const;
        // - front(), overloaded on const
    T& front();
    const T& front() const;
    T& operator[](size_type i );
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};


template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T> T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T& Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> const T& Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    return data->pop_back();
}

template <typename T> Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }
template <typename T> Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { }
template <typename T> template <typename It> Blob<T>::Blob(It b, It e): data(std::make_shared<std::vector<T>>(b, e)) {}

// BlobPtr class template
template <typename T> class BlobPtr{
public:
    // constructors
    BlobPtr(): curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    // deref operator
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    // increment and decrement
        // - we can use class template name directly, without arguments
            // - since we are inside the scope of a class template
    BlobPtr& operator++();
    BlobPtr operator++(int);
    BlobPtr& operator--();
    BlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // inside this member function, we are in scope of the class template
        // - so we can use class template name without argument list
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--()
{
    check(curr, "decrement past end of BlobPtr");
    --curr;
    return *this;
}

#endif