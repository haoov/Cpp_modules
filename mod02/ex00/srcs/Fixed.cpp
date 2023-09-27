#include "Fixed.hpp"

/*****************************************************************************/
/*                                                                           */
/*                        CONSTRUCTORS AND DESTRUCTOR                        */
/*                                                                           */
/*****************************************************************************/

Fixed::Fixed() {
	std::cout << "Constructor called" << std::endl;

	this->setRawBits(0);
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