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
	int index = 0;
	while (std::getline(ss, str, ' ')) {
		s_arg sarg;
		sarg.op = false;
		size_t i = 0;
		switch (str.size()) {
			case 1 :
				if (	str[0] == '-' || str[0] == '+'
						|| str[0] == '*' || str[0] == '/')
					sarg.op = true;
				break;
			default :
				if (str[i] == '-')
					++i;
				for (; i < str.size(); ++i) {
					if (!::isdigit(str[i])) 
						throw Error("invalid argument");
				}
		}
		if (!sarg.op)
			sarg.val = ::atoi(str.c_str());
		else
			sarg.val = str[0];
		_args.push_back(sarg);
		if ((index == 1 || (index % 2)) && sarg.op)
			throw Error("invalid argument");
		else if (index > 1 && !(index % 2) && !sarg.op)
			throw Error("invalid argument");
		++index;
	}
	if (_args.size() < 3)
		throw Error("not enough arguments");
}

std::list<RPN::s_arg> RPN::getArgs() const {
	return _args;
}

int RPN::compute() {
	int n1, n2, op, i = 0;
	while (_args.size() != 0) {
		if (i == 0) {
			n1 = _args.front().val;
			_args.pop_front();
		}
		n2 = _args.front().val;
		_args.pop_front();
		op = _args.front().val;
		_args.pop_front();
		n1 = doOp(n1, n2, op);
		++i;
	}
	return n1;
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

RPN::Error::~Error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}

const char *RPN::Error::what() const throw() {
	return _what.c_str();
}