#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public :

		WrongCat();
		WrongCat(const WrongCat &);
		~WrongCat();

		WrongCat &operator=(const WrongCat &);

		void makeSound() const;
		std::string getType() const;

	protected :

	private :

};

#endif