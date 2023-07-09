# Casting

- Casting is a conversion process where data can be changed from one type to another temporarily or permanently. It is a mechanism by which we can change the interpretation of an object by the compiler.
- It does not imply that the object itself changes — It simply changes the interpretation.
- All cast actions are conversions. Some of this conversions have different properties

## Why use casting?

In the real world, modules are programmed by a lot of different people and different environments have to work together. Compilers very often need to be instructed to interpret data in ways that make them compile and the application function correctly

In many situations, casts are legitimate requirements to solve important compatibility issues.

Today we have a split in the C++ programming community: a group that continued using C-style casts in their C++ applications, and another that religiously converted to casting keywords introduced by C++ compilers. It is important to know both types.

**_Best Practice:_ You should avoid casting as far as possible, and when you do use it, you should know what happens behind the scenes!**


## Type conversions

Conversions are cast actions in which the bits are changed in order to have the same value or the correspondent value in the new type

C++ has two types of conversions:
1. **Implicit conversion:** Conversions are performed automatically by the compiler without the programmer's intervention when a value is copied to a compatible type.
2. **Explicit conversion:** Conversions are performed only when explicitly specified by the programmer.

<br>

- Conversions from/to bool consider false equivalent to zero (for numeric types) and to null pointer (for pointer types); true is equivalent to all other values and is converted to the equivalent of 1.
- **Promotion**: converting to int from some smaller integer type, or to double from float, or to double/float from int. It is guaranteed to produce the exact same value in the destination type.
- Other conversions between arithmetic types may not always be able to represent the same value exactly (e.g., a negative integer value converted to an unsigned type).
- If the conversion is from a floating-point type to an integer type, the value is truncated (the decimal part is removed). This may imply a loss of precision and the compiler can signal with a warning. This warning can be avoided with an **explicit conversion**.
- Many conversions, specially those that imply a different interpretation of the value, require an explicit conversion, known in C++ as **type-casting**

### C-Style cast
```c
int  a = 42;

// Data type promotion
double b = a; // Implicit conversion cast
double c = (double)a; // Explicit conversion cast

double d = a; // Implicit promotion
int  e = d; // Implicit demotion - Hazardous!
int  f = (int)d; // Explicit demotion -> Ok, you are in charge!
```

C compilation flag to prevent implicit cast with precision lost:
`-Wenum-conversion`


## Type Reinterpretation

