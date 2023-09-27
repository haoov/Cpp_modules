#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap p1("player1");
	ScavTrap p2("player2");
	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttackDamage());
	p2.beRepaired(10);
	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttackDamage());
	p2.guardGate();
}