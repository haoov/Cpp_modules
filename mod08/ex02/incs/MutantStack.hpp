#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <iterator>
#include <cstddef>

template <typename T, typename Tp = std::vector<T> >
class MutantStack : public std::stack<T, Tp> {
	typedef typename std::stack<T, Tp>::container_type::iterator iterator;
	public :
		MutantStack();
		~MutantStack();
};

#endif //MUTANTSTACK_HPP