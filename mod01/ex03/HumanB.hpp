#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public :
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack() const;
	private :
	std::string name;
	Weapon *weapon;
};

#endif //HUMANB_HPP