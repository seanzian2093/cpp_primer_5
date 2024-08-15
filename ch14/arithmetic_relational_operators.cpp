
// Arithmetic and Relational Operators
    // - ordinarily, we define arithmetic and relational operators as non-member function
        // - in order to allow conversions for either left-hand or right-hand operand
        // - compound-assignment should be a member function
    // - should not need to change the sate of either operand
        // - so the parameters are ordinarily ref to const

// Arithmetic Operators
    // - an arithmetic operator usaully generates a new value that is the result of a computation on its two operands
        // - value is calculated in a local var
        // - returns a copy of such local var
        // - usually define corresponding compound assignment operator
            // - compound-assignment should be a member function

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    // copy lhas to a local var of Sales_data type
    Sales_data sum = lhs;
    // use related compound-assignment which is defined together
    sum += rhs;
    // return the local var
    return sum;
}
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue ;
    return *this;
}

// Equality Operator
    // - compare two objects of same type 
    // - treat as equal if and ONLY if all coresponding members are equal
    // - principles
        // - use `operator==` rather than a named function if a class has an operation to determine whether two objects are equal
        // - define a `operator!=` accordingly
        // - one of equality or inequality operators should delegate the work to the other,i.e., who does the real work
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold = rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    // delegate real work to `operator==`
    return !(lhs == rhs);
}

// Relational Operators
    // - useful to define an `operator<` since associative containers and some algorithms use less-than operator 
    // - consistent with requirements for use as a key to an associative container
    // - consistent with ==
        // - if two objects are !=, then one should be <= the other