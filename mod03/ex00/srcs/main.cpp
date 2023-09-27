#include "ClapTrap.hpp"

int main() {
	ClapTrap p1("player1"), p2("player2");
	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttackDamage());
	p2.beRepaired(5);
}