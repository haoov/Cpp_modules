#include "ScalarConverter.hpp"

/*------------------------------------*/
/*    Constructors and destrcutor     */
/*------------------------------------*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter::~ScalarConverter() {}

/*------------------------------------*/
/*       Overloading operators        */
/*------------------------------------*/

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {}

/*------------------------------------*/
/*               Methods              */
/*------------------------------------*/

void ScalarConverter::convert(const std::string &str) {
	this->str = str;
}

type ScalarConverter::checkType() const {
	bool point = false, f;
	size_t len = this->str.length();
	f = (this->str.at(len -1) == 'f');
	if (f && !ISNUM(this->str.at(len - 2))) {
		return (t_string);
	}
	int i, j = 0;
	if (this->str.at(j) == '+' || this->str.at(j) == '-') {
		++j;
	}
	for (i = j; i < len; ++i) {
		if (!ISNUM(this->str.at(i))) {
			if (i == j)
				return (t_string);
			else if (i == len - 1 && (!f || f && !point))
				return (t_string);
			else if (this->str.at(i) == '.') {
				if (!point)
					point = true;
				else
					return (t_string);
			}
		}
	}
	if (f)
		return (t_float);
	else if (point)
		return (t_double);
	else
		return (t_int);
}