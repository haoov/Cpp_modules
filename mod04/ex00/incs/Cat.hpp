#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public :

		Cat();
		~Cat();

		void makeSound() const;
		std::string getType() const;

	protected :

	private :

};

#endif