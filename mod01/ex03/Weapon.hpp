#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	public :
	Weapon(std::string type);
	Weapon(const Weapon &other);
	~Weapon();
	const std::string &getType();
	void setType(std::string type);
	private :
	std::string type;
};

#endif //WEAPON_HPP