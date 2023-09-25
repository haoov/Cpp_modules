#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <stdint.h>

/*------------------------------------*/
/*    Constructors and destrcutor     */
/*------------------------------------*/

ScalarConverter::ScalarConverter() {
	this->error = 0;
	this->litteral = 0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter::~ScalarConverter() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	static_cast<void> (other);
	return (*this);
}

std::ostream &operator<<(std::ostream &ost, const ScalarConverter &obj) {
	static_cast<void> (obj);
	return (ost);
}

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

void ScalarConverter::convert(const std::string &str) {
	this->str = str;
	this->type = this->checkType();
	switch (type) {
		case t_int :
			this->intValue = std::atoi(this->str.c_str());
			this->doubleValue = static_cast<double> (this->intValue);
			if (this->intValue > INT8_MAX || this->intValue < INT8_MIN) {
				this->error |= CHAROVERFLOW;
			}
			break;
		case t_double :
			this->doubleValue = std::atof(this->str.c_str());
			if (	this->doubleValue > (double) std::numeric_limits<float>::max()
			||		this->doubleValue < (double) std::numeric_limits<float>::min()) {
				this->error |= FLOATOVERFLOW;
			}
			if (this->doubleValue > (double)INT32_MAX || this->doubleValue < (double)INT32_MIN) {
				this->error |= INTOVERFLOW;
			}
			this->intValue = static_cast<int> (this->doubleValue);
			if (this->doubleValue > (double) INT8_MAX || this->doubleValue < (double) INT8_MIN) {
				this->error |= CHAROVERFLOW;
			}
		case t_string :
			if (this->str == "+inf" || this->str == "+inff") {
				this->litteral = PLUSINF;
			}
			else if (this->str == "-inf" || this->str == "-inff") {
				this->litteral = MINUSINF;
			}
		default :
			break;
	}
}

type ScalarConverter::checkType() const {
	bool point = false, f;
	int len = this->str.length();
	f = (this->str.at(len -1) == 'f');
	if (f && !std::isdigit(this->str.at(len - 2))) {
		return (t_string);
	}
	int i, j = 0;
	if (this->str.at(j) == '+' || this->str.at(j) == '-') {
		++j;
	}
	for (i = j; i < len; ++i) {
		if (!std::isdigit(this->str.at(i))) {
			if (i == j) {
				return (t_string);
			}
			else if (i == len - 1 && !f) {
				return (t_string);
			}
			else if (this->str.at(i) == '.') {
				if (!point)
					point = true;
				else
					return (t_string);
			}
		}
	}
	if (f || point) {
		return (t_double);
	}
	else {
		return (t_int);
	}
}

int ScalarConverter::getIntValue() const {
	return (this->intValue);
}

double ScalarConverter::getDoubleValue() const {
	return (this->doubleValue);
}

void ScalarConverter::printDouble(std::ostream &ost) const {
	ost << "double: ";
	switch (this->litteral) {
		case PLUSINF :
			ost << "+inf";
			break;
		case MINUSINF :
			ost << "-inf";
			break;
		default :
			if (this->type == t_string) {
				ost << "nan";
			}
			else {
				ost << this->doubleValue;
				if (this->doubleValue - static_cast<int> (this->doubleValue) == 0) {
					ost << ".0";
				}
			}
			break;
	}
	ost << std::endl;
}

void ScalarConverter::printFloat(std::ostream &ost) const {
	ost << "float: ";
	switch (this->litteral) {
		case PLUSINF :
			ost << "+inff";
			break;
		case MINUSINF :
			ost << "-inff";
			break;
		default :
			if (this->type == t_string) {
				ost << "nanf";
			}
			else if (this->error & FLOATOVERFLOW) {
				ost << "overflow";
			}
			else {
				ost << static_cast<float> (this->doubleValue);
				if (this->doubleValue - static_cast<int> (this->doubleValue) == 0) {
					ost << ".0";
				}
				ost << "f";
			}
			break;
	}
	ost << std::endl;
}

void ScalarConverter::printChar(std::ostream &ost) const {
	ost << "char: ";
	if (this->error & CHAROVERFLOW) {
		ost << "overflow";
	}
	else if (this->type == t_string) {
		ost << "impossible";
	}
	else if (!std::isprint(static_cast<char> (this->intValue))) {
		ost << "not displayable";
	}
	else {
		ost << static_cast<char> (this->intValue);
	}
	ost << std::endl;
}

void ScalarConverter::printInt(std::ostream &ost) const {
	ost << "int: ";
	if (this->error & INTOVERFLOW) {
		ost << "overflow";
	}
	else if (this->type == t_string) {
		ost << "impossible";
	}
	else {
		ost << this->intValue;
	}
	ost << std::endl;
}