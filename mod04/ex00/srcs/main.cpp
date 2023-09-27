#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal *meta = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *cat2 = new WrongCat();

	std::cout << meta->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << meta2->getType() << std::endl;
	std::cout << cat2->getType() << std::endl;

	meta->makeSound();
	cat->makeSound();
	dog->makeSound();
	meta2->makeSound();
	cat2->makeSound();

	delete meta;
	delete cat;
	delete dog;
	delete cat2;
}