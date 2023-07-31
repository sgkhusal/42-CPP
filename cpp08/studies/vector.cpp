#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	// instantiate a vector object that holds 5 integers of default value
	vector <int> integers(5);
	cout << "Vector of integers was instantiated with " << endl;
	cout << "Size: " << integers.size();
	cout << ", Capacity: " << integers.capacity() << endl;

	// Inserting a 6th element in to the vector
	integers.push_back(6);

	cout << "After inserting an additional element... " << endl;
	cout << "Size: " << integers.size();
	cout << ", Capacity: " << integers.capacity() << endl;

	// Inserting more elements
	integers.push_back(7);
	integers.push_back(8);
	integers.push_back(9);
	integers.push_back(10);
	cout << "After inserting more elements... " << endl;
	cout << "Size: " << integers.size();
	cout << ", Capacity: " << integers.capacity() << endl;

	// Inserting another element
	integers.push_back(1);
	cout << "After inserting yet another element... " << endl;
	cout << "Size: " << integers.size();
	cout << ", Capacity: " << integers.capacity() << endl;

	return 0;
}