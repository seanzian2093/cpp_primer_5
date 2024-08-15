#include<string>
using std::string;

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<deque>
using std::deque;

#include<forward_list>
using std::forward_list;

#include<array>
using std::array;

#include<iostream>
using std::cout;
using std::endl;

#include<stack>
using std::stack;

#include<queue>
using std::queue;
using std::priority_queue;

// An adaptor is a mechanism for making one thing act like another
    // - a container adaptor takes an existing container type and makes it act like another
    // - the library defines three sequential container adaptors
        // - all three require ability to add and remove elementrs, and access last element in the container
            // - so can not be built on array or forward_list
        // - stack
            // - requires push_back, pop_back, and back operations
        // - queue
            // - requires back, push_back, front, and push_front
            // - can be built on a list or deque, not on a vector
        // - priority_queue
            // - require random access, front, push_back, and pop_back
            // - can be built on a vector or deque, not on list
    // - each adaptor defines two constructors
        // - default constructor that creates an empty object
        // - a constructor that takes a container and initializes the adaptor by copying the given container
    // - by default
        // - stack and queue are implemented in terms of deque
        // - priority_queue is implemented on a vector
        // - we can override the default container type by naming a sequential container as a second type argument

// - Common operations
    // - size_type
        // - type that is large enough to hold the size o the largest object of this type
    // - value_type
        // - element type
    // - container_type
        // - type of the underlying container on which the adaptor is implemented
    // - A a;
        // - create a new but empty adaptor named a
    // - A a(c);
        // - create a new but empty adaptor named a, initialized with a copy of the container c.
    // - relational operators
        // - ==, !=, <, <=, >, >=
        // - return the result of comparing teh underlying containers
    // - a.empty()
        // - false if a has any elements, true otherwise
    // - a.size()
        // - number of elements in a
    // - swap(a,b)
        // - swap the contents of a and b
        // - a and b must have same type, including the types of underlying containers

// Stack Adaptor
    // - defined in stack header
    // - s.pop()
        // - removes, but does not return, the top element from the stack; 
    // - s.push(item)
        // - create a new top element on the s by copying or moving, or constructing the element 
    // - s.emplace(args)
        // - create a new top element on the s by constructing the element from args 
    // - s.top()
        // - returns, but does not remove, the top element on s

// Queue Adaptor
    // - defined in queue header
    // - library queue uses a first-in, first-out storage and retrieval policy
        // - objects entering the queue are placed in the back
        // - objects leaving quue are removed from the front
    // - by default queue and priority_queue use vector
        // - queue can use a list
        // - priority_queuqe can use a deque
    // - q.pop()
        // - removes, but does not return, 
            // - the front element from a queue 
            // - or highest-priority element from a priority_queue
    // - q.front()
        // - return, but does not removes the front element of q 
        // - only valid for queue
    // - q.back()
        // - return, but does not removes the back element of q 
        // - only valid for queue
    // - q.top()
        // - returns, but does not remove, the highest-priority element of q
        // - only valid for priority_queue
    // - q.push(item)
        // - create a new element with the value item 
            // - at the end of queue
            // - in its appropriate position in priority_queue
    // - q.emplace(args)
        // - create a new element with value constructed from argsat the end of queue
            // - at the end of queue
            // - in its appropriate position in priority_queue

int main()
{
    deque<int> deq;
    stack<int> stk(deq);

    // an empty stack implemented on top of vector
    vector<string> svec;
    stack<string, vector<string>> str_stk;
        // - initialized with a copy of svec
    stack<string, vector<string>> str_stk2(svec);

    // Use of stack
    stack<int> intStack;
    for (size_t ix = 0; ix != 10; ++ix)
        intStack.push(ix);
    
    while (!intStack.empty()) {
        int value = intStack.top();
        // use value
        // pop the top element and repeat
        intStack.pop();
    }

    return 0;
}