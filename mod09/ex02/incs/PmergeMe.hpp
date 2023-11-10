#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>

//template <typename _C>
class PmergeMe {
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
		std::vector<int> getMain() const;

	private :
		std::string _str;
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