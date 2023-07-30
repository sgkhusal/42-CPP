# Templates

- The template is like a recipe.
- With templates we can create a function that would adapt itself to suit parameters of different types or define a behavior that you can apply to objects of varying types. It is almost close to what macros let you do, but **macros are type unsafe** while **templates are type safe**.

Example:
```c++
template< typename T > // Template definition
T const& max(T const& x, T const& y) {
    return x >= y ? x : y;
}

int foo(int x) {
    std::cout << "Long computing time" << std::endl;
    return x;
}

int main(void) {
    int a = 21;
    int b = 42;
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << max<int>(a, b) << std::endl;  // Explicit instantiation
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << max(a, b) << std::endl;  // Implicit instantiation

    float c = -1.7f;
    float d = 4.2f;
    std::cout << "Max of " << c << " and " << d << " is ";
    std::cout << max(c, d) << std::endl;  // Implicit instantiation

    char e = 'a';
    char f = 'z';
    std::cout << "Max of " << e << " and " << f << " is ";
    std::cout << max(e, f) << std::endl;  // Implicit instantiation

    int ret = max<int>(foo(a), foo(b)); // Explicit instantiation
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << ret << std::endl;

    return 0;
}
```

- We need to ask for the compiler to instantiate the template: the type of the variable value is T, and that is assigned at the time the template is used (= instantiated).
- Template functions don’t necessarily need an accompanying type specifier. Compilers are intelligent enough to understand that the template function is being invoked for each type. **With template classes, however, you need to explicitly specify type.**
- Template classes can be instantiated with types other than simple ones like `int` or classes supplied by the standard library. You may instantiate a template using a class defined by you.
- A template class you define but don’t consume is code that is simply ignored. In the case of template classes, instantiation is the act or process of creating a specific type using one or more template arguments.

```c++
template < typename T, typename U >
class Pair {
    public:
        Pair< T, U >( T const& lhs, U const& rhs): _lhs(lhs), _rhs(rhs) {
            std::cout << "Generic template" << std::endl;
            return ;
        }
        ~Pair< T, U >(void) {}

        T const& fst(void) const { return this->_lhs; }
        U const& snd(void) const { return this->_rhs; }
    private:
        T const& _lhs;
        U const& _rhs;

        Pair< T, U >(void);
};

// instantiate the template class for int, double
Pair<int, double> pairIntDbl;
```
- static member is shared across all objects of a template class with the same template instantiation. For example, you can visualize it as the compiler creating two versions of the static member variable X in a template class: X_int for template instantiation as `int` and X_double for template instantiations as `double`.
- The template can have multiple parameters separated by a comma.

## Templates vs Macros

- The macro functions get expanded inline before compilation and hence the performance of a simple macro is superior to that of an ordinary function
call doing the same task. This is because the function call requires the creation of a call stack, passing arguments, and so on—administrative overload that often takes more CPU time than the calculation of MAX, for example.
- Macro functions are often used for such very simple calculations. They provide the advantage of normal function calls in that these are expanded inline before compilations and hence can help improve code performance in certain cases

Problems with macros:
- macros are not type sensitive and macro functions can therefore cause problems
- you don’t have much control on a macro defined constant, for example:
```c++
#define PI 3.1416
```
PI: was it a double or a float? The answer is neither. To the preprocessor, was just a text substitution element “3.1416”. It never was a defined data type. **Constants are better defined using the const keyword with data types instead**.

- debugging a complicated macro is not easy either

**If you need the ability to program generic functions that are type independent, yet type safe, you program a template function instead of a macro function.**

### Best practices:
- program your own macro functions as infrequently as possibly.
- use const variables where you can instead of macros.
- remember that macros are not type safe and the preprocessor performs no type checking.


## Templates with Default Parameters
```c++
template< typename T = float >  // default type for T is float
class Vertex {
	// ...
};
```

## Specialization

There may be situations that require you to explicitly define a (different) behavior of a template when instantiated with a specific type. This is where you specialize a template (or behavior thereof) for that type

- Important: code that specializes a template must follow the template definition

Examples of specialization for template `Pair` above:

```c++
// specialization, for T = int
template < typename U >
class Pair< int, U > {
    public:
        Pair< int, U >( int const& lhs, U const& rhs): _lhs(lhs), _rhs(rhs) {
            std::cout << "Int partial specialization" << std::endl;
            return ;
        }
        ~Pair< int, U >(void) {}

        int const& fst(void) const { return this->_lhs; }
        U const& snd(void) const { return this->_rhs; }
    private:
        int const& _lhs;
        U const& _rhs;

        Pair< int, U >(void);
};

// bool specialization
template <>
class Pair< bool, bool > {
    public:
        Pair< bool, bool >( bool const& lhs, bool const& rhs) {
            std::cout << "Bool/bool specialization" << std::endl;
            this->_n = 0;
            this->_n |= static_cast<int>(lhs) << 0;
            this->_n |= static_cast<int>(rhs) << 1;
            return ;
        }
        ~Pair< bool, bool >(void) {}

        bool fst(void) const { return (this->_n & 0x01); }
        bool snd(void) const { return (this->_n & 0x02); }
    private:
        int _n;

        Pair< bool, bool >(void);
};

template< typename T, typename U >
std::ostream& operator<<(std::ostream& o, Pair< T, U > const& p) {
    o << "Pair(" << p.fst() << ", " << p.snd() << ")";
    return o;
}

std::ostream& operator<<(std::ostream& o, Pair< bool, bool > const& p) {
    o << std::boolalpha << "Pair(" << p.fst() << ", " << p.snd() << ")";
    return o;
}
```

## Subscript Operator ([])
The operator that allow array-style [] access to a class.

Syntax:
```c++
/*const*/ return_type& operator[](subscript_type& subscript) /*const*/;
```

Example:
```c++
class MyString
{
	private:
		char* buffer;

	public:
		// ...
		const char& operator[] (int index) const
		{
			if (index < GetLength())
			return buffer[index];
		}
};
```
The example above restricted the return value of subscript operator [] to `const char&`. The program will work and compile even without the `const` keywords. By using `const` you are protecting internal member `MyString::buffer` from direct modifications via operator []. It even have restricted the operator function type to `const` to ensure that it cannot modify the class’s member attributes.

You can implement two subscript operators: one as a const function and the other as a non-const one:
```c++
char& operator[](int index); // use to write / change buffer at index
char& operator[](int index) const; // used only for accessing char at index
```

## References

1. Sams Teach Yourself C++ in one Hour a Day - Siddhartha Rao - 2017
2. [42 School Piscine C++ videos](https://elearning.intra.42.fr/notions/piscine-c-d07-templates/subnotions)
3. [C++ new int[0]](https://stackoverflow.com/questions/1087042/c-new-int0-will-it-allocate-memory)
4. [How to initialise memory with new operator in C++](https://stackoverflow.com/questions/2204176/how-to-initialise-memory-with-new-operator-in-c)

