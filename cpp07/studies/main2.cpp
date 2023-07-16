#include <iostream>
#include "Pair.tpp"

int main(void) {
    Pair< int, int > p1(4, 2);
    Pair< std::string, float > p2("Pi", 3.14f);
    Pair< float, bool > p3(4.2f, true);
    Pair< bool, bool > p4(true, false);

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;

    Pair pairIntDbl (300, 10.09); // Pair types not explicit
    // instantiate the template class for int, double

    return 0;
}
