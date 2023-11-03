#include "../incs/ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2)
		return -1;
	ScalarConverter scalarConverter(argv[1]);
	std::cout << scalarConverter << std::endl;
	return 0;
}