#include "RPN.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

RPN::RPN(const char *args) {
	_str = args;
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::~RPN() {}

/*------------------------------------*/
/*              Operators             */
/*------------------------------------*/

RPN &RPN::operator=(const RPN &other) {
	_args = other._args;
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void RPN::parseArg() {
	std::string str;
	std::stringstream ss(_str);
	while (std::getline(ss, str, ' ')) {
		s_arg sarg;
		sarg.op = false;
		size_t i = 0;
		switch (str.size()) {
			case 1 :
				if (	str[0] == '-' || str[0] == '+'
						|| str[0] == '*' || str[0] == '/')
					sarg.op = true;
			default :
				if (str[i] == '-')
					++i;
				for (; i < str.size(); ++i) {
					if (!::isdigit(str[i]))
						throw parserError("Invalid argument");
				}
		}
		if (!sarg.op)
			sarg.val = ::atoi(str.c_str());
		else
			sarg.val = str[0];
		_args.push_back(sarg);
	}
}

std::vector<RPN::s_arg> RPN::getArgs() const {
	return _args;
}

/*------------------------------------*/
/*             Exceptions             */
/*------------------------------------*/

RPN::parserError::parserError(std::string what) : _what(what) {}

RPN::parserError::~parserError() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}

const char *RPN::parserError::what() const throw() {
	return _what.c_str();
}