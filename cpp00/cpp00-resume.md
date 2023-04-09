# Concepts

## Object Oriented Programming

### Class vs Struct
A `class` is a data structure, like a `struct`, but it also can have functions inside. The variables are called attributes, and the functions are called methods.

### Class and instance
- The object is an instance of the class
- The object is like the variable and the class, the type

### Constructor
Called every time an instance is created.

### Destructor
Called every time the function where the object is instanciated finish 


## namespaces
- Allow to group entities like classes, objects and functions under a name - even if they are in different files - help to improve organization
- This way thw global scope can be divided in "sub-scopes", each one with its own name
- We can have variables with the same name in different namespaces

Setting an alias for a namespace:
```c++
namespace Bar = namespaceWithAVeryBigName;
```
Accessing a variable from namespace `Bar`:
```c++
Bar::varName
```
### The scope resolution operator or scope operator `::`

- Used to access functions and variables within namespaces and classes and also to access global variables (`::globalVar`)
- It helps to know the scope of the function/variable

Ex:
```c++
std::cout << text_to_print << std::endl;
```

## stdio streams (I/O manipulations)

The `iostream` library is an objetc-oriented library that provides input and output functionality using streams
<br>A `stream` is an object that represents a device on which input and output operations are performed. It can be associated to physical source like a disk file, the keyboard, or the console

- `cout`: std character output
- `cin`: std character input
- `cerr`: std character output stream for errors
- `clog`: std character output stream for logging
- operators `<<` and `>>`: redirect the data transmission into/from a stream:
```c++
std::cout << "Text to print" // redirects the string to the std output
std::cin >> var // redirects the content in std input into the variable
``` 

## Visibility
- public: the attribute/method can be accessed inside and outside the class
- private: the attribute/method can be only accessed inside the class
- protected (next chapters)

<b>Best practice 1:</b> Leave as public only what is necessary for the user. It helps to isolate parts of the code - encapsulation
<br><b>Best practice 2:</b> name private attributes and methods beggining with an underscore indicates that it is a private variable/function. Ex: 
```c++
int     _privateAttribute;
void    _privateMethod(void);
```

## initialization lists



## const

## accessors - getters and setters

<b>Best practice:</b> Set the getters as `const`

## comparisons

## member attributes and member functions 

## static - non member attributes and non member functions

## pointer to member

## Exercises

- [td::string](https://legacy.cplusplus.com/reference/cctype/toupper/?kw=toupper)
- [std::getline](https://legacy.cplusplus.com/reference/string/string/getline/?kw=getline)
- [std::localtime](https://cplusplus.com/reference/ctime/localtime/)
