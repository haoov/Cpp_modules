#ifndef SPAN_HPP
#define SPAN_HPP

typedef struct elem {
	int val;
	struct elem *next;
} elem;

class Span {
	public :
		Span(unsigned int);
		Span(const Span &);
		~Span();

		Span &operator=(const Span &);

		void addNumber(int);

		/*------------------------------------*/
		/*          Exception class           */
		/*------------------------------------*/
		class Full : public std::exception {
			public :
				const char *what() const throw();
		};
	protected :

	private :
		unsigned int maxElems;
		unsigned int nbElems;
		elem *elems;
		elem *last;
};

#endif