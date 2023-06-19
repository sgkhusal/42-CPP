# Casting

- Casting is a conversion process wherein data can be changed from one type to another temporarily or permanently. It is a mechanism by which we can change the interpretation of an object by the compiler.
- It does not imply that the object itself changes — It simply changes the interpretation.
- All cast actions are conversions. Some of this conversions have different properties

## Why use casting?

In the real world, modules are programmed by a lot of different people and different environments have to work together. Compilers very often need to be instructed to interpret data in ways that make them compile and the application function correctly

In many situations, casts are legitimate requirements to solve important compatibility issues.

Today we have a split in the C++ programming community: a group that continued using C-style casts in their C++ applications, and another that religiously converted to casting keywords introduced by C++ compilers. It is important to know both types.


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


### Static cast

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

# References
- Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017
- [Type conversions](https://cplusplus.com/doc/tutorial/typecasting/)
- [C++ casting](https://cplusplus.com/articles/iG3hAqkS/)
- [C++ variables and types](https://cplusplus.com/doc/tutorial/variables/)
