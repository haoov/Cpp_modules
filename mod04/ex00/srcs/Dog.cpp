#include "Dog.hpp"
#include <iostream>

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

void Dog::makeSound() const {
	std::cout << "Waf Waf" << std::endl;
}

std::string Dog::getType() const {
	return (this->type);
}