#include "PhoneBook.h"
#include <cstdlib>
#include <cstdio>

std::string	GetEntry(const std::string &msg) {
	std::string Entry;
	bool ValidEntry;
	do {
		std::cout << msg;
		std::getline(std::cin, Entry);
		bool Error = !std::cin.good();
		if (Error || Entry.empty()) {
			ValidEntry = false;
			if (Error) {
				std::cin.clear();
				clearerr(stdin);
				std::cout << std::endl << "Error please try again" << std::endl;
			}
			else {
				std::cout << "Empty field please try again" << std::endl;
			}
		}
		else {
			ValidEntry = true;
		}
	} while (!ValidEntry);
	return (Entry);
}