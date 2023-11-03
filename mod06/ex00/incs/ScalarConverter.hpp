#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <errno.h>
#include <cstdlib>
#include <cmath>

#define _CHAR_MAX std::numeric_limits<char>::max()
#define _CHAR_MIN std::numeric_limits<char>::min()
#define _INT_MAX std::numeric_limits<int>::max()
#define _INT_MIN std::numeric_limits<int>::min()
#define  _FLOAT_MAX std::numeric_limits<float>::max()
#define  _FLOAT_MIN std::numeric_limits<float>::min()
#define _CHAR_CAST(x) (static_cast<char>(x))
#define _INT_CAST(x) (static_cast<int>(x))
#define _FLOAT_CAST(x) (static_cast<float>(x))
#define _DOUBLE_CAST(x) (static_cast<double>(x))

class ScalarConverter {
	public :
		typedef enum type {_NAN, _INT, _DOUBLE} e_type;
		typedef enum overflow {_CHAROVERFLOW = 0x1, _INTOVERFLOW = 0x2} e_overflow;
		typedef enum infValues {_PINF = 0x1, _PINFF = 0x2, _MINF = 0x4, _MINFF = 0x8} e_infValues;

	public :
		ScalarConverter(const char *);
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &);

		void getType();
		void checkOverflow();
		void convert();
		bool charOverflow() const;
		bool intOverflow() const;
		bool displayable() const;
		bool nan() const;
		char charValue() const;
		int intValue() const;
		float floatValue() const;
		double doubleValue() const;
		int infValues() const;

	private :
		std::string _str;
		e_type _type;
		int _overflow;
		int _infValues;
		char _charVal;
		int _intVal;
		float _floatVal;
		double _doubleVal;
};

std::ostream &operator<<(std::ostream &ost, const ScalarConverter &obj);

#endif