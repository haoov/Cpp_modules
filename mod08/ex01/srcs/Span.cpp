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

Span::~Span() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

Span &Span::operator=(const Span &other) {
	for (unsigned int i = 0; i < other.size(); ++i) {
		this->addNumber(other.at(i));
	}
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
	std::vector<int>::const_iterator max = std::max_element(this->elems.begin(), this->elems.end());
	std::vector<int>::const_iterator min = std::min_element(this->elems.begin(), this->elems.end());
	return (static_cast<unsigned long>(std::abs(*max - *min)));
}

unsigned long Span::shortestSpan() const {
	std::vector<int> v;
	v.insert(v.begin(), this->elems.begin(), this->elems.end());
	std::sort(v.begin(), v.end());
	unsigned long minRange = __LONG_MAX__;
	for (size_t i = 0; i < v.size() - 1; ++i) {
		unsigned long currRange = static_cast<unsigned long>(std::abs(v.at(i + 1) - v.at(i)));
		if (currRange < minRange) {
			minRange = currRange;
		}
	}
	return (minRange);
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