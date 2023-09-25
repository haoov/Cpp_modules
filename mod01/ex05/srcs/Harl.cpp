#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() const {
	std::cout	<< "[DEBUG]" << std::endl;
}

void Harl::infos() const {
	std::cout << "[INFOS]" << std::endl;
}

void Harl::warning() const {
	std::cout << "[WARNING]" << std::endl;
}

void Harl::error() const {
	std::cout << "[ERROR]" << std::endl;
}

void Harl::complain(std::string level) const {
	std::string lvls[4] = {"DEBUG", "INFOS", "WARNING", "ERROR"};
	void (Harl::*fct[4])() const = {&Harl::debug, &Harl::infos, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; ++i) {
		if (level == lvls[i]) {
			(this->*fct[i])();
		}
	}
}