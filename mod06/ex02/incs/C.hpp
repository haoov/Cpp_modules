#ifndef C_HPP
#define C_HPP

#include "Base.hpp"
#include <iostream>

class C : public Base {
	public :
		C();
		~C();
		
		std::string type;
};

#endif