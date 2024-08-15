
// Classes that represent containers from which elements can be retrieved by postion often define the subscript operator, `operator[]`
    // - must be a member function
    // - usaully return a ref to the element that is fetched
        // - subscript can be used on either side of an assignment
    // - usually define both const and non-const versions
        // - non-const version returns a plain ref
        // - const version returns a ref to const