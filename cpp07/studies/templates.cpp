#include <iostream>

template< typename T > // Template definition

T const& max(T const& x, T const& y) {
    return x >= y ? x : y;
}

int foo(int x) {
    std::cout << "Long computing time" << std::endl;
    return x;
}

template< typename T >
class List {
    public:
        List<T>(T const& content) {
            // ...
        }
        List<T>(List<T> const& list) {
            // ...
        }
        ~List<T>(void) {
            // ...
        }
    private:
        T*          _content;
        List<T>*    _next;
};

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
    std::cout << max<float>(c, d) << std::endl;  // Explicit instantiation
    std::cout << "Max of " << c << " and " << d << " is ";
    std::cout << max(c, d) << std::endl;  // Implicit instantiation

    char e = 'a';
    char f = 'z';

    std::cout << "Max of " << e << " and " << f << " is ";
    std::cout << max<char>(e, f) << std::endl;  // Explicit instantiation
    std::cout << "Max of " << e << " and " << f << " is ";
    std::cout << max(e, f) << std::endl;  // Implicit instantiation

    int ret = max<int>(foo(a), foo(b)); // Explicit instantiation
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << ret << std::endl;

    // ********************************************************************** //
    List<int>       g(42);
    List<float>     h(3.14f);
    List< List<int> > i(a);

    return 0;
}
