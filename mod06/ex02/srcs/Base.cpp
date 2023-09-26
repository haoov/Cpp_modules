#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <cstdlib>
#include <iostream>

/*------------------------------------*/
/*    Constructors and destructot     */
/*------------------------------------*/

Base::~Base() {}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

Base *Base::generate() const {
	srand(time(NULL));
	int v = rand() % 3;
	switch (v) {
		case 0 :
			return (dynamic_cast<Base*>(new A()));
		case 1 :
			return (dynamic_cast<Base*>(new B()));
		case 2 :
			return (dynamic_cast<Base*>(new C()));
		default :
			break;
	}
	return (NULL);
}

void Base::identify(Base *p) const {
	A *a = dynamic_cast<A*>(p);
	if (a != NULL) {
		std::cout << a->type << std::endl;
	}
	B *b = dynamic_cast<B*>(p);
	if (b != NULL) {
		std::cout << b->type << std::endl;
	}
	C *c = dynamic_cast<C*>(p);
	if (c != NULL) {
		std::cout << c->type << std::endl;
	}
}

void Base::identify(Base &p) const {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << a.type << std::endl;
	}
	catch (std::exception &e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << b.type << std::endl;
	}
	catch (std::exception &e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << c.type << std::endl;
	}
	catch (std::exception &e) {}
}