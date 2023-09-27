#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	public :

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string &target);
		void takeDamage(int amount);
		void beRepaired(int amount);
		std::string getName() const;
		int getAttackDamage() const;

	private :

		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;

};

#endif