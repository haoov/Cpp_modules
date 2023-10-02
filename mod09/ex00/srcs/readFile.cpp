#include <iostream>
#include "../incs/btc.hpp"
#include <cstdlib>
#include <limits>
#include <algorithm>

str_float_map readFile(const char *file, char delim) {
	std::ifstream ifs;
	str_float_map date_currency;
	ifs.exceptions(ifs.badbit | ifs.failbit | ifs.eofbit);
	ifs.open(file);
	try {
		std::string line;
		std::getline(ifs, line);
		while (!ifs.eof()) {
			std::getline(ifs, line, '\n');
			line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
			int pos = line.find(delim);
			errnum error;
			if (pos == std::string::npos) {
				error = badInput;
			}
			else {
				std::string date = line.substr(0, pos);
				std::string sValue = line.substr(pos + 1, line.length() - pos);
				float fValue = std::atof(sValue.c_str());
			}

		}
	}
	catch (std::ios::failure &failException) {
		if (!ifs.eof()) {
			throw failException;
		}
	}
	return date_currency;
}

int extractData(std::string line, char delim, str_float_map &date_value) {
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	int pos = line.find(delim);
	int error = 0;
	if (pos == std::string::npos) {
		error = badInput;
	}
	else {
		std::string date = line.substr(0, pos);
		std::string sValue = line.substr(pos + 1, line.length() - pos);
		error = checkDate(date);
		if (!error) {
			error = checkValue(sValue);
		}
		if (!error) {
			float fValue = std::atof(sValue.c_str());
		}
	}
}