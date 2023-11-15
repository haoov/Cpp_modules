#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <map>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <limits>

template <template <typename, typename> class C>
class PmergeMe {
	public :
		typedef typename C<int, std::allocator<int> >::iterator it_t;
		typedef std::pair<int, int> int_pair_t;
		typedef C<int_pair_t, std::allocator<int_pair_t> > int_pair_cont_t;
		typedef C<int, std::allocator<int> > int_cont_t;
		typedef typename int_pair_cont_t::iterator int_pair_cont_it_t;

	public :
		PmergeMe(const char *);
		PmergeMe(const PmergeMe &);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &);

		void parseArg();
		void sort();
		void insert();
		void printChain();
		double getTime() const throw();

	private :
		std::string _str;
		int_cont_t _c;
		int_pair_cont_t _pair;
		int_cont_t _main;
		bool _odd;
		int _last;
		double _time;

	public :
		class Error : public std::exception {
			public :
				Error(std::string);
				~Error() throw();
				const char *what() const throw();
			private :
				std::string _what;
		};
};

template <typename T, template <typename, typename> class C>
typename C<T, std::allocator<T> >::iterator binarySearch(C<T, std::allocator<T> > &cont, size_t start, size_t end, T key, bool (*comp)(T, T));

template <typename T, template <typename, typename> class C>
C<T, std::allocator<T> > binarySort(C<T, std::allocator<T> > &cont, bool (*comp)(T, T));

bool highCompare(std::pair<int, int> p1, std::pair<int, int> p2);
bool compare(int a, int b);
size_t jacobsthal(int n);

#endif