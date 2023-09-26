#include "../incs/ScalarConverter.hpp"

int main() {
	ScalarConverter conv;
	conv.convert("13534365439436334987643457477457444444444444444444444444444");
	conv.printChar(std::cout);
	conv.printInt(std::cout);
	conv.printFloat(std::cout);
	conv.printDouble(std::cout);
}