#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	//Animal *a = new Animal();
	Cat *cat = new Cat();
	cat->setIdea(21, "super idea");
	Cat cat2;
	cat2 = *cat;
	delete cat;
	std::cout << std::endl;
	std::cout << cat2.getIdea(21) << std::endl << std::endl;
	Animal *tab[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	for (int i = 0; i < 4; ++i) {
		delete tab[i];
	}
	return (0);
}