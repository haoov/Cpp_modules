#include "MutantStack.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : stack(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

/*------------------------------------*/
/*              Operators             */
/*------------------------------------*/

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
	if (this != &other) {
		this->stack::operator=(other);
	}
	return (*this);
}

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}