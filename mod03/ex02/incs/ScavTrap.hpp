#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {

	public :
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &other);

		void guardGate();

	private :
	
		bool gateKeeper;
};

#endif