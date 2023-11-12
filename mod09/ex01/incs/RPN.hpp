#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#define ISOP(x) (x == '-' || x == '+' || x == '/' || x == '*')

class RPN {
	public :
		RPN(const char *);
		RPN(const RPN &);
		~RPN();

		RPN &operator=(const RPN &);
		void compute();
		int doOp(int, int, int);
		int getRes() const throw();

	public :
		class Error : public std::exception {
			public :
				Error();
				Error(std::string);
				~Error() throw();
				const char *what() const throw();
			private :
				std::string _what;
		};

	private :
		std::string _str;
		std::stack<int> _val;
		int _res;
};

#endif
