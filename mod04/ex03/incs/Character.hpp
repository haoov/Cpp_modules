#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {

	public :

		Character(const std::string name);
		~Character();

		Character &operator=(const Character &other);

		const std::string &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

	protected :

	private :

		static const int inventorySize = 4;
		AMateria *inventory[Character::inventorySize];
		int freeSlots;

};

#endif