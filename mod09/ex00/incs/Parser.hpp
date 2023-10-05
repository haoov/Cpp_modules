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
		void openFile(const char *);
		bool eof() const;

		char getDelim() const;

		void setDelim(const char);

	public :

		/*------------------------------------*/
		/*            Exceptions              */
		/*------------------------------------*/

		class Error : public std::exception {};
		class BadInput : public Parser::Error {
			public :
				const char *what() const throw();
		};
		class NegativeNumber : public Parser::Error {
			public :
				const char *what() const throw();
		};
		class TooLargeNumber : public Parser::Error {
			public :
				const char *what() const throw();
		};
		class EmptyLine : public Parser::Error {};
		class InvalidDate : public Parser::Error {
			public :
				const char *what() const throw();
		};
		class EofReached : public Parser::Error {
			public :
				const char *what() const throw();
		};

	private :

		std::ifstream	m_ifs;
		char			m_delim;

		void checkValue(std::string &) const;
		void checkDate(std::string date) const;
		bool isValidDate(int, int, int) const;
};

#endif