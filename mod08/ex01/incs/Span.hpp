#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	public :
		Span(unsigned int);
		Span(const Span &);
		~Span();

		Span &operator=(const Span &);

		void addNumber(int);
		void insert(int*, int*);
		int at(int) const;
		unsigned long shortestSpan() const;
		unsigned long longestSpan() const;
		unsigned int size() const;

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
		class noDistance : public std::exception {
			public :
				const char *what() const throw();
		};
	protected :

	private :
		unsigned int maxElems;
		std::vector<int> elems;
};

#endif