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
	int i = 0;
	while (lvls[i] != level) {
		++i;
	}
	switch (i) {
		case 0 :
			this->debug();
		case 1 :
			this->infos();
		case 2 :
			this->warning();
		case 3 :
			this->error();
			break;
		default :
			break;
	}
}