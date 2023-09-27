#include "Character.hpp"

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

Character::Character(const std::string name) {
	for (int i = 0; i < Character::inventorySize; ++i) {
		this->inventory[i] = NULL;
	}
	this->freeSlots = Character::inventorySize;
	this->name = name;
}

Character::~Character() {}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

Character &Character::operator=(const Character &other) {
	for (int i = 0; i < Character::inventorySize; ++i) {
		delete this->inventory[i];
		this->inventory[i] = other.inventory[i];
	}
	this->freeSlots = other.freeSlots;
	this->name = other.name;
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

const std::string &Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria *m) {
	if (this->freeSlots) {
		int i = 0;
		while (i < Character::inventorySize && this->inventory[i] != NULL) {
			++i;
		}
		this->inventory[i] = m;
		--(this->freeSlots);
		std::cout << this->name << " equip " << m->getType() << " in slot " << i << std::endl;
	}
}

void Character::unequip(int idx) {
	if (this->inventory[idx] != NULL) {
		this->inventory[idx] = NULL;
		++(this->freeSlots);
		std::cout << this->name << " unequip materia in slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter &target) {
	std::cout << this->name << " ";
	if (this->inventory[idx] != NULL) {
		this->inventory[idx]->use(target);
	}
}