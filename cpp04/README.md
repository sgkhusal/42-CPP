# Concepts

## Polymorphism

It allows objects of different types to be treated similarly.


### Sub-typing polymorphism

A polymorphic behavior that can be implemented in C++ via the inheritance hierarchy

```c++
class Character {};
class Warrior: public Character {};

...
int main(void){
    Warrior*    a = new Warrior();
    Character*  b = new Warrior(); // ok: Warrior is a Character
    // not ok: Warrior*    c = new Character();
    // A Warrior is a Character, but not all Character is necessarily a Warrior
}
```

#### Static type
If Warrior (derived class) overrides a member function from Character (base class), in
```c++
Character*  b = new Warrior();
b.overridedFunction();
```
the `overridedFunction()` used will be the implementation from Character. It doesn’t care if the object sent was a Warrior, handles it as a Character, and invokes Character::overridedFunction().

A similar behavior happens in this other example:

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

#### Dynamic type
Declaring the overrided function as `virtual` in base class will ensure that the `overridedFunction()` used will be from the derived class
```c++
virtual <returnType> overridedFunction(parameters);
```
Use of keyword virtual means that the compiler ensures that any overriding variant of the requested base class method is invoked.

This is usefull when you will know the sub-type of the object only during compilation time. Example: a user will choose it's character during the game: it could be a warrior, a witch, ...

This is polymorphism: treating different characters as a common type Character, yet ensuring that the right implementation of `overridingFunction()` supplied by the derived types is executed.


## Abstract classes

## Interfaces

## References
- Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017
