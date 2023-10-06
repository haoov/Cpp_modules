#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN {
	public :
		RPN(std::string &);
		RPN(const RPN &);
		~RPN();

		RPN &operator=(const RPN &);
		void parseArg(std::string &);

	protected :

	private :
		std::stack<double> m_val;
};

#endif
