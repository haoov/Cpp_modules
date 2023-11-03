#include "ScalarConverter.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

ScalarConverter::ScalarConverter(const char *str) {
	_str = str;
	_charVal = 0;
	_intVal = 0;
	_floatVal = 0;
	_doubleVal = 0;
	_overflow = 0;
	_infValues = 0;
	getType();
	checkOverflow();
	convert();
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter::~ScalarConverter() {}

/*------------------------------------*/
/*             Operators              */
/*------------------------------------*/

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	static_cast<void>(other);
	return *this;
}

std::ostream &operator<<(std::ostream &ost, const ScalarConverter &obj) {
	//printing char value
	ost << "char: ";
	if (obj.nan())
		ost << "impossible";
	else if (obj.charOverflow())
		ost << "overflow";
	else if (!obj.displayable())
		ost << "not displayable";
	else
		ost << obj.charValue();
	ost << std::endl;

	//printing int value
	ost << "int: ";
	if (obj.nan())
		ost << "impossible";
	else if (obj.intOverflow())
		ost << "overflow";
	else
		ost << obj.intValue();
	ost << std::endl;

	//printing float value
	ost << "float: ";
	if (obj.nan())
		ost << "nan";
	else if (obj.infValues() & ScalarConverter::_PINFF)
		ost << "+inf";
	else if (obj.infValues() & ScalarConverter::_MINFF)
		ost << "-inf";
	else {
		ost << obj.floatValue();
		if (	obj.floatValue() - _INT_CAST(obj.floatValue()) == 0
				&& obj.floatValue() < 1e6)
				ost << ".0";
	}
	ost << "f";
	ost << std::endl;

	//printing double value
	ost << "double: ";
	if (obj.nan())
		ost << "nan";
	else if (obj.infValues() & ScalarConverter::_PINF)
		ost << "+inf";
	else if (obj.infValues() & ScalarConverter::_MINF)
		ost << "-inf";
	else {
		ost << obj.doubleValue();
		if (	obj.doubleValue() - _INT_CAST(obj.doubleValue()) == 0
				&& obj.doubleValue() < 1e6)
				ost << ".0";
	}
	return ost;
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void ScalarConverter::getType() {
	size_t i = 0;
	bool point = false, string = false;
	bool f = (_str[_str.length() - 1] == 'f');
	if (_str[i] == '+' || _str[i] == '-')
		++i;
	while (i < _str.length() && !string) {
		if (_str[i] == '.') {
			if (!point)
				point = true;
			else
				string = true;
		}
		if (i == 0 && !::isdigit(_str[i]))
			string = true;
		if (i == _str.length() - 2 && !::isdigit(_str[i]) && f)
			string = true;
		if (i == _str.length() - 1 && !::isdigit(_str[i]) && !f)
			string = true;
		++i;
	}
	if (string || _str.empty())
		_type = _NAN;
	else {
		if (point || f)
			_type = _DOUBLE;
		else
			_type = _INT;
	}
}

void ScalarConverter::checkOverflow() {
	if (_type != _NAN) {
		_doubleVal = ::strtod(_str.c_str(), NULL);
		_floatVal = ::strtof(_str.c_str(), NULL);
	}
	if (_doubleVal > _DOUBLE_CAST(_CHAR_MAX) || _doubleVal < _DOUBLE_CAST(_CHAR_MIN))
		_overflow |= _CHAROVERFLOW;
	if (_doubleVal > _DOUBLE_CAST(_INT_MAX) || _doubleVal < _DOUBLE_CAST(_INT_MIN))
		_overflow |= _INTOVERFLOW;
	if (errno == ERANGE) {
		if (_doubleVal == HUGE_VAL)
			_infValues |= _PINF;
		if (_doubleVal == -HUGE_VAL)
			_infValues |= _MINF;
		if (_floatVal == HUGE_VAL)
			_infValues |= _PINFF;
		if (_floatVal == -HUGE_VAL)
			_infValues |= _MINFF;
	}
}

void ScalarConverter::convert() {
	_charVal = _CHAR_CAST(_doubleVal);
	_intVal = _INT_CAST(_doubleVal);
	_floatVal = _FLOAT_CAST(_doubleVal);
}

bool ScalarConverter::charOverflow() const {
	return (_overflow & _CHAROVERFLOW);
}

bool ScalarConverter::intOverflow() const {
	return (_overflow & _INTOVERFLOW);
}

bool ScalarConverter::displayable() const {
	return ::isprint(_charVal);
}

bool ScalarConverter::nan() const {
	return (_type == _NAN);
}

char ScalarConverter::charValue() const {
	return _charVal;
}

int ScalarConverter::intValue() const {
	return _intVal;
}

float ScalarConverter::floatValue() const {
	return _floatVal;
}

double ScalarConverter::doubleValue() const {
	return _doubleVal;
}

int ScalarConverter::infValues() const {
	return _infValues;
}