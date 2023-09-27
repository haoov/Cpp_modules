#include "MateriaSource.hpp"

/*****************************************************************************/
/*                                                                           */
/*                       CONSTRUCTORS AND DESTRUCTOR                         */
/*                                                                           */
/*****************************************************************************/

MateriaSource::MateriaSource() {
	for (int i = 0; i < MateriaSource::maxMateria; ++i) {
		this->knownMateria[i] = NULL;
	}
	this->freeSlots = MateriaSource::maxMateria;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MateriaSource::maxMateria; ++i) {
		delete this->knownMateria[i];
	}
}

/*****************************************************************************/
/*                                                                           */
/*                          OVERLOADING OPERATORS                            */
/*                                                                           */
/*****************************************************************************/

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	for (int i = 0; i < MateriaSource::maxMateria; ++i) {
		delete this->knownMateria[i];
		this->knownMateria[i] = other.knownMateria[i];
	}
	this->freeSlots = other.freeSlots;
	return (*this);
}

/*****************************************************************************/
/*                                                                           */
/*                             MEMBER FUNCTIONS                              */
/*                                                                           */
/*****************************************************************************/

void MateriaSource::learnMateria(AMateria *materia) {
	if (this->freeSlots != 0) {
		int i = 0;
		while (i < MateriaSource::maxMateria && this->knownMateria[i] != NULL) {
			++i;
		}
		this->knownMateria[i] = materia;
		--(this->freeSlots);
		std::cout << "materia " << materia->getType() << " learned" << std::endl;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	int i = 0;
	while (i < MateriaSource::maxMateria) {
		if (this->knownMateria[i] != NULL && this->knownMateria[i]->getType() == type) {
			std::cout << "creating materia " << type << std::endl;
			return (this->knownMateria[i]->clone());
		}
		++i;
	}
	return (NULL);
}