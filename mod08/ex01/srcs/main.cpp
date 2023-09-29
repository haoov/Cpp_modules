#include "../incs/Span.hpp"
#include <iostream>

int main() {
	int N = 10;
	Span testSpan(N);

	testSpan.addNumber(-18);
	testSpan.addNumber(-42);
	int array[4] = {-4, 5, -6, 7};
	testSpan.insert(array, array + 4);
	for (unsigned int i = 0; i < testSpan.size(); ++i) {
		std::cout << testSpan.at(i) << std::endl;
	}
	std::cout << "longest span is: " << testSpan.longestSpan() << std::endl;
	std::cout << "shortest span is: " << testSpan.shortestSpan() << std::endl;
	return (0);
}