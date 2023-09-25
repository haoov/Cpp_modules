#include "../incs/ScalarConverter.hpp"

int main() {
	ScalarConverter conv;
	conv.convert("24fd");
	conv.printChar(std::cout);
	conv.printInt(std::cout);
	conv.printFloat(std::cout);
	conv.printDouble(std::cout);
}