#include <string>
/* It is not always possible to write a single template that is best suited for every possible template argument with
which template might be instantiated. E.g. compare 
*/
    // - general version
        // - takes two references to const any-type
template <typename T> int compare (const T&, const T&)
{
    return 0;
};
    // - string literal version
        // - takes two reference to char array
template <size_t N, size_t M> int compare (const char (&)[N], const char (&)[M])
{
    return 0;
};

// Defining a Function Template Specialization
    // - to indicate we are specializing a template, we use empty template parameter list, i.e., <>
    // - we must supply arguments for every template parameter in original templatet.
        // - to handle string literal, T is specialized to type `const char*`, i.e., a pointer to const char 
            // - so compare requires reference to `const` version of this type, i.e., a ref to a const pointer that points to a const char
            // - so const T& is specialized to `const char* const &`, from right to left, 
                // - &: a ref 
                // - const &: a ref to a const type
                // - char* const &: a ref to a const type of (pointer to char)
                // - const char* const &: a ref to a const type of ( const pointer to char)
                    // - e.g., a reference to a `const` pointer to a `const char`
        // - a better match than the general version to a call
    // - we define a function template specialization to provide definition of a specific instantiation of the original template
        // - an instantiation, not overloaded isntance of the function name
template <>
int compare(const char* const &p1, const char* const &p2)
{
    return strcmp(p1, p2);
};

// Class Template Specializations
    // - differently from function templates, a class template specialization does not have to supply ar argument for every template parameter
        // - i.e., we can partially specialize only a class template, but cannot partially specialize a function template
    // - a class template partial specialization is itself a template,i.e., 
        // - users must supply arguments for those template parameters that are not fixed by specialization

int main()
{
    // p1 and p2 are pointer to const char array
    const char *p1 = "hi", *p2 = "mom";
    // call general version
        // - because no way to convert pointer to ref to array so string literal versiion is not viable
    compare(p1, p2);
    // call string literal version
        // call the specialized version if it is in scope
    compare("hi", "mom");
    return 0;
}