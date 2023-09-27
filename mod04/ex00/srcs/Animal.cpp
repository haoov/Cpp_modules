#include "Animal.hpp"
#include <iostream>

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

Animal::Animal() : type("No type") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;

	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignement called" << std::endl;

	this->type = other.type;
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

void Animal::makeSound() const {
	std::cout << "No sound..." << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}