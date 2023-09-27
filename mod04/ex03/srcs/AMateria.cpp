#include "AMateria.hpp"

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

AMateria::~AMateria() {}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

AMateria &AMateria::operator=(const AMateria &other) {
	this->type = other.type;
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

const std::string &AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter &target) {
	std::cout << "does nothing to " << target.getName() << std::endl;
}