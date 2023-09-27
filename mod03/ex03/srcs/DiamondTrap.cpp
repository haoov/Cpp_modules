#include "DiamondTrap.hpp"
#include <iostream>

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap name constructor called" << std::endl;

	this->name = name;
	this->ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = this->FragTrap::hitPoints;
	this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = this->FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name), ScavTrap(other.name), FragTrap(other.name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;

	*this = other;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap copy assignement operator called" << std::endl;

	this->ClapTrap::name = other.ClapTrap::name;
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

void DiamondTrap::whoAmI() const {
	std::cout << "My name is : " << this->name << std::endl;
	std::cout << "My name is also : " << this->ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}