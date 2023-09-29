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
	if (this->size() == this->maxElems) {
		throw Span::Full();
	}
	else {
		this->elems.push_back(val);
	}
}

int Span::at(int index) const {
	return (this->elems.at(index));
}

unsigned int Span::size() const {
	return (this->elems.size());
}

void Span::insert(int *first, int *last) {
	this->elems.insert(this->elems.end(), first, last);
}

unsigned long Span::longestSpan() const {
	int max = this->at(0);
	int min = max;
	for (unsigned int i = 1; i < this->size(); ++i) {
		if (this->at(i) > max) {
			max = this->at(i);
		}
		if (this->at(i) < min) {
			min = this->at(i);
		}
	}
	return (static_cast<unsigned long>(std::abs(max - min)));
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

const char *Span::noDistance::what() const throw() {
	return ("There is no distance to be found");
}