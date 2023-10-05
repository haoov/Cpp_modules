#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

typedef std::pair<std::string, float>	str_float;
typedef std::map<std::string, float>	str_float_map;

void analyseInput(const char *inputFile, str_float_map date_currency);

class BitcoinExchange {

	public :

		BitcoinExchange(const char);
		BitcoinExchange(const BitcoinExchange &);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &);

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
		class BadInput : public BitcoinExchange::Error {
			public :
				const char *what() const throw();
		};
		class NegativeNumber : public BitcoinExchange::Error {
			public :
				const char *what() const throw();
		};
		class TooLargeNumber : public BitcoinExchange::Error {
			public :
				const char *what() const throw();
		};
		class EmptyLine : public BitcoinExchange::Error {};
		class InvalidDate : public BitcoinExchange::Error {
			public :
				const char *what() const throw();
		};
		class EofReached : public BitcoinExchange::Error {
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