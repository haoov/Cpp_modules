#include "Point.hpp"

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(Fixed x, Fixed y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point &other) {
	*this = other;
}

Point::~Point() {}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

Point &Point::operator=(const Point &other) {
	this->x = other.getx();
	this->y = other.gety();
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

Fixed Point::getx() const {
	return (this->x);
}

Fixed Point::gety() const {
	return (this->y);
}

void Point::setx(Fixed x) {
	this->x = x;
}

void Point::sety(Fixed y) {
	this->y = y;
}
