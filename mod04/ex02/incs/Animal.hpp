#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

	public :
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &other);

		virtual void makeSound() const = 0;
		virtual std::string getType() const;

		protected :
		
			std::string type;

	private :
		
};

#endif