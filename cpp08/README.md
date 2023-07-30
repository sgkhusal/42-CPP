
# STL (Standard Template Library)

A set of template classes and functions that supply the programmer with:
- Containers for storing information
- Iterators for accessing the information stored
- Algorithms for manipulating the content of the containers

## STL Containers
Template classes that are used to store data.

### Sequential containers
- hold data in a sequential fashion, such as arrays and lists.
- characterized by a fast insertion time
- relatively slow in find operations.

#### 1. std::vector
- like a dynamic array - it can resize itself to suit the application’s runtime requirements
- You can add or remove items at the end
- you can directly access or manipulate an element in the vector given its position (index) using the subscript operator ([]).
- To keep the property of being able to randomly access an element in the array when given a position, most implementations of the STL vector keep all elements in contiguous locations. Therefore, a vector that needs to resize itself often can reduce the performance of the application, depending on the type of the object it contains.

#### 2. std::deque
- Similar to std::vector
- it allows for new elements to be inserted or removed at the beginning, too

#### 3. std::list
- Operates like a doubly linked list.
- You can add or remove objects at any position
- a list can organize elements in noncontiguous sections of memory. Therefore, it does not have the performance issues that are applicable to a vector when the vector needs to reallocate its internal array

#### 4. std::forward_list
- Similar to a std::list
- it is a singly linked list of elements that allows you to iterate only in one direction

### Associative containers
- store data in a sorted fashion - like a dictionary.
- slower insertion times
- significant advantages when it comes to searching

#### 1. std::set
- Stores unique values sorted on insertion in a container featuring logarithmic complexity

#### 2. std::map
- Stores key-value pairs sorted by their unique keys in a container with logarithmic complexity

#### 3. std::multiset and std::multimap
- Akin to a set/map
- Supports the ability to store multiple items having the same value/key; that is, the values/keys don’t need to be unique.

### Containers adapters

## References

1. Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017