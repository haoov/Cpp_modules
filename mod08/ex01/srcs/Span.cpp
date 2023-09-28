#include "../incs/Span.hpp"
#include <iostream>
#include <algorithm>

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Span::Span(unsigned int N) : maxElems(N) {}

Span::Span(const Span &other) {
	*this = other;
}

Span::~Span() {
}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

Span &Span::operator=(const Span &other) {
	static_cast<void>(other);
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void Span::addNumber(int val) {
	this->elems.push_back(val);
}

/*------------------------------------*/
/*         Exception methods          */
/*------------------------------------*/

const char *Span::Full::what() const throw() {
	return ("Span is full");
}

const char *Span::outOfRange::what() const throw() {
	return ("Value is out of range");
}

void Span::insert(int first, int last) {
	std::for_each(&first, &last, Span::addNumber);
}