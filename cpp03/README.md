# Concepts

## Inheritance

Inheritance allows classes that are similar to derive from a base class that contains common attributes and implements common functionality, overriding this base functionality to implement behavior that makes each class unique

**DON’T create an inheritance hierarchy just to reuse a trivial function.**

<div align="center">
  <img width="659" alt="image" src="https://user-images.githubusercontent.com/75377067/232261245-9df0aa40-8b99-41f6-b51c-07059fc64d89.png">
  <h6>source: Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017</h6>
</div>

### Example

```c++
// base class
class Animal {
  public:
    // base class members that can be accessed by derived class and user
    Animal();
    ~Animal();
    Animal(std::string const& type); // overloaded constructor
  private:
    // base class members that only can be accessed by base class members
    // a derived class can't access them
  protected:
    // base class members that can be accessed by base class and derived classes (and friends)
};

// derived class with a public access-specifier: a Cat IS an Animal
class Cat: public Animal {
  public:
    Cat();
    ~Cat();
    Cat(std::string const& type); // see implementation below
 // derived class members
};

// Derived class constructor implementation
Cat::Cat(): Animal(){...};

// Passing parameters to the base class in initialization
Cat::Cat(std::string const& type): Animal(type) {...};
```

### Access-specifier
#### For class members in base class
- private: base class members that only can be accessed by base class members
- protected: base class members that can be accessed by base class and derived classes (and friends)
- public: base class members that can be accessed by derived class and users

**Best Practice:** *To ensure maximum security, if the derived classes don’t need to access a base class attribute, remember to mark the attribute private*

#### In class inheritance declaration
- public (most frequently used): a “derived class is a base class” - an “is-a” relationship. Example: A Cat is an Animal
- private or protected: a “derived class has a base class” - a “has-a” relationship. Example: A Car has a Motor

- Public inheritance means that classes deriving from the derived class have access to the public and protected members of the base class. An object of the derived class can be used to access public members of the base.

- Private inheritance of the base class means that all public members and attributes of the base class are inaccessible to anyone with an instance of the derived class. They can only be accessed by the derived class. Classes deriving from the derived class have no access to any member of the base class.

- Protected inheritance lets the derived class access all public and protected members of base class. An object of the derived class cannot be used to access public members of the base. Classes deriving from the derived class have access to the public and protected methods of the base class.

*The most restrictive access specifier takes dominance in the compiler’s calculation of whether one class should have access to a base class’s public or protected members.*

```c++
class Motor {...};
class Car: protected Motor {...};
class RaceCar: protected Car {...};
// the nature of the relationship between the classes Car and RaceCar plays no role in access to base Motor, 
// while the relationship between Car and Motor does. So, even if we change protected in 'class RaceCar: protected Car' 
// to public or to private, the fate of compilation of the program remains unchanged
```

**Best Practice:** *Use private or protected inheritance only when you have to. In most cases where private inheritance is used, such as that of the Car and the Motor, the base class could have as well been a member attribute of the class Car instead of being a super- class. By inheriting from class Motor, you have essentially restricted your Car to having only one motor, for no significant gain over having an instance of class Motor as a private member.
Cars have evolved, and hybrid cars, for instance, have a gas motor in addition to an electric one. Our inheritance hierarchy for class Car would prove to be a bottleneck in being compatible to such developments.*

### Initialization and destruction
- Base class objects are instantiated before the derived class so that member attributes contained in base class are ready for consumption when the derived class is instantiated and ensuring that member attributes are ready before the constructor works with them.
- The sequence of destruction is the opposite to that of construction: first de derived class destructor is called, and then the base class destructor.
- You can't have a derived class if the base class is not instantiated

### Derived Class Overriding Base Class’s Methods
When a class Derived implements the same functions with the same return values and signatures as in a class Base it inherits from

#### Invoking Overridden Methods of a Base Class
- `instance.BaseClass::overridenMethod()`

```c++
Cat johnny;
johnny.overridenMethod(); // invokes Cat::overridenMethod()
johnny.Animal::overridenMethod(); // invokes Animal::overridenMethod() using instance of Cat
```

**Best Practice:** *DON’T program derived class functions that hide those in the base class by having the same name but a different set of input parameters.*

## Multiple Inheritance

```c++
class Platypus: public Mammal, public Bird, public Reptile {...};
```

## References
- Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017