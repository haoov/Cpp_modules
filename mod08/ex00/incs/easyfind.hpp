#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>


template <typename T>
int &easyfind(T cont, int nb) {
	typename T::iterator i = std::find(cont.begin(), cont.end(), nb);
	if (i == cont.end() && *i != nb) {
		throw std::exception();
	}
	else {
		return (*i);
	}
}

#endif