#include "PhoneBook.h"

std::string Trunc10(const std::string &str) {
	if (str.length() > 10) {
		return (str.substr(0, 9) + ".");
	}
	else {
		return (str);
	}
}