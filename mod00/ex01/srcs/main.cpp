#include "PhoneBook.h"
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	PhoneBook PhoneBook;
	std::cout << "Welcome to my awesome PhoneBook !" << std::endl;
	PRINTCMDS();
	std::string Entry;
	do {
		Entry = GetEntry(">");
		if (Entry == "ADD") {
			PhoneBook.Add();
		}
		else if (Entry == "SEARCH") {
			PhoneBook.Search();
		}
		else if (Entry != "EXIT") {
			std::cout << Entry << " : invalid command" << std::endl;
			PRINTCMDS();
		}
	} while (Entry != "EXIT");
}