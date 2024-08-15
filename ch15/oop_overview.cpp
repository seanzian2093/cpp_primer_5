
// Classes related by inheritance form a hierarchy
    // - base classat the root of hierarchy
    // - other classes, aka derived classes, inherit direcly or indirectly from base class

    // - use `virtual` keyword to define functions that it expects its derived classes to define for themselves
        // - non-virtual members are resolved at compile time, not as virtual ones in run-time
        // - if derived class does not override virtual, it inherits the version defined in base class,like other functions.
            // - if override, derived lclass may include the `override` on functions that it overrides

    // - a derived class must specify the classes from which it intends to inherit
        // - by a class derivation list, which is a colon followed by a comma-separated list of base classes
            // - each of which may have an optional access specifier, i.e., public, private, protected
        // - a derived class can be a base class to other classes
            // - so root class is direct base to classes that direcly inherit it, indirect base to others 

    // - a derived can explicitly indicate that it intends to override the virtual funcion it inherits from base class by
        // - use `override` keyword after parameter list 
    
    // - dynamic binding happens when a virtual function is called through a ref or a pointer to a base class
        // - also known as run-time binding becase decision as to which version to run depends on the type of argument
    
    // - base class should define a destructor, even a virtual one
        // - a class must be defined before being used as base class 

    // - `protected` members in a base class are those derived classes have access to but not other users

    // - in derivation list, access specifier
        // - determines whether users of a derived class are allowed to know that the derived class inherits from its base class
        // - when derivation is `public`, 
            // - the `public` members of the base class become part of the interface of derived class too
            // - we may use a derived class object where a pointer or refer to base class object is expected
                // - this conversion is referred as `derived-to-base` conversion
        // - must appear in clas body, i.e., cannot in declaration

    // - derived class has two parts
        // - the members defined in itself
        // - the members inherited from base class
            // - derived class cannot directly initialize those members
            // - must use base class constructors to initialize them
        // - not guaranteed to be store contiguously in memory
    
    // - Inheritance and static members
        // - if a base class defines a static member, there is only one such member defined for entire hierarchy
            // - which can be access through
                // - base class or its objects
                // - derived class or its objects, if accessbile
    
    // - following the class name with`final` in declaration/definition to prevent a class from being used as a base

// Conversions and Inheritance
    // - static type of an expression(a var) is always known at compile time
            // - it is the type with which a variable is declared or the expression yields
    // - dynamic type is the type of the object in meory that the var or the expression represents
        // - it it not known until run time 
        // - e.g. in expr `double ret = item.net_price(n);`, item's static type is the type in its declaration
            // - but dynamic type is the type of object that is bound to item
    // - no implicit conversion from base to derived class
        // - becase members of derived class do not exist in base class
    // - no conversion between objects
        // - automatic derived-to-base conversion applies only for conversions to a ref or pointer type
        // - conversions between objects will involve calling constructors/copy operators etc
            // - they only know about the members of the calling class
    // - when initializing or assign an object of a base type from an object of derived type
        // - only the base-part of the derived-class object is copied, moved, or assigned
        // - the derived part is ignored