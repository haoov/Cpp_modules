#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <stdint.h>
#include "Data.hpp"

class Serialize {
	public :
		Serialize();
		Serialize(const Serialize &);
		~Serialize();

		Serialize &operator=(const Serialize &);

		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);
	protected :

	private :
};

#endif