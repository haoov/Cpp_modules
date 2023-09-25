#include "ScalarConverter.hpp"
#include <limits>

/*------------------------------------*/
/*    Constructors and destrcutor     */
/*------------------------------------*/

ScalarConverter::ScalarConverter() {
	this->error = 0;
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

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

void ScalarConverter::convert(const std::string &str) {
	this->str = str;
	type type = this->checkType();
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
			if (this->doubleValue > (double) INT32_MAX || this->doubleValue < (double) INT32_MIN) {
				
			}
	}
}

type ScalarConverter::checkType() const {
	bool point = false, f;
	size_t len = this->str.length();
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
			else if (i == len - 1 && (!f || f && !point)) {
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