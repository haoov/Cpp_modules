#include "Parser.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

Parser::Parser(const char delim) {
	m_ifs.exceptions(m_ifs.failbit | m_ifs.badbit | m_ifs.eofbit);
	m_delim = delim;
}

Parser::Parser(const Parser &other) {}

Parser::~Parser() {}

/*------------------------------------*/
/*             Operators              */
/*------------------------------------*/

Parser &Parser::operator=(const Parser &other) {}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

str_float Parser::parseLine(bool check) {
	std::string line;
	std::getline(m_ifs, line);
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	int pos = line.find(m_delim);
	if (pos == std::string::npos) {
		throw Parser::BadInput();
	}
	std::string date = line.substr(0, pos);
	std::string sValue = line.substr(pos + 1, line.length() - pos);
	for (size_t i = 0; i < date.length(); ++i) {
		if (i > 9) {
			throw Parser::BadInput();
		}
		switch (i) {
			case 0 ... 3 :
			case 5 ... 6 :
			case 8 ... 9 :
				if (!std::isdigit(date[i])) {
					throw Parser::BadInput();
				}
				break;
			case 4 :
			case 7 :
				if (date[i] != '-') {
					throw Parser::BadInput();
				}
				break;
			default :
				break;
		}
	}
	for (size_t i = 0; i < sValue.length(); ++i) {
		bool point = false;
		if (!std::isdigit(sValue[i])) {
			if (sValue[i] == '.' && !point) {
				point = true;
			}
			else {
				throw Parser::BadInput();
			}
		}
	}
	float fValue = std::atof(sValue.c_str());
	if (fValue < 0) {
		throw Parser::NegativeNumber();
	}
	if (check && fValue > 1000) {
		throw Parser::TooLargeNumber();
	}
	return (str_float(date, fValue));
}

str_float_map Parser::parseFile(const char *file) {
	if (m_ifs.is_open()) {
		m_ifs.close();
	}
	m_ifs.open(file);
	str_float_map map;
	std::string line;
	std::getline(m_ifs, line);
	while (!m_ifs.eof()) {
		map.insert(parseLine(false));
	}
	return (map);
}

/*------------------------------------*/
/*              Getters               */
/*------------------------------------*/


const char Parser::getDelim() const {
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