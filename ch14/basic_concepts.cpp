// Overloaded operators are funtions with
    // - special names: the keyword operator,
    // - followed by symbol for the operator being defined
    // - three parts,like other functions
        // - return type
        // - parameter list
        // - body
    // - have same number of parameters as the operator has operands
        // - unary has one paramter; binary has two
        // - in a binary operator, left-hand operand is passed to first parameter
            // - right-hand to second
        // - may not have default arguments
            // - except for the function-call operator : `operator ()`
        // - if it is a member function, the first operand(left-hand) is bound to implicit pointer `this`
    // - must be either a member of a class 
        // - or have at least one parameter of class type
        // - e.g. cannot redefine built-in operator for ints
    // - has same precedence and associativity

// Calling an Overloaded Operation Function Directly
    // - `data1 + data2` is expression-based call, equivalant to function call `operator+(data1, data2)`
    // - if calling data1's member operator function `+=`,  `data1 += data2` is expression-based call, equivalant to function call `data1.operator+=(data2)`
        // - when we define an operator as a member function, the left-hand operand must be an object of the class of which the operator is a member.

// Some Operators Should Not Be Overloaded
    // - a few operators guarantee the order in which operands are evaluted
    // - overloaded operator functions does not guarantee such
        // - because overloaded operator functions are essentially function calls
    // - logical AND, logical OR, and comma operator are among these function
    // - overloaded version of `&&` and `||` operators do not preserve short-circut evaluation properties of the built-in operators
        // - both operands are always evaluated
    // - comma and address of operators too should not be overloaded