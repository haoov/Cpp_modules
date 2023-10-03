#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

	public :

		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &other);

		std::string getIdea(int) const;
		void setIdea(int, std::string);

	protected :

	private :

		std::string ideas[100];

};

#endif