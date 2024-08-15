#include <iostream>
#include <fstream>
using namespace std;

// `fstream` types inherit from `iostream` types
    // - `fstream` objects inherit all the operations of `iostream` types, so is `sstream` types
    // - `fstream`-specific operations
        // - f

// File Modes
    // - each stream has an associated file mode that represents how the file may be used
        // - `in`, open for input
        // - `out`, open for output
        // - `app`, seek to the end before every write
        // - `ate`, seek to the end immediately after open
        // - `trunc`, truncate the file
        // - `binary`, do IO operation in binary mode.
    // - we can supply a file mode with
        // - call open() or
        // - indirectly open thefile when initialize a stream from a file name
    // - restrictions
        // - `out` may be set only for `ofstream` or `fstream` oject
            // - by default, a file in `out` mode is truncated even if `trunc` is not explicitly specified
        // - `in` may be set only for `ifstream` or `fstream` oject
        // - `trunc` may be set only when `out` is also specified
            // - by default, a file in `out` mode is truncated even if `trunc` is not explicitly specified
            // - to preserve the contents of a file opened with `out`, we must either
                // - specify `app`, i.e., to append, write only at the end of the file
                // - Or also specify `in`, i.e., open the file for both input and output - ch17
        // - `app` may be set as long as `trunc` is not;
            // - if `app` is specified, file is open in `out` mode implicitly, even not explicity specified
        // - `ate` and `binary` may be specified on any file stream object type and in combination with other file modes

    // - each file stream type defines a default file mode
        // - `in` mode for file associated with `ifstream` 
        // - `out` mode for file associated with `ofstream` 
        // - both `in` and `out` mode for file associated with `fstream` 
    
    // - File Mode is determined Each Time open() is called
int main()
{
    // - creates an unbound file stream. `fstream` is one of the types defined in `fstream` header
        // - use fstrm.open() to associate fstrm with a file and open the file 
    fstream fstrm;

    // - creates an `fstream` and open file named s.
        // - s can be `string` type or a pointer to C-style character string
        // - file is opened automatically, no need to call fstrm.open()
    string s;
    fstream fstrm2(s);
        // - open in a given mode
    char mode;
    fstream fstrm3(s, mode);

    // - open a file s and bind it to fstrm, return void
    fstrm.open(s);
        // - in a given mode
    fstrm.open(s, mode);

    // - close the files to which fstrm is bound, return void
        // - when a `fstream` object is destroyed, close() is called automatically
    fstrm.close();

    // - return a bool indicating whether the file associated with fstrm was
        // - successfully opened
        // - has not been closed
    fstrm.is_open();

    // check if the open succeeded
    if (fstrm)
        {;}

    return 0;
}