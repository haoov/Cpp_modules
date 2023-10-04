#include "Parser.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Parser::Parser(const char delim) {
	m_ifs.exceptions(std::iostream::failbit | std::iostream::badbit);
	m_delim = delim;
}

Parser::Parser(const Parser &other) {
	*this = other;
}

Parser::~Parser() {}

/*------------------------------------*/
/*             Operators              */
/*------------------------------------*/

Parser &Parser::operator=(const Parser &other) {
	m_delim = other.getDelim();
	m_ifs.exceptions(m_ifs.failbit | m_ifs.badbit);
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

/**
 * @brief Function to parse a line from the current file opened by the parser
 * 
 * 
 * @param check boolean for advanced checking
 * @return a pair<string, float> constructed from the extracted data
 * @exception throws a EmptyLine exception if the line is empty
 * @exception throws a BadInput exception if the format is incorrect
*/
str_float Parser::parseLine(bool check) {
	std::string line;
	std::getline(m_ifs, line);

	if (line.empty())
		throw Parser::EmptyLine();

	//this removes all the whitespaces fron the line
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

	size_t pos = line.find(m_delim);

	//if there is no delimiter the input is incorrect
	if (pos == std::string::npos)
		throw Parser::BadInput();

	//then we extract the date part and the value part to do further checks
	std::string date = line.substr(0, pos);
	std::string sValue = line.substr(pos + 1, line.length() - pos);
	checkDate(date);
	
	//check the value's format (must be an int or a float)
	for (size_t i = 0; i < sValue.length(); ++i) {
		bool point = false;
		if (!std::isdigit(sValue[i])) {
			if (sValue[i] == '.' && !point)
				point = true;
			else
				throw Parser::BadInput();
		}
	}

	//extracting the value to a float and further check if necessary
	float fValue = std::atof(sValue.c_str());
	if (fValue < 0)
		throw Parser::NegativeNumber();
	if (check && fValue > 1000)
		throw Parser::TooLargeNumber();

	return (str_float(date, fValue));
}

str_float_map Parser::parseFile(const char *file) {
	if (m_ifs.is_open())
		m_ifs.close();
	m_ifs.open(file);
	str_float_map map;
	std::string line;
	std::getline(m_ifs, line);
	while (!m_ifs.eof()) {
		try {
			map.insert(parseLine(false));
		}
		catch (Parser::EmptyLine &empty) {
			//discard the line
		}
		catch (std::ios_base::failure &fail) {
			if (!m_ifs.eof()) {
				throw fail;
			}
		}
	}
	m_ifs.clear();
	return (map);
}

void Parser::checkDate(std::string date) const {

	if (date.length() > 10) {
		throw Parser::BadInput();
	}
	for (size_t i = 0; i < 10; ++i) {
		if (!std::isdigit(date[i])) {
			if (i != 4 && i != 7) {
				throw Parser::BadInput();
			}
			else if (date[i] != '-') {
				throw Parser::BadInput();
			}
		}
	}
	std::string syear = date.substr(0, 4);
	std::string smonth = date.substr(5, 2);
	std::string sday = date.substr(8, 2);
	int year = std::atoi(syear.c_str());
	int month = std::atoi(smonth.c_str());
	int day = std::atoi(sday.c_str());
	if (!isValidDate(year, month, day)) {
		throw Parser::BadInput();
	}
}

bool Parser::isValidDate(int year, int month, int day) const {
	bool leapYear = false;
	if (year % 4) {
		if (year % 100) {
			if (year % 400)
				leapYear = true;
			else
				leapYear = false;
		}
		else {
			leapYear = true;
		}
	}
	else {
		leapYear = false;
	}
	if (year < 1800 || year > 2100)
		return (false);
	if (day < 1)
		return (false);
	switch (month) {
		case 2 :
			if (leapYear && day > 29)
				return (false);
			else if (day > 28)
				return (false);
			break;
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10 :
		case 12 :
			if (day > 31)
				return (false);
			break;
		case 4 :
		case 6 :
		case 9 :
		case 11 :
			if (day > 30)
				return (false);
			break;
		default : break;
	}
	return (true);
}

/*------------------------------------*/
/*              Getters               */
/*------------------------------------*/


char Parser::getDelim() const {
	return (m_delim);
}

/*------------------------------------*/
/*              Setters               */
/*------------------------------------*/

void Parser::setDelim(const char delim) {
	m_delim = delim;
}

/*------------------------------------*/
/*             Exceptions             */
/*------------------------------------*/

const char *Parser::BadInput::what() const throw() {
	return ("bad input");
}

const char *Parser::NegativeNumber::what() const throw() {
	return ("negative number");
}

const char *Parser::TooLargeNumber::what() const throw() {
	return ("too large a number");
}