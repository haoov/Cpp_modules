#include "../incs/MateriaSource.hpp"
#include "../incs/Character.hpp"
#include "../incs/Ice.hpp"
#include "../incs/Cure.hpp"

int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("Greg");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
delete tmp;
Character *other = new Character("Steve");
*other = *dynamic_cast<Character*>(me);
ICharacter* bob = new Character("bob");
other->use(0, *bob);
other->use(1, *bob);
AMateria *store = static_cast<Character*>(other)->getMateria(0);
other->unequip(0);
if (store != NULL) {
	delete store;
}
delete other;
delete bob;
delete me;
delete src;
return 0;
}