# Concepts

## Object Oriented Programming

### Class vs Struct
A `class` is a data structure, like a `struct`, but it also can have functions inside. The variables are called attributes, and the functions are called methods.
<br><b>Hint:</b> To access the attributes from a class inside its functions, you can use `this->var` that shows that it is a class attribute and not a function variable

### Class and instance
- The object is an instance of the class
- The object is like the variable and the class, the type

### Constructor
Called every time an instance is created.

### Destructor
Called every time the function where the object is instanciated finish 
```c++
class Sample{
    public:
        Sample(); // Constructor
        ~Sample(); // Destructor
}
```

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
- <b>public:</b> the attribute/method can be accessed inside and outside the class
- <b>private:</b> the attribute/method can be only accessed inside the class
- <b>protected:</b> (next chapters)

<b>Best practice 1:</b> Leave as public only what is necessary for the user. It helps to isolate parts of the code - encapsulation. <b>*** Always make sure when designing a class to think about what you should keep internal and what you should expose outside ***</b>
<br><b>Best practice 2:</b> name private attributes and methods beggining with an underscore indicates that it is a private variable/function. 
```c++
class Sample {
    public:
        int     publicAttribute;
        void    publicMethod(void);
    private:
        int     _privateAttribute;
        void    _privateMethod(void);
}
```

## initialization lists

```c++
class Sample {
    public:
        Sample(char p1, int p2, float p3);
        ~Sample(void);
        char    a1;
        int     a2;
        float   a3;
}

// Constructor using a initialization list
Sample::Sample(char p1, int p2, float p3): a1(p1), a2(p2), a3(p3) {
    //...
};

// or:
Sample::Sample(char p1, int p2, float p3) {
    this->a1 = p1;
    this->a2 = p2;
    this->a3 = p3;
}
```
<b>*Prefer to use the initialization list</b>

## const
- const variables needs to be initialized in the beggining of the code. For const class attributes, we use the initialization list (its not an attribution, but an initialization of the variable, which is different)
- const functions in class: it tells the compiler that the function will not going to alter some value of the instance (there is no attributions inside it). They are read-only

<b>Best Practice:</b> try to use as much `const` variables and functions as possible. As the programs get bigger, it helps to ensure the consistency of the program. <b>*** The more your code is const and read-only, the more it will be robust in the long term ***</b>

## accessors - getters and setters
In practice, all attributes from a class should be private. To access it, we use getters (read) and setters (write) which are interfaces between the user and the private attribute
<br><b>Best practice:</b> use the getters as `const` to guarantee that it is read-only and doesn't change anything
<br><b>Best practice:</b> use the setters to validate the value

## comparisons `==`
- If you have 2 instances with the same values in their attributes, the comparasion will return false - it is an address comparasion
- We can implement a class method that verify if 2 different instances of the class are equals in terms of values

## member attributes and member functions 
- Belong to the instances: each class instance will have a separate chunck of memory for their own attributes and functions. The attributes values can be different for each instance
- Accessed with the operator `this->memberVar`
- They can only be accessed when we instanciate the class

## static - non member attributes and non member functions
- Belong to the class: they are the same for every instance.
- Accessed in the scope of the class: `ClassName::nonMemberVar` or `ClassName::nonMemberFunction()`
- To declare non-member attributes or functions, we use the `static` before each declaration

## pointer to member accessors

```c++
class Sample{
    public:
        Sample(void);
        ~Sample(void);
        int     foo; // member attribute
        void    bar(void) const; // const member method
}

int main(void){
    // a pointer to a class instance
    Sample instance;
    Sample *instancePointer = &instance;

    // a pointer to a member attribute in Sample class
    int Sample::*p = NULL; // a pointer to a integer member of Sample class
    p = &Sample::foo;
    // doesn't work: p = &instance.foo (p should be of type int * - it is of type int Sample::*)
    
    instance.*p = 21;
    std::cout << instance.foo << std::endl;
    instancePointer->*p = 42;
    std::cout << instance.foo << std::endl;

    // a pointer to a member function in Sample class:
    void (Sample::*f)(void) const;
    f = &Sample::bar;
    (instance.*f)();
    (instancePointer->*f)();

    return 0;
}
```

## Exercises

- [std::string](https://legacy.cplusplus.com/reference/cctype/toupper/?kw=toupper)
- [std::getline](https://legacy.cplusplus.com/reference/string/string/getline/?kw=getline)
```c++
std::string s;
int         i;
std::cin >> s; // reads a single word from std::cin
std::cin >> i; // reads a single number from std::cin
std::getline(std::cin, s); // reads an entire line (up to \n) from std::cin
```

- [std::cin.ignore()](https://legacy.cplusplus.com/reference/istream/istream/ignore/): Usefull if used inside of a loop before readind a line (to ignore a new line character)

```c++
std::cin.ignore(100); // ignores the next 100 characters of std::cin
std::cin.ignore(); // equals to std::cin.ignore(1);
```
- [std::cin.fail()](https://cplusplus.com/reference/ios/ios/fail/): to check if happened a fail during the reading process
- [std::cin.clear()](https://cplusplus.com/reference/ios/ios/clear/): clears the error flag on `cin` to future I/O operations works properly

- [std::localtime](https://cplusplus.com/reference/ctime/localtime/)
