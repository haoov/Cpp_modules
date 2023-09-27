#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	Cat cat;
	Cat cat2;
	cat2 = cat;
	Animal *tab[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	for (int i = 0; i < 4; ++i) {
		delete tab[i];
	}
	return (0);
}