#include "Fixed.hpp"
#include "Fixed.h"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p);

int main( void ) {
	Point a(0, 0), b(3, 0), c(0, 3), p(2, (float)0.5);
	if (bsp(a, b, c, p)) {
		std::cout << "Inside" << std::endl;
	}
	else {
		std::cout << "Outside" << std::endl;
	}
	return (0);
}