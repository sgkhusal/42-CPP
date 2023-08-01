
# STL (Standard Template Library)

A set of template classes and functions that supply the programmer with:
- Containers for storing information
- Iterators for accessing the information stored
- Algorithms for manipulating the content of the containers

-----------------------------
## STL Containers
Template classes that are used to store data. They need to be instantiated specifying the type of object

**About containers complexity:**
- constant complexity: the performance of the container is unrelated to the number of elements contained by it. It would need as much time to perform on a thousand elements as it would on a million.
- logarithmic complexity: the performance is proportional to the logarithm of the number of elements contained in it. It would take twice as long in processing a million elements (1,000,000 = 1,000 ^ 2) as it would in processing a thousand.
- linear complexity: the performance is proportional to the number of elements. It would be a thousand times slower in processing a million elements than it would be in processing a thousand (1,000,000 = 1,000 * 1,000)

For a given container, the complexities may be different for differing operations (for example, element insertion complexity may be constant but search complexity linear). **It is important to understand how a container may perform as also the functionality it will be used with to choose the right container**. Your application might have requirements that can be satisfied by more than one STL container. But the selection is important because a wrong choice could result in performance issues and scalability bottlenecks.

-----------------------------
### Sequential containers
- elements are stored and accessed in a sequencial order that they are inserted.
- characterized by a fast insertion time
- relatively slow in find operations.

#### 1. std::vector
- `<vector>` library
- It is a dynamic array - it can resize itself to suit the application’s runtime requirements and manages the memory usage.
- You can add or remove items at the end
- elements are stored and accessed in the very order that they are inserted; it doesn't change the order of the elements stored in it
- To keep the property of being able to randomly access an element in the array when given a position, most implementations of the STL vector keep all elements in contiguous locations. Therefore, a vector that needs to resize itself often can reduce the performance of the application, depending on the type of the object it contains.
- The time required for the insertion or removal of elements at the middle is directly proportional to the number of elements behind the element being removed

```c++
std::vector<int> integares; // vector containing integers
std::vector<float> floats; // vector containing floats
std::vector<Tuna> tunas; // vector containing Tunas

// vector constructors
// vector with 10 elements with default value 0 (it can still grow)
std::vector<int> tenElements(10);

// vector with 10 elements, each initialized to 90
std::vector<int> tenElemInit(10, 90);

// copy constructor (only same types)
std::vector<int> copy(tenElemInit);

// vector initialized to 5 elements from another using iterators
std::vector<int> partialCopy(tenElements.cbegin(), tenElements.cbegin() + 5);
```

Access to elements:
- you can directly access or manipulate an element using the subscript operator ([])
- If you use it to access elements in a vector at a position that is beyond its bounds, the result will be undefined.
- `at()` performs a runtime check against the size of the container and throws an exception if you cross the boundaries
```c++
tenElements[3] = 2011;
std::cout << integers.at(2);

// accessing using iterators: see section about iterators below
```

- Insert, remove elements and delete all elements:
```c++
// Insert element into the end
integers.push_back(50);

// insert an element at the beginning
integers.insert(integers.begin(), 25);

// Insert 2 elements of value 45 at the end
integers.insert(integers.end(), 2, 45);

// Insert two elements from another container in position [1]
std::vector<int> another(2, 30);
integers.insert(integers.begin() + 1, another.begin(), another.end());

// integers = 25 30 30 50 45 45

// remove elements
integers.pop_back(); // erase one element at the end

// delete all elements
integers.clear();
if (integers.empty())
	std::cout << "The container is now empty" << std::endl;
```

- Prefer to use `push_back` instead of `insert` to add elements to a vector. `insert` is inefficient because adding elements in the beginning or the middle makes the vector class shift all subsequent elements backwards (after making space for the last ones at the end) and, depending on the type of the objects contained in the sequence, the cost of this shift operation can be significant in terms of the copy constructor or copy assignment operator invoked.
**If your container needs to have very frequent insertions in the middle, you should ideally choose the `std::list`**


**Size and Capacity of a vector**
- The size of a vector is the number of elements stored in a vector.
```c++
std::cout << "Size: " << integers.size() << std::endl;
```
- The capacity of a vector is the total number of elements that can potentially be stored in the vector before it reallocates memory to accommodate more elements
```c++
std::cout "Capacity: " << integers.capacity() << std::endl;
```

**Reallocation and performance issues - using reserve function**
- It increases the amount of memory allocated for the vector’s internal
array without needing to reallocate when adding more elements.
- A vector can cause some amount of performance problems when it needs to frequently reallocate memory.
- Reducing the number of reallocations also reduces the number of times the objects are copied and saves on performance.
- There is also member function `resize`

