#include "RPN.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

RPN::RPN(std::string &arg) {
	parseArg(arg);
}

RPN::RPN(const RPN &other) {}

RPN::~RPN() {}

/*------------------------------------*/
/*              Operators             */
/*------------------------------------*/

RPN &RPN::operator=(const RPN &other) {
	m_val = other.m_val;
	return (*this);
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

void RPN::parseArg(std::string &arg) {
	size_t len = arg.length();
	for (size_t i = 0; i < len; ++i) {
		
	}
}