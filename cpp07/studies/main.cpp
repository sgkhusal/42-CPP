#include <iostream>
#include "Vertex.tpp"

int main(void) {
    Vertex<int> v1(12, 23, 34);
    Vertex<>    v2(12, 23, 34);

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return 0;
}
