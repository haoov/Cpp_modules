#ifndef RPN_HPP
#define RPN_HPP

#include <vector>
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
		void compute();
		std::vector<s_arg> getArgs() const;

	public :
		class parserError : public std::exception {
			public :
				parserError(std::string);
				~parserError() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char *what() const throw();
			private :
				std::string _what;
		};

	private :
		std::string _str;
		std::vector<s_arg> _args;
};

#endif
