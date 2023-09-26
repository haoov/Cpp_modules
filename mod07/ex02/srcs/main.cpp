#include "../incs/Array.hpp"
#include <iostream>

int main() {
	int n = 5;
	Array<int> array(n);
	Array<int> other;
	std::cout << "original array" << std::endl;
	for (int i = 0; i < array.size(); ++i) {
		array[i] = i;
		std::cout << array[i] << std::endl;
	}
	Array<int> copy(array);
	std::cout << "copy const array" << std::endl;
	for (int i = 0; i < copy.size(); ++i) {
		std::cout << copy[i] << std::endl;
	}
	other = copy;
	std::cout << "assignment array" << std::endl;
	for (int i = 0; i < other.size(); ++i) {
		std::cout << other[i] << std::endl;
	}
	try {
		std::cout << array[-1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "out of bounds" << std::endl;
	}
}