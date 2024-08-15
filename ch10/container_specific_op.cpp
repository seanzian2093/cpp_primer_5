

// list and forward_list define several algorithms as member

// list
    // - sort
        // - generic version of sort cannot be used with list and forward_list
            // - because it requires random access iterator while
                // - list offers bidirectional iterator
                // - forward_list offers forward iterator
        // - other generic(than sort) can be used with list but with a performance cost
    // - merge
    // - remove
    // - reverse
    // - unique