**Advantages:**
- Quick (constant time) insertion at the end (the time needed to insert at the end is not dependent on the size of the array). The same for
removal of an element at the end.
- Array-like access

**Disadvantages:**
- Resizing can result in performance loss.
- Search time is proportional to the number of elements in the container.
- Insertion only at the end.

**Note:** the vector methods shown in this section also apply to other STL containers

#### 2. std::deque
- `<deque>` library
- Similar to std::vector
- it allows for new elements to be inserted or removed at the beginning, too, with `push_front` and `pop_front` methods.

**Advantages:**
- All advantages of the vector.
- Offers constant time insertion at the beginning of the container too.

**Disadvantages:**
- Resizing can result in performance loss.
- Search time is proportional to the number of elements in the container.
- By specification does not need to feature the reserve() function that allows to reserve memory space to be used like the vector - a feature that avoids frequent resizing to improve performance.

#### 3. std::list
- `<list>` library
- Operates like a doubly linked list.
- You can add or remove objects at any position
- a list can organize elements in noncontiguous sections of memory. Therefore, it does not have the performance issues that are applicable to a vector when the vector needs to reallocate its internal array

**Advantages:**
- Constant time insertion at the front, middle, or end of the list.
- Removal of elements from a list is a constant time activity regardless of the position of the element.
- Insertion or removal of elements does not invalidate iterators that point to other elements in the list.

**Disadvantages:**
- Elements cannot be accessed randomly given an index as in an array.
- Accessing elements can be slower than the vector because elements are not stored in adjacent memory locations.
- Search time is proportional to the number of elements in the container.

**Reversing and Sorting Elements**
- iterators pointing to the elements in a list remain valid in spite of rearrangement of the elements or insertion of new elements and so on.
- To ensure this property, list has it's own `sort` and `reverse` member methods even though the STL supplies these as algorithms that will and do work on the list class

```c++
lst.reverse(); // reverse order of elements
lst.sort(); // sort in ascending order

bool yourSortingRule(const int& lhs, const int& rhs) {
	// define criteria for list::sort: return true for desired order
	return (lhs > rhs);
}
lst.sort(yourSortingRule);
```

**Important:** you need to implement `operator<` and `operator==` in a class that will be collected in a STL container such as list to supply the default sort or remove predicate.

**Best Practice:** DON’T use a list when you have infrequent insertions or deletions at the ends and no insertions or deletions in the middle; vector or deque can be significantly faster in these cases.

-----------------------------
### Associative containers
- store data in a sorted fashion - like a dictionary.
- slower insertion times but quick searches

#### 1. std::set and std::multiset
- `<set>` library
- Stores unique values sorted on insertion in a container featuring logarithmic complexity
- multiset is akin to a set with the difference that values don’t need to be unique.
- To facilitate quick searching, STL implementations of the set and multiset internally look like a binary tree
- An element at a given position in a set cannot be replaced by a new element of a different value. The set place the new element in a possible different location in accordance with its value relative to those in the internal tree.
- It uses a default predicate `std::less` when you don’t supply a sort criteria. This ensures that your set contains elements sorted in ascending order
- You need to program `operator<` and `operator==` for classes that can be collected in containers such as set or multiset. The former becomes the sort predicate, whereas the latter is used for functions such as `set::find()`.
- You create a binary sort predicate by defining a class with `operator()` that takes two values of the type contained in the set and returns a bool value. Example:

```c++
template <typename T>
struct SortDescending {
	bool operator()(const T& lhs, const T& rhs) const {
		return (lhs > rhs);
	}
};

// use this predicate in the set or multiset instantiation:
std::set<int, SortDescending<int>> setInts;
```

**Finding Elements:**
```c++
std::set<int>::const_iterator elementFound = setInts.find(-1);
// Check if found...
if (elementFound != setInts.end ())
	cout << "Element " << *elementFound << " found!" << endl;
else
	cout << "Element not found in set!" << endl;
```
- `find()` makes use of the internal binary tree structure

**Advantages:**
- Search performance proportional to the logarithm of number of elements. Often significantly faster than sequential containers.
- Optimized for situations that involve frequent search. Their contents are sorted and therefore quicker to locate

**Disadvantages:**
- Insertion of elements is slower than in sequential containers, as elements are sorted at insertion.
- In a vector, the element pointed to by an iterator can be overwritten by a new value. In case of a set, however, elements are sorted by the set class according to their respective values. **Overwriting an element
using an iterator should never be done, even if that were programmatically possible*.

