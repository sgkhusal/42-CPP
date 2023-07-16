#include <iostream>
#include <iomanip>

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
Pair<int, double> pairIntDbl2;

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

// fool specialization
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
