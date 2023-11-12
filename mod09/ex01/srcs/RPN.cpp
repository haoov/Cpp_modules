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
	_op = other._op;
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void RPN::parseArg() {
	std::string str;
	std::stringstream ss(_str);
	while (std::getline(ss, str, ' ')) {
		bool op = false;
		size_t i = 0;
		switch (str.size()) {
			case 1 :
				if (	str[0] == '-' || str[0] == '+'
						|| str[0] == '*' || str[0] == '/')
					op = true;
				break;
			default :
				if (str[i] == '-')
					++i;
				for (; i < str.size(); ++i) {
					if (!::isdigit(str[i])) 
						throw Error("invalid argument: " + str);
				}
		}
		if (op)
			_op.push_back(str[0]);
		else
			_val.push_back(::atoi(str.c_str()));
	}
	if (_val.size() != (_op.size() + 1))
		throw Error("wrong number of arguments");
}

int RPN::compute() {
	int res = _val.front();
	_val.pop_front();
	while (_val.size() != 0) {
		res = doOp(res, _val.front(), _op.front());
		_val.pop_front();
		_op.pop_front();
	}
	return res;
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

/*------------------------------------*/
/*             Exceptions             */
/*------------------------------------*/

RPN::Error::Error(std::string what) : _what("Error: " + what) {}

RPN::Error::~Error() throw() {}

const char *RPN::Error::what() const throw() {
	return _what.c_str();
}