#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class RPN {
	public :
		typedef std::list<int> int_list_t;
		typedef int_list_t::iterator int_list_it_t;

	public :
		RPN(const char *);
		RPN(const RPN &);
		~RPN();

		RPN &operator=(const RPN &);
		void parseArg();
		int compute();
		int doOp(int, int, int);

	public :
		class Error : public std::exception {
			public :
				Error(std::string);
				~Error() throw();
				const char *what() const throw();
			private :
				std::string _what;
		};

	private :
		std::string _str;
		std::list<int> _val;
		std::list<char> _op;
};

#endif
