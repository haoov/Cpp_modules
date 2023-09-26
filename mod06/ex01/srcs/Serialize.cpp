#include "../incs/Serialize.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Serialize::Serialize() {}

Serialize::Serialize(const Serialize &other) {
	*this = other;
}

Serialize::~Serialize() {}

/*------------------------------------*/
/*      Overloading operators         */
/*------------------------------------*/

Serialize &Serialize::operator=(const Serialize &other) {
	static_cast<void>(other);
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

uintptr_t Serialize::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}