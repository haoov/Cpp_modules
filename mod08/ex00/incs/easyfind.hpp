#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
int &easyfind(T cont, int nb) {
	typename T::iterator i = cont.begin();
	while (i != cont.end()) {
		if (*i == nb) {
			return (*i);
		}
		++i;
	}
	throw std::exception();
}

#endif