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
	_val = other._val;
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void RPN::compute() {
	std::string str;
	std::stringstream ss(_str);
	if (_str.empty())
		throw Error("no arguments");
	int index = 0;
	while (std::getline(ss, str, ' ')) {
		if (str.size() == 1 && ISOP(str[0])) {
			if (_val.size() < 2)
				throw Error();
			int n1 = _val.top(); _val.pop();
			int n2 = _val.top(); _val.pop();
			_val.push(doOp(n2, n1, str[0]));
		}
		else {
			for (size_t i = 0; i < str.size(); ++i) {
				if (i == 0 && str[i] == '-')
					continue;
				if (!::isdigit(str[i])) 
					throw Error("invalid argument: " + str);
			}
			_val.push(::atoi(str.c_str()));
		}
		++index;
	}
	if (index < 3 || (index % 2) == 0)
		throw Error();
	_res = _val.top();
}

int RPN::doOp(int n1, int n2, int op) {
	if (op == '+')
		return (n1 + n2);
	else if (op == '-')
		return (n1 - n2);
	else if (op == '*')
		return (n1 * n2);
	else {
		if (n2 == 0)
			throw Error("division by zero");
		return (n1 / n2);
	}
}

int RPN::getRes() const throw() {
	return _res;
}

/*------------------------------------*/
/*             Exceptions             */
/*------------------------------------*/

RPN::Error::Error() : _what("Error") {}

RPN::Error::Error(std::string what) : _what("Error: " + what) {}

RPN::Error::~Error() throw() {}

const char *RPN::Error::what() const throw() {
	return _what.c_str();
}