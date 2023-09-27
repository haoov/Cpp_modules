#include "Fixed.hpp"
#include "Fixed.h"

/*****************************************************************************/
/*                                                                           */
/*                        CONSTRUCTORS AND DESTRUCTOR                        */
/*                                                                           */
/*****************************************************************************/

Fixed::Fixed() {
	std::cout << "Deafault constructor called" << std::endl;

	this->setRawBits(0);
}

Fixed::Fixed(const int nb) {
	std::cout << "Integer constructor called" << std::endl;

	this->setRawBits(nb << Fixed::fractBitsNb);
}

Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;

	this->setRawBits(roundf(nb * myPow(2, Fixed::fractBitsNb)));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*****************************************************************************/
/*                                                                           */
/*                                  OPERATORS                                */
/*                                                                           */
/*****************************************************************************/

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignement operator called" << std::endl;

	this->rawBits = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return (out);
}

/*****************************************************************************/
/*                                                                           */
/*                              MEMBER FUNCTIONS                             */
/*                                                                           */
/*****************************************************************************/

int Fixed::getRawBits() const {
	std::cout << "getRawBits fucntion called" << std::endl;

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