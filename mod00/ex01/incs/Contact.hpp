#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.h"

class Contact {
	public :
		Contact();
		~Contact();

		void	FillInfos();
		void	View() const;
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickname();

	private :
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;
};

#endif