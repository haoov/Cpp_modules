#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

	public :

		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &other);

	protected :

	private :

		std::string ideas[100];

};

#endif