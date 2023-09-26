#include "../incs/easyfind.hpp"

#include <vector>

int main() {
	std::vector<int> vec(4);
	int i;
	vec.at(3) = 2;
	try {
		i = easyfind(vec, 4);
	}
	catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
		return (-1);
	}
	std::cout << i << std::endl;
}