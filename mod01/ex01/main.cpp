#include "Zombie.h"
#include "Zombie.hpp"

int main() {
	int nb = 10;
	Zombie *horde = zombieHorde(nb, "Mike");
	for (int i = 0; i < nb; ++i) {
		horde[i].annouce();
	}
	delete[] horde;
	return 0;
}