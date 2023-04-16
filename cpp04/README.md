# Concepts

## Polymorphism

### Sub-typing
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
the `overridedFunction()` used will be the implementation from Character.

#### Dynamic type
Declaring the overrided function as `virtual` in base class will ensure that the `overridedFunction()` used will be from the derived class
```c++
virtual <type> overridedFunction(parameters);
```
This is usefull when you will know the sub-type of the object only during compilation time. Example: a user will choose it's character during the game: it could be a warrior, a witch, ...

## Abstract classes

## Interfaces