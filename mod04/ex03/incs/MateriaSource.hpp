#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {

	public :

		MateriaSource();
		MateriaSource(const MateriaSource &);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &);

		void learnMateria(AMateria *);
		AMateria *createMateria(const std::string &);

	protected :

	private :

		static const int maxMateria = 4;
		AMateria *knownMateria[MateriaSource::maxMateria];
		int freeSlots;

};

#endif