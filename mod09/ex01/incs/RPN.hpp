#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class RPN {
	public :
		typedef struct arg {
			int val;
			bool op;
		}s_arg;

	public :
		RPN(const char *);
		RPN(const RPN &);
		~RPN();

		RPN &operator=(const RPN &);
		void parseArg();
		int compute();
		int doOp(int, int, int);
		std::list<s_arg> getArgs() const;

	public :
		class Error : public std::exception {
			public :
				Error(std::string);
				~Error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char *what() const throw();
			private :
				std::string _what;
		};

	private :
		std::string _str;
		std::list<s_arg> _args;
};

#endif
