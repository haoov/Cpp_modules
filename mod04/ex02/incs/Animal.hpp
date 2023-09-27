#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

	public :

		virtual ~Animal();

		Animal &operator=(const Animal &other);

		virtual void makeSound() const;
		virtual std::string getType() const;

	protected :

		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		std::string type;

	private :
		
};

#endif