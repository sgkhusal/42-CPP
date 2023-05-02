# Concepts

## Polymorphism

It allows objects of different types to be treated similarly.


## Sub-typing polymorphism & virtual functions

- A polymorphic behavior that can be implemented in C++ via the inheritance hierarchy
- a pointer to a derived class is type-compatible with a pointer to its base class:

```c++
class Character {};
class Warrior: public Character {};

...
int main(void){

    Warrior*    a = new Warrior();

    // A Character* can point to a 'Character' or 'Warrior'
    // i.e. anything that 'is-a' Character
    Character*  b = new Warrior(); // ok: Warrior is a Character

    // not ok: Warrior*    c = new Character();
    // A Warrior is a Character, but not all Character is necessarily a Warrior
}
```

### Static type - early binding
If Warrior (derived class) overrides a member function from Character (base class), in
```c++
Character*  b = new Warrior();
b.overridedFunction();
```
the `overridedFunction()` used will be the implementation from Character. The compiler doesn’t care if the object sent was a Warrior, handles it as a Character, and invokes Character::overridedFunction(). Compiler doesn't care about the address pointer is holding.

This is called **early binding**: it assumes the type is Character and so will invokes `overridedFunction()` from it.

You can see another example of such case bellow:

```c++
class Fish {
    public:
        void Swim(){
            cout << "Fish swims! " << endl;
        }
};

class Tuna: public Fish {
    public:
        // override Fish::Swim
        void Swim() {
            cout << "Tuna swims!" << endl;
        }
};

void MakeFishSwim(Fish& inputFish) {
    // calling Fish::Swim
    inputFish.Swim();
};


int main()
{
    Tuna myDinner;

    // calling Tuna::Swim
    myDinner.Swim();

    // sending Tuna as Fish
    MakeFishSwim(myDinner);

    return 0;
}
```

```
Output:
Tuna swims!
Fish swims!
```

`MakeFishSwim(Fish&)` doesn’t care if the object sent was a Tuna, handles it as a Fish, and invokes `Fish::Swim()`. The same object Tuna produced the output of a Fish not indicating any specialization thereof

What the user would ideally expect is that an object of type Tuna behaves like a tuna even if the method invoked is `Fish::Swim()`.

When an object of known type class Base can behave as its actual type Derived we have a polymorphic behavior that can be implemented by making `Fish::Swim()` a virtual function

### Dynamic type
Declaring the overrided function as `virtual` in base class will ensure that the `overridedFunction()` used will be from the derived class
```c++
virtual <returnType> overridedFunction(parameters);
```
Use of keyword `virtual` means that the compiler ensures that any overriding variant of the requested base class method is invoked.

This is usefull when you will know the sub-type of the object only during compilation time. Example: a user will choose it's character during the game: it could be a warrior, a witch, ...

- This is polymorphism: treating different characters as a common type Character, yet ensuring that the right implementation of `overridingFunction()` supplied by the derived types is executed.
- A class that declares or inherits a virtual function is called a polymorphic class.
- We use virtual functions when we want to give preference to address in pointer, i.e., when we compiler to think - this is called **late binding**

*DON’T confuse the function of keyword virtual when used in creating an inheritance hierarchy with the same when used in declaring base class functions.*

### Virtual Destructor

```c++
class Character {};
class Warrior: public Character {};

int main(void){
    Character*  b = new Warrior();
    ...
    delete b
}
```
```
// output:
Constructed Character
Constructed Warrior
...
Destroyed Character
```
The destructor also needs to be set as virtual in the base class. Otherwise we end up not destroying the derived class when we work with pointers as in the example above.

The virtual destructor on the base class will tell the compiler that it needs to call the destructor of the derived class (which calls the destructor of the base class afterwards)

**BEST PRACTICE:** *Always declare the base class destructor as virtual*

### Virtual Tables

- Any time we use the `virtual` keyword, a `virtual table` is created for every instance of the object at compile time (for base class and derived classes instances)
- When we call a member function, the virtual table points us to the correct member function
- For more information see: [VTable & VPointers - Virtual functions, Runtime Polymorphism](https://www.youtube.com/watch?v=47ZP-0iBicI) and [Understanding the vtable](https://www.youtube.com/watch?v=hS7kPtVB1vI)


## Abstract classes

- Classes that can only be used as base classes
- Have at least a virtual member function without definition (known as pure virtual function)
- The syntax of a function without definition: replace their definition by `= 0`

```c++
// Abstract class ACharacter
class ACharacter {
    private:
        std::sting      _name;
    public:
        // a pure virtual function
        virtual void    sayHello(std::string const& target) = 0;
}
```

Since it don't implements some methods, it can't be instanciated:

```c++
ACharacter* a = new Warrior(); // A Warrior is a Character
ACharacter* b = new ACharacter(); // results in compilation error
```

An abstract base class can be used to create pointers to it, and take advantage of all its polymorphic abilities

## Interface
- Doesn't implement methods (it has only pure virtual functions)
- Doesn't have attributes
- It is a way of establishing contracts with derived classes, indicating the behaviors needed to be implemented by them

## References
- Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017
- [Polymorphism](https://legacy.cplusplus.com/doc/tutorial/polymorphism/)
- [Virtual Function in C++](https://www.youtube.com/watch?v=SF8HbxDbNr0)
- [VTable & VPointers - Virtual functions, Runtime Polymorphism](https://www.youtube.com/watch?v=47ZP-0iBicI)
- [Understanding the vtable](https://www.youtube.com/watch?v=hS7kPtVB1vI)
- [Circular Dependencies in C++](https://pvigier.github.io/2018/02/09/dependency-graph.html)
