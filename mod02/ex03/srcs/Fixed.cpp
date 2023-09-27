#include "Fixed.hpp"
#include "Fixed.h"

/*****************************************************************************/
/*                                                                           */
/*                        CONSTRUCTORS AND DESTRUCTOR                        */
/*                                                                           */
/*****************************************************************************/

Fixed::Fixed() {
	this->setRawBits(0);
}

Fixed::Fixed(const int nb) {
	this->setRawBits(nb << Fixed::fractBitsNb);
}

Fixed::Fixed(const float nb) {
	this->setRawBits(roundf(nb * myPow(2, Fixed::fractBitsNb)));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::~Fixed() {}

/*****************************************************************************/
/*                                                                           */
/*                                  OPERATORS                                */
/*                                                                           */
/*****************************************************************************/

Fixed &Fixed::operator=(const Fixed &other) {
	this->rawBits = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &other) const {
	if (this->rawBits > other.getRawBits()) {
		return (true);
	}
	else {
		return (false);
	}
}

bool Fixed::operator<(const Fixed &other) const {
	if (this->rawBits < other.getRawBits()) {
		return (true);
	}
	else {
		return (false);
	}
}

bool Fixed::operator>=(const Fixed &other) const {
	if (this->rawBits >= other.getRawBits()) {
		return (true);
	}
	else {
		return (false);
	}
}

bool Fixed::operator<=(const Fixed &other) const {
	if (this->rawBits <= other.getRawBits()) {
		return (true);
	}
	else {
		return (false);
	}
}

bool Fixed::operator==(const Fixed &other) const {
	if (this->rawBits == other.getRawBits()) {
		return (true);
	}
	else {
		return (false);
	}
}

bool Fixed::operator!=(const Fixed &other) const {
	if (this->rawBits != other.getRawBits()) {
		return (true);
	}
	else {
		return (false);
	}
}

Fixed Fixed::operator+(const Fixed &other) {
	Fixed nb;
	nb.setRawBits(this->rawBits - other.getRawBits());
	return (nb);
}

Fixed Fixed::operator-(const Fixed &other) {
	Fixed nb;
	nb.setRawBits(this->rawBits - other.getRawBits());
	return (nb);
}

Fixed Fixed::operator*(const Fixed &other) {
	Fixed nb(this->toFloat() * other.toFloat());
	return (nb);
}

Fixed Fixed::operator/(const Fixed &other) {
	Fixed nb(this->toFloat() / other.toFloat());
	return (nb);
}

Fixed Fixed::operator++(int) {
	Fixed nb(*this);
	++(this->rawBits);
	return (nb);
}

Fixed &Fixed::operator++() {
	++(this->rawBits);
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed nb(*this);
	--(this->rawBits);
	return (nb);
}

Fixed &Fixed::operator--() {
	--(this->rawBits);
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                              MEMBER FUNCTIONS                             */
/*                                                                           */
/*****************************************************************************/

int Fixed::getRawBits() const {
	return (this->rawBits);
}

void Fixed::setRawBits(const int raw) {
	this->rawBits = raw;
}

float Fixed::toFloat() const {
	return (static_cast<float>(this->rawBits) / myPow(2, Fixed::fractBitsNb));
}

int Fixed::toInt() const {
	return (this->rawBits >> Fixed::fractBitsNb);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2) {
	if (obj1 > obj2) {
		return (obj1);
	}
	else {
		return (obj2);
	}
}

Fixed const &Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	if (obj1 > obj2) {
		return (obj1);
	}
	else {
		return (obj2);
	}
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2) {
	if (obj1 < obj2) {
		return (obj1);
	}
	else {
		return (obj2);
	}
}

Fixed const &Fixed::min(Fixed const &obj1, Fixed const &obj2) {
	if (obj1 < obj2) {
		return (obj1);
	}
	else {
		return (obj2);
	}
}