#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <iostream>

int main() {
	Base obj;
	Base *p;
	p = obj.generate();
	Base &pref = *p;
	obj.identify(p);
	obj.identify(pref);
}