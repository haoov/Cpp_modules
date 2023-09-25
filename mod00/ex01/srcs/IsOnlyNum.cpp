#include "PhoneBook.h"

bool IsOnlyNum(const std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (str.at(i) < '0' || str.at(i) > '9') {
			return (false);
		}
	}
	return (true);
}