#### 2. std::map and std::multimap
- `<map>` library
- map stores key-value pairs sorted on insertion by their unique keys in a container with logarithmic complexity
- multimap is akin to a map with the difference that the keys don’t need to be unique.
- To facilitate quick searching, STL implementations of the map and multimap internally look like binary trees
- elements in a map at a given position cannot be replaced by a new element of a different value
- The template instantiation needs that you specify the key type, the value type, and optionally a predicate that helps the map class to sort the elements on insertion. If you don't specify a predicate, the key type must have `operator<` implemented: it will use the default sort criterion provided by `std::less<>`, which essentially compares two objects using `operator<`

```c++
// instantiation - the third parameter is optional
std::map<keyType, valueType, Predicate=std::less<keyType>> mapObj;
std::multimap<keyType, valueType, Predicate=std::less<keyType>> mmapObj;
```

- inserting elements:
```c++
std::map<int, std::string> map1;

// with make_pair function
map1.insert(make_pair(-1, "Minus One"));

// with std::pair
map1.insert(pair<int, std::string>(1000, "One Thousand"));

// with array-like syntax
map1[1000000] = "One Million";

// with map<K, V>::value_type
map1.insert(map<int, string>::value_type(3, "Three"));
```

- the key is accessed through the attribute `first` and value through `second`:
```c++
std::map<int, std::string>::iterator it;
for (it = map1.begin(); it != map1.end(); ++it) {
	std::cout << it->first << ': ' << it->second << '\n';
}
```

- find a value given a key:
```c++
int key = 1000;
map<int, string>::const_iterator pairFound = map1.find(key);
if (pairFound != map1.end())
{
	std::cout << "Key " << pairFound->first << " points to Val" << pairFound->second << std::endl;
}
else
	std::cout << "Pair with key " << key << " not in map" << endl;
```

**Best practice:** Never use the result of a `find` operation directly without checking the iterator returned for success!!

- Erasing elements:
```c++
// with the key (for multimaps it returns the number of objects erased)
mapObject.erase(key);

// with an iterator that points to the element:
mapObject.erase(iterator);

// with a range of elements from a map or a multimap using iterators
mapObject.erase (lowerBoundIterator, upperBoundIterator);
```


**Advantages:**
- Search performance proportional to the logarithm of number of elements. Often significantly faster than sequential containers.

**Disadvantages:**
- Elements (pairs) are sorted on insertion, hence it will be slower than in a sequential container of pairs.

-----------------------------
### Containers adapters
- variants of sequential and associative containers that adapts another container and implements restriction on how elements are inserted, accessed or removed. They are intended to fulfill a particular purpose.

#### 1. std::stack
- `<stack>`
- LIFO (last-in-first-out) storage of elements
- elements can be inserted (pushed) and removed (popped) at the top of the container.
- You can visualized it as a stack of plates: the last plate added is going to be the first one taken off. Plates in the middle and at the bottom cannot be inspected.
- `std::deque` is the default container for the stack’s internal data storage and can be replaced by `std::vector` or the `std::list`

```c++
// Instantiation with default container std::deque
std::stack<int> numsInStack;

// Instantiation with a container other than the default
std::stack<double, vector<double>> doublesStackedInVec;

// Instantiation with copy constructor
std::stack<int> stackCopy(numsInStack);

// add an element in the top of the stack
numsInStack.push(25);

// access elements at the top
std::cout << numsInStack.top() << std::endl;

// remove topmost element
numsInStack.pop();

// check if stack is empty
numsInStack.empty();

// get stack size
numsInStack.size();
```

- `push_back` and `insert`, which are available with all STL sequential containers, used as underlying containers by the stack class, are not available as public member functions of the stack, as also iterators that help you peek at elements that are not at the top of the container. All that the stack exposes is the element at the top, nothing else.

#### 2. std::queue
- `<queue>`
- FIFO (first-in-first-out) storage of elements
- addition at the back but removal at the front: elements are inserted behind the previous one, and the one inserted first gets removed first
- You can think it as a queue of people waiting for something: those who join the queue earlier, leave earlier.
- A queue does not permit any access or inspection of elements at the middle; only elements at the beginning and the end can be accessed
- `std::deque` is the default container for the queue’s internal data storage and can be replaced by `std::vector` or the `std::list`
- Instantiation works the same as in stacks. Member functions are: `push`, `pop`, `front`, `back`, `empty` and `size`.

#### 3. std::priority_queue
- `<queue>`
- It stores elements in a sorted order, such that the one whose value is evaluated to be the highest is always first in the queue
- Member functions are: `push`, `pop`, `top`, `empty` and `size`.

-----------------------------
## STL String Classes
STL supplies a template class that has been specially designed for string operations: `std::basic_string<T>` which have two template specializations:
- std::string
- std::wstring

