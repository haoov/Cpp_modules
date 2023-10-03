#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public :

		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);

		void makeSound() const;
		std::string getType() const;
		std::string getIdea(int) const;
		void setIdea(int, std::string);

	protected :

	private :

		Brain *brain;

};

#endif