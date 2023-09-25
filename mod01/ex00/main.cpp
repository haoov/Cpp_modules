#include "Zombie.h"
#include "Zombie.hpp"

int main() {
	Zombie *garry = newZombie("Garry");
	garry->annouce();
	randomChump("Steve");
	Zombie john("John");
	john.annouce();
	delete(garry);
	return (0);
}