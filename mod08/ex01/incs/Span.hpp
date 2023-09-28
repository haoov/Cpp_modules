#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <algorithm>

class Span {
	public :
		Span(unsigned int);
		Span(const Span &);
		~Span();

		Span &operator=(const Span &);

		void addNumber(int);
		void insert(int, int);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		/*------------------------------------*/
		/*          Exception class           */
		/*------------------------------------*/
		class Full : public std::exception {
			public :
				const char *what() const throw();
		};
		class outOfRange : public std::exception {
			public :
				const char *what() const throw();
		};
	protected :

	private :
		unsigned int maxElems;
		std::list<int> elems;
};

#endif