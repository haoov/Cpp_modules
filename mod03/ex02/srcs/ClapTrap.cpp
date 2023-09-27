#include "ClapTrap.hpp"
#include <iostream>

/*****************************************************************************/
/*                                                                           */
/*                        CONSTRUCTORS AND DESTRUCTOR                        */
/*                                                                           */
/*****************************************************************************/

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap name constructor called" << std::endl;

	this->name = name;
	this->energyPoints = 10;
	this->attackDamage = 0;
	this->hitPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;

	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

/*****************************************************************************/
/*                                                                           */
/*                           OVERLOADING OPERATOR                            */
/*                                                                           */
/*****************************************************************************/

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignement operator called" << std::endl;

	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

void ClapTrap::attack(const std::string &target) {
	if (this->energyPoints > 0) {
		std::cout << this->name << " attacks " << target << std::endl;
		--(this->energyPoints);
	}
	else {
		std::cout << this->name << " has no energy points left" << std::endl;
		return;
	}
}

void ClapTrap::takeDamage(int amount) {
	std::cout	<< this->name << " takes "<< amount << " points of damage" << std::endl;

	if (this->hitPoints - amount < 0) {
		std::cout << this->name << " died" << std::endl;
		this->hitPoints = 0;
	}
	else {
		this->hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(int amount) {
	if (this->hitPoints == 0) {
		std::cout << this->name << " is dead" << std::endl;
	}
	else {
		std::cout	<< this->name << " gains " << amount << " hit points" << std::endl;
		this->hitPoints += amount;
	}
}

std::string ClapTrap::getName() const {
	return (this->name);
}

int ClapTrap::getAttackDamage() const {
	return (this->attackDamage);
}