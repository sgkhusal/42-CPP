#include <iostream>
#include <iomanip>

template< typename T = float >  // default type for T is float
class Vertex {
public:
    Vertex(T const& x, T const& y, T const& z): _x(x), _y(y), _z(z) {}
    ~Vertex(void) {}

    T const& getX(void) const { return this->_x; }
    T const& getY(void) const { return this->_y; }
    T const& getZ(void) const { return this->_z; }

private:
    T const _x;
    T const _y;
    T const _z;

    void vertex(void);
};

// a template function using the template class
template< typename T >
std::ostream& operator<<(std::ostream& o, Vertex<T> const& v) {
    std::cout << std::fixed;
    std::cout.precision(1);
    o << "Vertex(";
    o << v.getX() << ", ";
    o << v.getY() << ", ";
    o << v.getZ();
    o << ")";
    return o;
}