Why use them:
- Reduces the effort of string creation and manipulation
- Increases the stability of the application being programmed by internally managing memory allocation details
- Features copy constructor and assignment operators that automatically ensure that member strings get correctly copied
- Supplies useful utility functions
- Lets you focus efforts on your application’s primary requirements rather than on string manipulation details

-----------------------------
## STL Iterators
- template classes that in some ways are a generalization of pointers
- it helps to manipulate STL containers and perform operations on them

```c++
// iterator that points to an element in the list and doesn't modifying it
std::vector<int>::const_iterator it1;
// iterator to modify values or invoke non-const functions
std::vector<int>::iterator it2;

std::list<int> lst1;
lst1.push_back(1);
lst1.push_back(17);
lst1.push_back(42);
std::list<int>::const_iterator it;
std::list<int>::const_iterator ite = lst1.end();
for(it = lst1.begin(); it != ite; it++)
	std::cout << *it << std::endl;
```

**Best Practice:** use constant iterators as much as you can. You may deviate from it when you are certain about the need to modify the elements they point to.

##### Classification:
- InputIterator: guarantee read access. An Iterator that can be used in sequential input operations, where each value pointed by the iterator is read only once and then the iterator is incremented.
- OutputIterator: guarantee write access. It can be used in sequential output operations, where each element pointed by the iterator is written a value only once and then the iterator is incremented. Once dereferenced, its iterator value may no longer be dereferenceable.

##### Types:
- Forward iterator: it may allow read-only access or allow both read and write operations.
- Bidirectional iterator: A refinement of the forward iterator. It can be decremented to move backward as well.
- Random access iterators: iterators that can be used to access elements at an arbitrary offset position relative to the element they point to. They are the most complete iterators in terms of functionality. All pointer types are also valid random-access iterators.

All forward, bidirectional and random-access iterators are also valid input iterators.
All forward, bidirectional and random-access iterators that are not constant iterators are also valid output iterators.

-----------------------------
## Functors or Function objects
Function objects are instances of a class with member function `operator()` defined. This member function allows the object to be used with the same syntax as a function call.

**Types:**
- unary function: called with one argument. When it returns a `bool`, it is called a predicate.
```c++
// A unary function
template <typename T>
void FuncDisplayElement (const T& element) {
	std::cout << element << ' ';
};

// Struct that can behave as a unary function
// Remember that struct is akin to a class where members are public by default
template <typename T>
struct DisplayElement {
	void operator()(const T& element) const {
		std::cout << element << ' ';
	}
};
```
Either of these implementations can be used with the STL algorithm `for_each()`, for example. The real advantage of using a function object implemented in a struct is to be able to use the object of the struct to store information.

- binary function: called with two arguments. When it returns a `bool`, it is called a binary predicate.

Function objects that return a boolean type are naturally suited for use in algorithms that help in decision making, like `find()` and `sort()`.
A function object that combines two function objects is called an *adaptive function object*.

**std::less**

Binary function object class whose call returns whether the its first argument compares less than the second (as returned by operator <).
'
**std::greater**

Binary function object class whose call returns whether the its first argument compares greater than the second (as returned by operator >).

-----------------------------
## STL Algorithms
- template functions
- header `<algorithm>`

**STL algorithms work using iterators. Because neither the stack nor the queue class supplies iterators that mark the end of the ranges, the use of STL algorithms with these containers would not be possible.**

A reference to all STL algorithms: [<algorithm>](https://cplusplus.com/reference/algorithm/)

**Best Practices:**
- Use the container’s `erase` member method after using algorithms `remove`, `remove_if`, or `unique` to resize the container.
- Check the iterator returned by `find`, `find_if`, `search`, or `search_n` functions for validity before using it by comparing against the `end` of the container.
- Choose `stable_partition` over `partition` and `stable_sort` over `sort` only when the relative ordering of sorted elements is important as the stable_* versions can reduce the performance of the application.
- Sort a container using `sort` before calling `unique` to remove repeating adjacent values. It will ensure that all elements of a value are aligned adjacent to each other, making `unique` effective.
- Insert elements into a sorted container using positions returned by `lower_bound` or `upper_bound` to ensure that the sorted order of elements remains undisturbed instead of using randomly chosen positions.
- Use algorithms such as `binary_search` only in sorted containers. The use of this algorithm on an unsorted vector can have undesirable consequences
- The contents of an associative container should be treated as constants because they sort their elements on insertion, and the relative positions of the elements play an important role in functions such as `find` and also in the efficiency of the container. For this reason, mutating algorithms, such as `transform`, should not be used on STL sets and maps.


-----------------------------
## References

1. Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017
2. [STL Containers](https://cplusplus.com/reference/stl/)
3. [STL Iterators](https://cplusplus.com/reference/iterator/)
4. [algorithm library](https://cplusplus.com/reference/algorithm/)