#include "Zombie.h"
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << this->name << ": aaaarrrrrgh" << std::endl;
}

void Zombie::annouce() const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}