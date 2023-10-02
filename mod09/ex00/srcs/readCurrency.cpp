#include <iostream>
#include "../incs/btc.hpp"
#include <cstdlib>
#include <limits>

std::map<std::string, float> readCurrency(const char *file) {
	std::ifstream ifs;
	std::string date;
	std::string currency;
	str_float_map date_currency;
	ifs.exceptions(ifs.badbit | ifs.failbit | ifs.eofbit);
	ifs.open(file);
	std::getline(ifs, date);
	try {
		while (1) {
			std::getline(ifs, date, ',');
			std::getline(ifs, currency, '\n');
			date_currency.insert(str_float(date, std::atof(currency.c_str())));
		}
	}
	catch (std::ios::failure &e) {
		if (!ifs.eof()) {
			throw e;
		}
	}
	return date_currency;
}