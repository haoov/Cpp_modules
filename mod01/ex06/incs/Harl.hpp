#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {

	public :

		Harl();
		~Harl();

		void complain(std::string level) const;

	private :

		void debug() const;
		void infos() const;
		void warning() const;
		void error() const;

};

#endif