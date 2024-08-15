#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// 3 Standard Libraries
    // - iostream defines basic types that are used to read from and write to a stream
        // - isteam for read; wistream for reading wide character, wchar_t
        // - ostream, wostream for write
    // - fstream, that read and write named files
        // - ifstream, wifstream for read, 
        // - ofstream, wofstream for write
        // - fstream, wfstream for read and write 
    // - sstream, that read and write in-memory string 
        // - istringstream, wistringstream for read
        // - ostringstream, wostringstream for write
        // - stringstream, wstringstream for read and write

void process_input(istream &is)
{
    ;
}


// IO Condition States
    // - easiest way to determine the state of a stream is to use that object as a condition
        // - only telling if the stream is valid or not
            // - if any of badbit,failbit, or eofbit are set, a condition that evaluates the stream will fail


// No copy or Assign for IO Objects
    // - strm::iostate a machine-dependent integral type that represents the condition state of a stream
        // - badbit, failbit, eofbit, and goodbig
    // - strm::badbit indicates a system-level failure where strm is one of iostream, fstream or sstream
        // - an unrecoverable read or write error
        // - no possible to use the stream once badbit been set
        // - s.bad() is true if badbit in stream s is set
        // - s.fail() is true too if badbit in stream s is set
    // - strm::failbit is set after a recoverable error
        // - e.g., receiving a character while expecting a numeric
        // - possible to correct such problems and continue using the stream 
        // - s.fail() is true if badbit or failbit in stream s is set
    // - strm::eofbit indicates reaching end of file
        // - reaching end of file also set failbit
        // - s.eof() is true if eofbit in stream s is set
    // - strm::goodbit indicates no failures on the stream, guaranteed to have the value 0
        // - s.good() is true if s is in a valid state, i.e., none of eofbit, badibit or failbit is set
            // - similar to a condition that evaluates the stream
    
    // - more operations on stream states
        // - s.clear() reset all condition values in s to valid state, return void
        // - s.clear(flags) reset condition of s to flags, flags is one or more of states, return void
        // - s.setstate(flags) add specified conditions to s, returns void
        // - s.rdstate() return current condition of s as a strm::iostate value


// Managing the Output Buffer
    // - every output stream manages a buffer to hold the data that program reads and writes.
        // - allow the operating system to combine several output operations from our program into a single system-level write
            // - which is expensive
    // - Conditions that cause the buffer to be flushed, i.e., to be written, to actual output device or file
        // - the program completes normally. All outputs buffers are flushed as part of the return from main()
        // - at intermediate time, buffer becomes full in which case it will be flushed before writing the next value
        // - flush the buffer explicitly with a manipulator such as endl, ends, flush
            // - `endl`  inserts a new line to the buffer and flush it
            // - `ends` inserts a null character to buffer and flush it
            // - `flush` just flushes the stream without adding characters
        // - we `unitbuf` manipulator to set the stream's internal state to empty the buffer after each outupt operations
            // - by default, `unitbuf` is set for `cerr` so that writes to `cerr` are flushed immediately.
        // - an output stream might be tied to another stream. In such case, the buffer of the tied stream is flushed whenever
            // - the tied stream is read or written. e.g., by default, `cin` and `cerr` are tied to `cout`
            // - so when reading `cin` or writing to `cerr` flushes the buffer in `cout`
            // - use s.tie() function  
                // - s.tie(), i.e., taking no argument, return a pointer to the output stream to which s is currently tied
                    // - return a null pointer if s is not tied to any 
                // - s.tie(&os), i.e, taking a pointer to a outstream, ties s to that output stream os
                    // - return a pointer to the outstream previously tied to
                // - we can tie either an `istream` or an `ostream` to another `ostream`
    // - Buffers are not flushed if the program crashes

int main()
{

    ofstream out1, out2;
    out1 = out2;

    // we can not pass by value a parameter or return type that is one of stream type
        // - because we cannot copy them
        // - functions that do IO typically pass and return ref to IO objects
            // - reading and writing Io object changes its state, so the reference must not be const
    ofstream print(ofstream);
    out2 = print(out2);

    string word;
    while (cin >> word)
        ;
    

    auto old_state = cin.rdstate();// remember current state of cin
    cin.clear();//make cin valid
    process_input(cin); // use cin
    cin.setstate(old_state); // after done, reset cin to its previous state

    // turn off failbit, badbit but all other bits unchanged
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);

    // all writes will be flushed immediately
    cout << unitbuf;
    // return to normal buffering
    cout << nounitbuf;

    // ties cout to cin - illustration only; library does this for us
    cin.tie(&cout)
    // tie cin to a null pointer, return the old output stream that cin was tied to
    ostream *old_tie = cin.tie(nullptr)
    cin.tie(&cerr); // not a good idea though legit
    cin.tie(old_tie);
    return 0;
}

        