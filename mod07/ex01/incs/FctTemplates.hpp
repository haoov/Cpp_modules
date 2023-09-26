#ifndef FCTTEMPLATES_HPP
#define FCTTEMPLATES_HPP

#include <iostream>

template <typename A, typename L, typename F, typename P>
void iter(A *array, L len, F (*fct)(P)) {
	for (L i = 0; i < len; ++i) {
		fct(array[i]);
	}
}

template <typename T>
void print(T elem) {
	std::cout << elem << std::endl;
}

#endif