- It is an identity conversion
- The bits don't change but a type reinterpretation takes place
- When reinterpreting from `float` to a `void*` type, we lost in precision, but we also have a more generic type
- This kind of casting can help to receive different types in a function (e.g. C thread functions used in [42 Philosophers project](https://github.com/sgkhusal/42-philosophers))
- It may imply in a change of value in case of **demotion**

```c
float a = 420.042f;
void* b = &a; // Implicit reinterpretation cast to a more generic type
void* c = (void*)&a; // Explicit reinterpretation cast to a more generic type

void* d = a; // Implicit promotion -> Ok
int* e = d; // Implicit demotion - Hazardous! It generates errors
int* f = (int*)d; // Explicit demotion -> Ok, I obey...

printf("%p, %f\n", &a, a);
printf("%p\n", b);
printf("%p\n", c);

printf("%p\n", d);
printf("%p, %d\n", e, *e);
printf("%p, %d\n", f, *f);
```

The result:
<br>
```shell
0x16bd131dc, 420.041992
0x16bd131dc
0x16bd131dc
0x16bd131dc
0x16bd131dc, 1137837408 # pointer is the same, but the value changes
0x16bd131dc, 1137837408 # pointer is the same, but the value changes
```

_**Best practice**_: Always do an **explicit demotion** instead of an **implicit demotion**. It also indicates that you know what you are doing


## Type Qualifier Reinterpretation
- It is a kind of type reinterpretation
- E.g.: `const`

```c
int   a = 42;
int const* b = &a; // Implicit type qualifier cast
int const* c = (int const*)&a; // Explicit type qualifier cast

int const* d = &a; // Implicit promotion: Ok
int*  e = d; // Implicit demotion - Hell, no! - compilation error
int*  f = (int*)d; // Explicit demotion -> Ok, I obey
```

_**Best practice**_: If the function doesn't modifies the variable, write it as `const` in the function prototype.


## Upcast and Downcast - C++

- **upcast:** ascending reinterpretation - from pointer-to-derived to pointer-to-base
- **downcast:** descending reinterpretation - from pointer-to-base to pointer-to-derived

<img width="806" alt="image" src="https://github.com/sgkhusal/42-CPP/assets/75377067/114d5c1f-dfac-4b6e-81c6-aa572c4c60c3">


Note: examples using C syntax for learning purposes
```c++
class Parent {};
class Child1: public Parent {};
class Child2: public Parent {};

int main(void) {
 Child1 a;
 Parent* b = &a; // Implicit "reinterpretation" cast
 Parent* c = (Parent*)&a; // Explicit "reinterpretation" cast

 // The Parent class is a "more generic" type, and the Child classes are "more specific" types
 Parent* d = &a; // Implicit upcast: Ok
 Child1* e = d; // Implicit downcast - Hell, no! - compilation error
 Child2* f = (Child2*)d; // Explicit downcast -> Ok, but, really?
 // Compiler allows but we can have errors during program execution because Child2 implementation can be different from that of Child1.
 // Remember, it is still an Child1 object.
 // Trying to access any Child2 attributes or methods that Child1 doesn't have will generate an error.
 // Also, all methods that both classes have will have the Child1 behavior

}
```

The C-style cast can be applied indiscriminately on classes and pointers to classes, which can lead to code that can cause runtime errors.

Unrestricted explicit type-casting allows to convert any pointer into any other pointer type, independently of the types they point to.

In order to control these types of conversions between classes, we have the casting operators.


## Casting operators

Operators that change the interpretation of an object are called casting operators.

C++ supplies a new casting operator specific to inheritance-based scenarios that did not exist with C programming.

The four C++ casting operators are:
- static_cast
- dynamic_cast
- reinterpret_cast
- const_cast

The usage syntax of the casting operators is consistent:
```c++
destination_type result = cast_operator<destination_type> (object_to_cast);
```


### static_cast

It allows us to make simple conversions - type conversions for standard data types that would otherwise happen automatically or implicitly. It will convert between built-in types, even when there is a loss of precision.:
```c++
int  a = 42;
double b = a; // Implicit promotion -> Ok
int  c = b; // Implicit demotion -> Hell, no!
int  d = static_cast<int>(d); // Explicit demotion -> Ok, I obey
```
It also allows us to make upcasts and downcasts (convert pointers between related types), and also prevents cast between unrelated class hierarquies:
```c++
class Parent {};
class Child1: public Parent {};
class Child2: public Parent {};
class Unrelated {};

int main(void) {
 Child1 a;
 Parent* b = &a; // Implicit upcast -> Ok
 Child1* c = b; // Implicit downcast -> Hell, no! - compilation error
 Child2* d = static_cast<Child2*>(b); // Explicit downcast -> Ok, I obey -> but it still can be a problem

 Unrelated* e = static_cast<Unrelated*>(&a); // Explicit conversion -> No! -> compilation error
}
```

It implements a basic compile-time check to ensure that the pointer is being cast to a related type.
<br>But no checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type (e.g., the explicit downcast example above). Therefore, it is up to the programmer to ensure that the conversion is safe.

The `static_cast` operator can also:
- Convert from `void*` to any pointer type. It guarantees that, if the `void*` value was obtained by converting from that same pointer type, the resulting pointer value is the same.
- Convert integers, floating-point values and enum types to enum types.
- Explicitly call a single-argument constructor or a conversion operator.
- Convert to rvalue references. #####################################
- Convert enum class values into integers or floating-point values.
- Convert any type to `void`, evaluating and discarding the value.

\* You would also need to use static_ cast when using conversion operators or constructors that have been declared using keyword `explicit`


### dynamic_cast

- `dynamic_cast` can only be used with pointers and references to classes (or with void*).
- It only works with polymorphic classes (those with virtual members).
- It includes pointer **upcast** (converting from pointer-to-derived to pointer-to-base), in the same way as allowed as an **implicit conversion**.
- It can also **downcast** (convert from pointer-to-base to pointer-to-derived) polymorphic classes  if - and only if - the pointed object is a valid complete object of the target type
- Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.
- Dynamic cast occurs at runtime. The other cast types happen during the compilation. For that reason, the program may compile and the dynamic cast can fail during runtime
- So, the return value of a `dynamic_cast` operation should always be checked for validity  and handle the failure properly. It is NULL when the cast fails.
- The `dynamic_cast` operator returns a valid address if the Base class pointer points to an instance of the Derived class for which you are making the downcast

#### Example 1:
```c++
class Parent { public: virtual ~Parent(void) {} };
class Child1: public Parent {};
class Child2: public Parent {};

int main(void) {
  Child1 a;
  Parent* b = &a; // Implicit upcast -> Ok

  // Explicit downcast with pointer
  Child1* c = dynamic_cast<Child1*>(b);
  if (c == NULL) {
    std::cout << "Conversion is NOT OK" << std::endl;
  }
  else {
    std::cout << "Conversion is OK" << std::endl;
  }

  // Explicit downcast with reference
  // a reference can't be NULL so we need to use a try-catch block
  try {
    Child2* d = dynamic_cast<Child2*>(b); // It will fail
    std::cout << "Conversion is OK" << std::endl;
  }
  catch (std::bad_cast& bc){
    std::cout << "Conversion is NOT OK: " << bc.what() << std::endl;
  }

  Parent* parentptr = new Parent;
  Child1* childptr = dynamic_cast<Child1*>(parentptr);
  if (childptr == NULL)
  	std::cout << "Conversion is NOT OK" << std::endl;
  // parentptr is pointing to an object of class Parent, which is an incomplete object of class Child1 and so the dynamic cast fails.


  return 0;
}
```

Result:
```
Conversion is OK
Conversion is NOT OK: std::bad_cast
Conversion is NOT OK
```

- We can use `dynamic_cast` given a base-class pointer type to detected the type and then perform operations specific to the types detected.
- `dynamic_cast` helps determine the type at runtime and use a casted pointer when it is safe to do so.
- The mechanism of identifying the type of the object at runtime is called **runtime type identification (RTTI)**
- `dynamic_cast` requires **runtime type identification (RTTI)** to keep track of dynamic types. Some compilers support this feature as an option which is disabled by default. This needs to be enabled for runtime type checking using `dynamic_cast` to work properly with these types. DON’T design your application around RTTI using `dynamic_cast`.
- When you are sure that the object being pointed to is Derived type that you are casting, you can save on runtime performance by using `static_cast` instead of `dynamic_cast`

#### Example 2 (from Sams Teach Yourself C++ in one Hour a Day):
```c++
class Fish {
public:
  virtual ~Fish() {}
  virtual void Swim() {
    std::cout << "Fish swims in water" << std::endl;
  }
};

class Tuna: public Fish 16: {
public:
  void Swim() { std::cout << "Tuna swims real fast in the sea" << std::endl; }
  void BecomeDinner() { std::cout << "Tuna became dinner in Sushi" << std::endl; }
};

class Carp: public Fish 30: {
public:
  void Swim() { std::cout << "Carp swims real slow in the lake" << std::endl; };
  void Talk() { std::cout << "Carp talked Carp!" << std::endl; }

};

void DetectFishType(Fish* objFish) 44: {
  Tuna* objTuna = dynamic_cast <Tuna*>(objFish);
  if (objTuna) {
    std::cout << "Detected Tuna. Making Tuna dinner: " << std::endl;
    objTuna->BecomeDinner(); }

  Carp* objCarp = dynamic_cast <Carp*>(objFish);
  if(objCarp) {
    std::cout << "Detected Carp. Making carp talk: " << std::endl;
    objCarp->Talk();
  }

  std::cout << "Verifying type using virtual Fish::Swim: " << std::endl; objFish->Swim(); // calling virtual function Swim
}

int main() 64: {
  Carp myLunch;
  Tuna myDinner;

  DetectFishType(&myDinner);
  std::cout << std::endl;
  DetectFishType(&myLunch);

  return 0;
}
```

Result:
```
Detected Tuna. Making Tuna dinner:
Tuna became dinner in Sushi
Verifying type using virtual Fish::Swim: Tuna swims real fast in the sea

Detected Carp. Making carp talk:
Carp talked Carp!
Verifying type using virtual Fish::Swim: Carp swims real slow in the lake
```

- `dynamic_cast` can also perform the other implicit casts allowed on pointers: casting null pointers between pointers types (even between unrelated classes), and casting any pointer of any type to a `void*` pointer.


### reinterpret_cast

- Allows to make reinterpretations and upcast and downcast as well
- All pointer conversions are allowed: it converts any pointer type to any other pointer type, even of unrelated classes.
- There is no semantic checks: neither the content pointed nor the pointer type itself is checked. The compiler trusts you and you are responsible for the consequences in runtime if mistakes were made.
- The operation result is a simple binary copy of the value from one pointer to the other.
- It is the closest a C++ casting operator gets to the C-style cast

```c++
float a = 420.042f;
void* b = &a; // Implicit promotion -> Ok

int* c = reinterpret_cast<int*>(b); // Explicit demotion -> Ok, I obey
int& d = reinterpret_cast<int&>(b); // Explicit demotion -> Ok, I obey
```

- It forces the compiler to accept situations that `static_cast` would normally not permit:
```c
class A { /* ... */ };
class B { /* ... */ };
A * a = new A;
B * b = reinterpret_cast<B*>(a);
// This code compiles, although it does not make much sense
```

- It finds usage in certain low-level applications where data needs to be converted to a simple type that an API can accept.
- Because no other C++ casting operator would allow such a conversion that compromises type safety, `reinterpret_cast` is a last resort in performing an otherwise **unsafe** (and nonportable) conversion.

_**Best Practice:**_ You should refrain from using `reinterpret_cast` in your applications


### const_cast

- It enables you to turn off the const access modifier to an object: it manipulates the constness of the object pointed by a pointer, either to be set or to be removed.
- Example: when you need to pass a const pointer to a function that expects a non-const argument to and the function is from a third-party library, and making changes to it is not possible
- **Point of attention:** using `const_cast` to modify a `const` object can result in undefined behavior

```c++
int   a = 42;

// const is a more "generic", higher type and int is a more "specific/accurate" one. Then, we can make a promotion with no problem
int const* b = &a; // Implicit promotion: Ok
int*  c = b; // Implicit demotion - Hell, no! - compilation error
int*  d = const_cast<int*>(b); // Explicit demotion -> Ok, I obey
```

_**Best Practice:**_ Using `const_cast` in your code is a very bad sign. It usually means your design is wrong and you will be better off recoding your code to avoid using it. Remember that you should keep as many `const` variables as possible to make your program easier to maintain and more stable through time. If you need to make some `const_cast` at some point, make sure you have a good reason (**laziness isn't a good reason!!**). Be aware of what you are doing. Also, using `const_cast` to invoke `non-const` functions should be a last resort. The example below is not a best practice. The `DisplayMembers` should be a `const` member function.

```c++
class SomeClass {
public:
  // ...
  void DisplayMembers(); //problem - display function isn't const
  // void DisplayMembers() const; // the right to do
};

void DisplayAllData (const SomeClass& object) {
	// object.DisplayMembers (); // Compile failure
	SomeClass& refData = const_cast<SomeClass&>(object);
	refData.DisplayMembers(); // Allowed but is not the best solution
}
```


## Type cast operators in classes

- It allows you to define in your classes specific operators in order to make implicit conversions of your class to a type that you are interested in

```c++
class Foo {
public:
  Foo(float const v): _v(v) { }

  float getV(void) { return this->_v; }

  // cast operators
  operator float() { return this->_v; }
  operator int() { return static_cast<int>(this->_v); }

private:
  float _v;
}

int main(void) {
  Foo a(420.042f);
  float b = a; // the compiler checks if there is an cast operator for float in the Foo class
  int c = a; // the compiler checks if there is an cast operator for int in the Foo class

  std::cout << a.getV() << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;

  return 0;
}
```

Result:
```
420.024
420.024
420
```

# explicit keyword

- the casting operators have a sintaxe similar to functions
- Constructors are similar to cast operators when we think about the written form and behavior (both return a new instance of the type specified). We may think about the constructor as a conversion from the input parameters to a specific type
- We may think in a constructor receiving an integer - is like a conversion of an integer to the constructor class type
- C++ allows systematic implicit cast of an expression, whatever it is in the code. So, implicit conversion is performed by calling a constructor with only one argument compatible with converted value

```c++
class A {};
class B {};

class C {
public:
           C((A const& _)) { return; }
  explicit C((B const& _)) { return; }
};

void f((C const& _)) {
  return;
}

int main(void) {
  f(A());  // Implicit conversion, OK
  f(B());  // Implicit conversion, NOT OK, constructor is explicit

  return 0;
}
```

_**Best Practice:**_ Use **explicit** keyword in constructors to prevent unwanted implicit casting when creating an object.
- The implicit conversion doesn't happen if the constructor has more then one parameter, so the **explicit** keyword has no effect in this constructors
- Allowing implicit casting can lead to behavior that the programmer might not expect to happen. Passing a 5 into a function that expects something other an an int can be confusing (example below)

```c++
class Bar {
  public:
    /*explicit*/ Bar(int a) {  }
};

void foo(Bar b) {}

int main(void) {
  foo(5); // error if constructor is explicit
  foo(Bar(5)); // works either way

  return 0;
}
```

Another example (from reference #5):
```c++
class String {
  public:
    String(const char* c_str): str(c_str) {}
    String(int n)
    {
        str.reserve(n);
    }

  private:
    std::string str;

    friend std::ostream& operator<<(std::ostream&, const String&);
};

// Operator overload to allow printing with cout << operator
std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.str;
}

void writeLine(String str) {
    std::cout << str << "\n";
}

int main() {
    writeLine(3); // it will make an implicit conversion and print nothing (3 in ASCII table is a non-printable character)
}
```

# C++ static class

A static class cannot be instantiated or inherited and all of the members of the class are static in nature. In C++ there is no such thing.

The closest approximation is a class **with private constructors and destructors** and that **only contains static data members and static methods**.

# References
1. Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017
2. [Type conversions](https://cplusplus.com/doc/tutorial/typecasting/)
3. [C++ casting](https://cplusplus.com/articles/iG3hAqkS/)
4. [C++ variables and types](https://cplusplus.com/doc/tutorial/variables/)
5. [when and why use explicit?](https://cplusplus.com/forum/general/234487/)

## Exercises references
6. [std::numeric_limits](https://legacy.cplusplus.com/reference/limits/numeric_limits/)
7. [about infinit](https://stackoverflow.com/questions/20016600/negative-infinity)
8. [Difference between float and double in C/C++](https://www.geeksforgeeks.org/difference-float-double-c-cpp/)
9. [String literal](https://en.cppreference.com/w/cpp/language/string_literal)
10. [Convert String to int in C++](https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/)
