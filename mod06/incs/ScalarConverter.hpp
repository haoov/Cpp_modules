#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &);

		void convert(const std::string &str);
		type checkType() const;
	protected :

	private :
		std::string str;
		char charValue;
		int intValue;
		double doubleValue;
		float floatValue;
		int error;
};

typedef enum type {
	t_string,
	t_int,
	t_double,
}type;

#define CHAROVERFLOW	0x01
#define INTOVERFLOW		0x02
#define FLOATOVERFLOW	0x04

std::ostream &operator<<(std::ostream &ost, const ScalarConverter &obj);

#endif