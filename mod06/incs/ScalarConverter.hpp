#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

typedef enum type {
	t_string,
	t_int,
	t_double,
}type;
class ScalarConverter {
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &);

		void convert(const std::string &str);
		type checkType() const;
		int getIntValue() const;
		double getDoubleValue() const;
		void printChar(std::ostream &) const;
		void printInt(std::ostream &) const;
		void printDouble(std::ostream &) const;
		void printFloat(std::ostream &) const;
	protected :

	private :
		std::string str;
		type type;
		int intValue;
		double doubleValue;
		int litteral;
		int error;
};

#define CHAROVERFLOW	0x01
#define INTOVERFLOW		0x02
#define FLOATOVERFLOW	0x04

#define PLUSINF			0x02
#define MINUSINF		0x04

std::ostream &operator<<(std::ostream &ost, const ScalarConverter &obj);

#endif