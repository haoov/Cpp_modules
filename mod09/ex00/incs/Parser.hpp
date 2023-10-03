#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

typedef std::pair<std::string, float>	str_float;
typedef std::map<std::string, float>	str_float_map;

class Parser {

	public :

		Parser(const char);
		Parser(const Parser &);
		~Parser();

		Parser &operator=(const Parser &);

		str_float_map parseFile(const char *);
		str_float parseLine(bool);

		const char getDelim() const;

		void setDelim(const char);

		class BadInput : public std::exception {
				const char *what() const throw();
		};
		class NegativeNumber : public std::exception {
			const char *chat() const throw();
		};
		class TooLargeNumber : public std::exception {
			const char *what() const throw();
		};

	protected :

	private :

		std::ifstream	m_ifs;
		char			m_delim;
};

#endif