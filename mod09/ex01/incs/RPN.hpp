#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN {
	public :
		RPN();
		RPN(const RPN &);
		~RPN();

		RPN &operator=(const RPN &);

	protected :

	private :
		std::stack<double> m_val;
};

#endif