#include "Cat.hpp"
#include <iostream>

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;

	this->brain = new Brain();
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called" << std::endl;

	this->brain = new Brain();
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;

	delete this->brain;
}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

Cat &Cat::operator=(const Cat &other) {
	*(this->brain) = *(other.brain);
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

void Cat::makeSound() const {
	std::cout << "Miaaaawww" << std::endl;
}

std::string Cat::getType() const {
	return (this->type);
}

std::string Cat::getIdea(int index) const {
	return (this->brain->getIdea(index));
}

void Cat::setIdea(int index, std::string idea) {
	this->brain->setIdea(index, idea);
}