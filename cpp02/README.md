# Concepts

## Function overloading
Functions with the same name, but receiving different parameters

<br>

## Operator overloading
### Forms to write an arithmetic operation:
- the prefix/functional notation: +(1,1)
- the fix notation: 1 + 1
- the post fix notation: 1 1 +

A notation works similar to a member function

image.png

C++ incorporates the option to use standard operators to perform operations with classes in addition to with fundamental types

```c++
struct {
    string product;
    float  price;
} a, b, c;
a = b + c; // this will cause a compilation error, since we have not defined the behavior our class should have with addition operations
```
To overload an operator in order to use it with classes we declare operator functions, which are regular functions whose names are the `operator` keyword followed by the operator sign that we want to overload
```c++
return_type operator<sign>(parameters);
```

### Operators that can be overloaded

|   |   |   |   |   |   |   |    |    |    |    |    |    |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|:--:|:--:|:--:|
| + | - | * | / | = | < | > | += | -= | *= | /= | >> | << |
|<<=|>>=|== |!= |<= |>= | ++| -- |  % |  & | ^  | !  |\|  |
| ~ |&= |^= |\|=|&& |\|\||%=| [] | () | ,  |->* | -> |    |
|new|delete|new[]|delete[]|

The overload operator can be called either implicity using the operator, or explicity using the function name:
```c++
// both expressions are equivalent:
c = a + b;
c = a.operator+(b);
```

A class includes a default constructor and a copy constructor even if they are not declared, and also includes a default definition for the assignment operator (`=`) with the class itself as parameter.
<br>The behavior defined by default is to copy the whole content of the data members of the object passed as argument (the one at right side) to the one at the left side (a shallow copy)
<br>It is the only operator member function implemented by default, but it can be redefined

<br>
<b>*** The overload operators does not force its operation to bear a relation to the mathematical or usual meaning of the operator, althought it is recommended ***</b>

<br>

### The operations `a++` and `++a`
- `++a`: increments the value and returns `a``
- `a++`:
    - creates a copy of `a`
    - increments the value of `a`
    - returns the copy
 
### Reference
- [Overloading operators](https://legacy.cplusplus.com/doc/tutorial/templates/)

<br>

## Canonical form
It has:
- the default constructor
- the default destructor
- a copy constructor
- `=`operator overload

```c++
class Sample {
	public:
		Sample(void);
		~Sample(void);
		Sample(Sample const& src); // copy constructor
		Sample& operator=(Sample const& rhs); // = operator overload
};
```
Using `const` in the copy constructor declaration and in the `=`operator overload declaration ensures that they do not modify the source object being referred to

<br>

# Exercises
## Floating numbers
- accuracy: how close a measurment is to the true value
- precision: how much information you have about a quantity

Integer arithmetic have the property of complety accuracy:
- We have the integer "2", it is exactly 2. If we add 1 to it, we know we get exactly 3
- Whatever operations we do with integers, provided there is no overflow, we will always get a number that matches the correct answer bit-for-bit

<br>But integers lack precision: `5 ÷ 2 = 2` and `4 ÷ 2 = 2` when we work with integers. They are unable to keep track of the fractional part

<br>
Floating point numbers are the exact opposite of integers with respect to accuracy and precision: they never deliberately discard information representing the numbers, but they have poor accuracy. In many cases, there is literally no hope of a floating point number answer's matching the correct answer bit for bit.
<br>Not every fraction can be represented exactly in binary, whereas any integer can. It is more than likely that the computed result you need cannot be represented accurately by a finite floating point variable - you are going to be wrong by at least a little bit no matter what you do.

<br>

### Floating representation
Floating point representation vary from machine to machine. The most common is the TEE-754 standard:
- float: 4 bytes
- double: 8 bytes

<br>With 3 components:
- a sign bit
- an exponent given its order of magnitude
- a mantissa specifying the actual digits of the number

<br>

### Fixed point number representation

- binary point: the decimal point in a decimal system. It is a divider between the integer and the fractional parte of a number. It is equivalent to 10ˆ0 in the decimal system
- All digits (bits) to left and itself:  `2ˆ0, 2ˆ1, 2ˆ2, ...`
- All digits (bits) to right: `2ˆ-1, 2ˆ-2, 2ˆ-3, ...`

The sequence of bits for 53 and 26.5 is the same; the difference is the position of the binary point:

|    |2ˆ5|2ˆ4|2ˆ3|2ˆ2|2ˆ1|2ˆ0|Binary point|2ˆ-1|2ˆ-2|2ˆ-3|
|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:----------:|:--:|:--:|:--:|
|53  | 1 | 1 | 0 | 1 | 0 | 1 |     .      | 0  | 0  | 0  |
|26.5| 0 | 1 | 1 | 0 | 1 | 0 |     .      | 1  | 0  | 0  |

- Shifting an integer to the right (`>>` operator) by 1 bit position is equivalent to dividing the number by 2
- Shifting an integer to the left (`<<` operator) by 1 bit position is equivalent to multiply the number by 2

To define a fixed point type conceptually, all we need are two parameters:
1. width of the number representation
2. binary point position within the number

All arithmetics of fixed point numbers are the same as integer. We can simply reuse the type `int` to perform fixed point arithmetic

The position of binary point only matters in cases when we print it on screen or perform arithmetic with a different type (such as adding `int` to `fixed point number`)

<br>

### Fixed point number conversion to float
- n: take the number of bits that represents the fractional part
- divide the number by `2ˆn` or bitshift to the right the number n times: `number >> n`

<br>

### Float conversion to fixed point number
- n: take the number of bits that represents the fractional part
- multiply the number by `2ˆn` or bitshift the number to the left by n times: `number << n`

<br>

### Reference
- [Understanding and Using Floating Point Numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)
- [Introduction to Fixed Point Number Representation](https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html)