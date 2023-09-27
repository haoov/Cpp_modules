#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	ClapTrap p1("player1");
	ScavTrap p2("player2");
	FragTrap p3("player3");
	DiamondTrap p4("player4");
	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttackDamage());
	p2.beRepaired(10);
	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttackDamage());
	p2.guardGate();
	p3.highFivesGuys();
	p4.whoAmI();
	p4.attack(p3.getName());
}