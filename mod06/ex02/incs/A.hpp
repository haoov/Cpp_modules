#ifndef A_HPP
#define A_HPP

#include "Base.hpp"
#include <iostream>

class A : public Base {
	public :
		A();
		~A();

		std::string type;
};

#endif