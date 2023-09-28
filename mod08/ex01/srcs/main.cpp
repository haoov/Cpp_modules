#include "../incs/Span.hpp"
#include <iostream>

int main() {
	Span testSpan(3);

	testSpan.addNumber(1);
	testSpan.addNumber(2);
	std::cout << testSpan.at(0) << std::endl;
	std::cout << testSpan.at(1) << std::endl;
	testSpan.addNumber(18);
	std::cout << testSpan.at(2) << std::endl;
	testSpan.addNumber(42);
	return (0);
}