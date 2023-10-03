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

Character::Character(const Character &other) {
	*this = other;
}

Character::~Character() {
	for (int i = 0; i < this->inventorySize; ++i) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
		}
	}
}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

Character &Character::operator=(const Character &other) {
	std::cout << "Character assignment operator called" << std::endl;
	for (int i = 0; i < Character::inventorySize; ++i) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
		}
		if (other.getMateria(i) != NULL) {
			this->inventory[i] = other.getMateria(i)->clone();
		}
	}
	this->freeSlots = other.freeSlots;
	this->name = other.getName();
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
	else {
		std::cout << this->name << " inventory is full" << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < this->inventorySize && this->inventory[idx] != NULL) {
		this->inventory[idx] = NULL;
		++(this->freeSlots);
		std::cout << this->name << " unequip materia in slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter &target) {
	std::cout << this->name << " ";
	if (idx >= 0 && idx < this->inventorySize && this->inventory[idx] != NULL) {
		this->inventory[idx]->use(target);
	}
}

AMateria *Character::getMateria(int index) const {
	if (index >= 0 && index < this->inventorySize) {
		return (this->inventory[index]);
	}
	else {
		return (NULL);
	}
}