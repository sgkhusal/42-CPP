#include <iostream>

int main(void) {
	int* a = new int();
	int* b = new int[0];
	int* c = new int[1];
	int* d = new int[1]();

	// ok: *a is initialized to 0
	std::cout << "a: " << *a << " | pointer: " << a << std::endl;
	// ko: valgrind: invalid read for *b
	std::cout << "b: " << *b << " | pointer: " << b << std::endl;
	// ko: valgrind: uninitialised value (*c)
	std::cout << "c: " << *c << " | pointer: " << c << std::endl;
	// ok: *d is initialized to 0
	std::cout << "d: " << *d << " | pointer: " << d << std::endl;

	delete a;
	delete[] b;
	delete[] c;
	delete[] d;
	return 0;
}
