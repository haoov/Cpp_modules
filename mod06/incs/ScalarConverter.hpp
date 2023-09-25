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
};

typedef enum type {
	t_string,
	t_int,
	t_double,
	t_float
}type;

#define ISNUM(c) (c >= '0' && c <= '9')

#endif