#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "PhoneBook.h"
#include "Contact.hpp"

class PhoneBook {
	public :
		PhoneBook();
		~PhoneBook();

		void Add();
		void Search();
		void View();

	private :
		int NbOfContacts;
		Contact ContactTab[8];
};

#endif