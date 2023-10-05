#include "Parser.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Parser::Parser(const char delim) {
	m_ifs.exceptions(m_ifs.failbit | m_ifs.badbit | m_ifs.eofbit);
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
	m_ifs.exceptions(m_ifs.failbit | m_ifs.badbit | m_ifs.eofbit);
	return (*this);
}

/*------------------------------------*/
/*           Public methods           */
/*------------------------------------*/

/**
 * @brief Function to parse a line from the current file opened by the parser 
 * the format must be "date delim value"
 * 
 * @param check boolean for advanced checking
 * @return a pair<string, float> constructed from the extracted data
 * @exception throws a EofReached exception if the eofbit is set
 * @exception throws a EmptyLine exception if the line is empty
 * @exception throws a BadInput exception if the format is incorrect
 * @exception throws a InvalidDate if the date does not exist
 * @exception throws a NegativeNumber exception if the value is less than 0
 * @exception throws a TooLargeNumber if the value is greater than 1000 
 * and the check flag is set
*/
str_float Parser::parseLine(bool check) {
	std::string line;

	//Handling the eof case apart from other io_base exceptions
	try {
		std::getline(m_ifs, line);
	}
	catch (std::ios_base::failure &e) {
		if (m_ifs.eof())
			throw Parser::EofReached();
		else
			throw e;
	}

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
	checkValue(sValue);

	//extracting the value to a float and further check if necessary
	float fValue = std::atof(sValue.c_str());
	if (fValue < 0)
		throw Parser::NegativeNumber();
	if (check && fValue > 1000)
		throw Parser::TooLargeNumber();

	return (str_float(date, fValue));
}

/**
 * @brief Function to parse a file corresponding to 
 * the format "date delim value"
 * 
 * @param file the file to parse
 * @return a map<string, float> containing the parsed data
*/
str_float_map Parser::parseFile(const char *file) {
	if (m_ifs.is_open()) {
		m_ifs.close();
		m_ifs.clear();
	}
	m_ifs.open(file);
	str_float_map map;
	std::string line;
	str_float data;

	//discard the first line
	std::getline(m_ifs, line);

	while (!m_ifs.eof()) {
		try {
			data = parseLine(false);
			map.insert(data);
		}
		catch (Parser::EmptyLine &empty) {
			//discard the line
		}
		catch (Parser::EofReached &e) {
			//do nothing
		}
	}
	m_ifs.clear();
	return (map);
}

/**
 * @brief Function to open a file and discard the first line
*/
void Parser::openFile(const char *file) {
	if (m_ifs.is_open()) {
		m_ifs.close();
		m_ifs.clear();
	}
	m_ifs.open(file);
	std::string line;
	std::getline(m_ifs, line);
}

bool Parser::eof() const {
	return (m_ifs.eof());
}

/*------------------------------------*/
/*          Private methods           */
/*------------------------------------*/

/**
 * @brief Function to check the format and the validity of a given date. 
 * The format must be "YYYY-MM-DD"
*/
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
		throw Parser::InvalidDate();
	}
}

/**
 * @brief Function to check wether a date exist in the range 1800-2100
*/
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
	if (month > 12)
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

/**
 * @brief Function to check if the value format is correct
 * 
 * @exception throws a BadInput exception if it's not
*/
void Parser::checkValue(std::string &sValue) const {
	size_t i = 0;
	if (sValue[i] == '-' || sValue[i] == '+')
		++i;
	for (size_t id = i; i < sValue.length(); ++i) {
		bool point = false;
		if (!std::isdigit(sValue[id])) {
			if (sValue[id] == '.' && !point)
				point = true;
			else
				throw Parser::BadInput();
		}
	}
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

const char *Parser::InvalidDate::what() const throw() {
	return ("invalid date");
}

const char *Parser::EofReached::what() const throw() {
	return ("end of file reached");
}