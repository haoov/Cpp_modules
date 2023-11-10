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

//template <typename _C>
class PmergeMe {
	public :
		typedef std::pair<int, int> t_int_pair;
		typedef std::vector<t_int_pair> t_vec;
	public :
		PmergeMe(const char *);
		PmergeMe(const PmergeMe &);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &);

		void parseArg();
		void sort();
		void insert();
		int jacobsthal(int);
		std::vector<int> jacobsthalSequence();
		void insertValue(int);
		void binarySort(std::vector<int> &);
		size_t binarySearch(std::vector<int>, int, int, int);
		static bool highCompare(t_int_pair, t_int_pair);
		std::vector<int> getMain() const;
		void printMain();

	private :
		std::string _str;
		t_vec _v;
		std::vector<int> _c;
		std::vector<int> _main;
		std::vector<int> _pen;
		bool _odd;
		int _last;

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

#endif