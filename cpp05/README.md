# Concepts

## Exceptions

- extraordinary situations that disrupt the flow of your program
- no two computers, even with the same hardware configuration, are alike: the software running on each computer and the state the machine is in decide the amount of resources that are available at a particular time. Eg: memory allocation that worked perfectly in your environment can fail in another environment.
- Exceptions can be caused by external factors, such as a system with insufficient resources, or by factors internal to your application, such as a divide-by-zero error.
- Some modules are designed to communicate errors by throwing exceptions to the caller.
- To protect your code against exceptions, you “handle” exceptions thereby making your code “exception safe.”


### Handling Exceptions
- we can handle exceptions and display a friendly error message to the user, perform any minimal rescue operation if needed, and exit the program if necessary

```c++
try {
    // some code that can throw an exception
}
// we handle the error in the catch block
catch (const char* e) {  // catch exceptions of type const char*
    std::cout << "Excpetion: " << e << std::endl;
}
catch (const std::exception& e) {  // catch exceptions of type std::exception&
    std::cout << "Excpetion: " << e.what() << std::endl;
}
catch (...) { // (...) // catch all kind of exceptions
    std::cout << "Some exception occurred" << std::endl;
}
```

- handle the exceptions types separately can supply a more precise reason for the abrupt ending of the application
- you can insert as many catch() blocks as you like, one after another, depending on the exceptions you expect and those that would help
- `catch(...)` catches all those exception types that have not been explicitly caught by other catch statements

**Good practice**: include the only the part of the code that you expect to throw in the `try {}` block. Exception handling can reduce the execution performance of your code


### Throwing Exceptions

All you need is the keyword throw:
```c++
void DoSomething() {
    if(something_unwanted)
        throw object;
}
```

The object can be a simple `char*`.


### Class std::exception

- Standard exception class
- Base class for standard exceptions
- header `<exception>`

All objects thrown by components of the standard library are derived from this class. Therefore, all standard exceptions can be caught by catching this type by reference

Some important exceptions derived from it:
- `bad_alloc`: thrown when a request for memory using `new` fails
- `bad_cast`: thrown by dynamic_cast when you try to cast a wrong type (a type that has no inheritance relation)
- `ios_base::failure`: thrown by the functions and methods in the iostream library


**virtual method `what()`**

It gives a more descriptive reason on the nature of the problem causing the exception
```c++
// the 'throw' below indicates to compiler that the function doesn't throw an exception. A very important and relevant restriction on a class that is used as an exception object!
// If a function ends with throw(int), it means that the function is expected to throw an exception of type int
class NewException: public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Describe the error here";
        }
};

void DoSomething() {
    if(something_unwanted)
        throw NewException();
}
```

### Best Practices
- Inherit your custom exception class (if any) from `std::exception`. You can throw an exception of whatever type you want. However, when inheriting from `std::exception` all existing exception handlers that `catch(const std::exception&)` and work for `bad_alloc`, `bad_cast` and the like will automatically scale up to catch your new exception class as well
- remember to catch exceptions of type `std::exception`
- throw exceptions but with discretion. They’re not a substitute for return values such as true or false
- don't throw exceptions from destructors
- don't insert any heavy logic or resource allocations inside a `catch()` block. You don’t want to be causing exceptions when you’re handling one
- don't take memory allocations for granted; code that does `new` should always be exception safe

### How Exception Handling Works

At each step in the stack unwinding procedure, the variables local to that function are destroyed in reverse sequence of their construction.


## References
- Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017
- [class std::exception](https://legacy.cplusplus.com/reference/exception/exception/)
- [Circular Dependencies in C++](https://pvigier.github.io/2018/02/09/dependency-graph.html)
