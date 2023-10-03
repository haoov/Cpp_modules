#include "Dog.hpp"
#include <iostream>

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;

	this->brain = new Brain();
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;

	this->brain = new Brain();
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;

	delete this->brain;
}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

Dog &Dog::operator=(const Dog &other) {
	*(this->brain) = *(other.brain);
	return (*this);
}

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

std::string Dog::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return (this->brain->getIdea(index));
	}
	else {
		return (NULL);
	}
}

void Dog::setIdea(int index, std::string idea) {
	this->brain->setIdea(index, idea);
}