#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

class IOperation;

void displayInt(int i) {
	std::cout << i << std::endl;
}

int main(void) {
	// container: list
	std::list<int> lst1;
	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);

	// iterators
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = lst1.end();
	for(it = lst1.begin(); it != ite; it++)
		std::cout << *it << std::endl;

	// container: map
	std::map<std::string, IOperation*> map1;;
	// map1["opA"] = new OperationA;
	// map1["opB"] = new OperationB;

	// container: vector
	std::vector<int> v1; // check what it does
	std::vector<int> v2(42, 100); // a vector with 42 spaces with 100 by default
	std::vector<int>::const_iterator vit;
	std::vector<int>::const_iterator vite = v1.end();
	std::cout << "v1: |";
	for(vit = v1.begin(); vit != vite; vit++)
		std::cout << *vit << " ";
	vite = v2.end();
	std::cout << "|\nv2: ";
	for(vit = v2.begin(); vit != vite; vit++)
		std::cout << *vit << " ";
	std::cout << "\n";

	// algorithms -> a collection of functions of algorithms
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	std::cout << "algorithms - for_each:\n";
	for_each(lst.begin(), lst.end(), displayInt);

	return 0;
}