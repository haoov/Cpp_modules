#include "../incs/Span.hpp"
#include <iostream>

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Span::Span(unsigned int N) : maxElems(N), nbElems(0), elems(NULL), last(NULL) {}

Span::Span(const Span &other) {
	*this = other;
}

Span::~Span() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

Span &Span::operator=(const Span &other) {}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void Span::addNumber(int val) {
	if (this->nbElems + 1 > this->maxElems) {
		throw Span::Full();
	}
	if (this->elems == NULL) {
		this->elems = new elem;
		this->elems->next = NULL;
		this->elems->val = val;
		this->last = this->elems;
	}
	else {
		elem *newElem = new elem;
		this->last->next = newElem;
		newElem->next = NULL;
		newElem->val = val;
		this->last = newElem;
	}
}